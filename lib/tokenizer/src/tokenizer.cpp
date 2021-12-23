#include <iostream>
#include <exception>

#include "Tokenizer.h"

// Static functions private

bool isIgnore( char character )
{
    return character == '\t'    // Horizontal Tab
        || character == '\n'    // Line Feed
        || character == '\r'    // Carriage Return
        || character == ' ';    // Space
}

bool isUnderscore( char character )
{
    return character == '_';
}

bool isLetter( char character )
{
    return character >= 'A' && character <= 'Z'
        || character >= 'a' && character <= 'z';
}

bool isWord( char character )
{
    return isUnderscore( character ) || isLetter( character );
}

bool isNumber( char character )
{
    return character >= '0' && character <= '9';
}

bool isOperator( char character )
{
    return character == '*'
        || character == '+'
        || character == '-'
        || character == '/'
        || character == '<'
        || character == '='
        || character == '>'
        || character == '^'
        || character == '%';
}

class LexicalSyntaxError : public exception
{
public:
    LexicalSyntaxError(const string& err) throw()
        : m_Err(err)
    {}

    virtual ~LexicalSyntaxError() throw()
    {}

    virtual const char* what() const throw()
    {
        return m_Err.c_str();
    }
private:
    string m_Err;

};

// Definitions des fonctions de la classe Tokenizer

void Tokenizer::printTokens(TokenList tokens)
{
    for (
        TokenList::iterator it = tokens.begin();
        it != tokens.end();
        ++it
        ) {
        cout << "Token {" << endl;
        cout << '\t' << "type: " << Token::getStringType(it->getType()) << "," << endl;
        cout << '\t' << "data: " << it->getData() << endl;
        cout << "}" << endl;
    }
}

Tokenizer::Tokenizer( string characters )
    : m_characters( characters )
{}

TokenList Tokenizer::getTokens()
{
    TokenList tokens;

    size_t charactersLength = this->m_characters.size();
    char character;
    Token token;

    for (
        int i = 0;              // Commence à zéro.
        i < charactersLength;   // Arètte losque on arrive à la fin de la chaine de caractère.
        i++                     // Incrémente de un à chaque boucle.
    ) {
        character = this->m_characters[ i ];

        // Si le caractère actuelle ne doit n'est pas ignorer
        if ( !isIgnore( character ) )
        {
            if ( isWord( character ) )
            {
                token = this->getWordToken( i );
            }
            else if ( isNumber( character ) )
            {
                token = this->getNumberToken( i );
            }
            else if ( isOperator( character ) )
            {
                token = this->getOperatorToken(character);
            }
            else
            {
                throw LexicalSyntaxError(
                    string("Unexpected token: ") + character
                );
            }

            tokens.push_back( token );
        }
    }

    return tokens;
}

Token Tokenizer::getWordToken( int& i )
{
    string characters;
    getStringLiteralToken(characters, i);
    Token token( Token::Type::Identifier );

    if ( characters == "var" || characters == "print" )
    {
        token.setType(Token::Type::Keyword);
    }

    token.setData(characters);
    return token;
}

string Tokenizer::getStringLiteralToken(string &characters, int& i)
{
    characters += this->m_characters[ i ];

    if ( i < this->m_characters.size() )
    {
        const char nextCharacter = this->m_characters[ i + 1 ];
        if ( isWord( nextCharacter ) )
        {
            i++;
            return getStringLiteralToken(characters, i);
        }
    }

    return characters;
}

Token Tokenizer::getNumberToken(int& i)
{
    string characters;
    getNumberLiteralToken(characters, i);
    Token token(Token::Type::Number);
    token.setData(characters);
    return token;
}

string Tokenizer::getNumberLiteralToken(string& characters, int& i)
{
    characters += this->m_characters[i];

    if (i < this->m_characters.size())
    {
        const char nextCharacter = this->m_characters[i + 1];
        if (isNumber(nextCharacter))
        {
            i++;
            return getStringLiteralToken(characters, i);
        }
    }

    return characters;
}


Token Tokenizer::getOperatorToken(const char character)
{
    Token token(Token::Type::Operator);
    token.setData(character);
    return token;
}
