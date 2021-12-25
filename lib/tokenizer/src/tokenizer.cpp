#include <iostream>
#include <exception>

#include "Tokenizer.h"

// Static functions private

bool IsIgnore( char character )
{
    return character == '\t'    // Horizontal Tab
        || character == '\n'    // Line Feed
        || character == '\r'    // Carriage Return
        || character == ' ';    // Space
}

bool IsUnderscore( char character )
{
    return character == '_';
}

bool IsLetter( char character )
{
    return character >= 'A' && character <= 'Z'
        || character >= 'a' && character <= 'z';
}

bool IsWord( char character )
{
    return IsUnderscore( character ) || IsLetter( character );
}

bool IsNumber( char character )
{
    return character >= '0' && character <= '9';
}

bool IsOperator( char character )
{
    return character == '!'
        || character == '*'
        || character == '+'
        || character == '-'
        || character == '/'
        || character == '<'
        || character == '='
        || character == '>'
        || character == '&'
        || character == '%';
}

// Definitions des fonctions de la classe Tokenizer

void Tokenizer::PrintTokens(TokenList tokens)
{
    for (
        TokenList::iterator it = tokens.begin();
        it != tokens.end();
        ++it
        ) {
        cout << "Token {" << endl;
        cout << '\t' << "type: " << Token::GetStringType(it->GetType()) << "," << endl;
        cout << '\t' << "data: " << it->GetData() << endl;
        cout << "}" << endl;
    }
}

Tokenizer::Tokenizer( string characters )
    : m_characters( characters )
{}

TokenList Tokenizer::GetTokens()
{
    TokenList tokens;

    size_t charactersLength = this->m_characters.size();
    char character;
    Token token;
    

    int numberAtCharacter = 0;
    int numberLine = 1;

    for (
        int i = 0;              // Commence à zéro.
        i < charactersLength;   // Arètte losque on arrive à la fin de la chaine de caractère.
        i++                     // Incrémente de un à chaque boucle.
    ) {
        character = this->m_characters[ i ];

        // Si le caractère actuelle n'est pas ignorer
        if ( !IsIgnore( character ) )
        {
            if ( IsWord( character ) )
            {
                token = this->GetWordToken( i );
            }
            else if ( IsNumber( character ) )
            {
                token = this->GetNumberToken( i );
            }
            else if ( IsOperator( character ) )
            {
                token = this->GetOperatorToken(character);
            }
            else
            {
                string errorMessage = string("Jeton `") + character + "` inattendu.";
                errorMessage += "\nÀ la ligne au caractère: " + to_string(numberLine) + ":" + to_string(numberAtCharacter);
                throw exception(errorMessage.c_str());
            }

            numberAtCharacter += static_cast<int>(token.GetData().size());
            token.SetNumberAtCharacter(numberAtCharacter);
            token.SetNumberLine(numberLine);
            tokens.push_back(token);
        }
        else if (character == '\n')
        {
            numberAtCharacter = 0;
            numberLine++;
        }
        else
        {
            numberAtCharacter++;
        }
    }

    return tokens;
}

Token Tokenizer::GetWordToken( int& i )
{
    string characters;
    GetStringLiteralToken(characters, i);
    Token token( Token::Type::Identifier );

    if ( characters == "var" || characters == "print" )
    {
        token.SetType(Token::Type::Keyword);
    }

    token.SetData(characters);
    return token;
}

string Tokenizer::GetStringLiteralToken(string &characters, int& i)
{
    characters += this->m_characters[ i ];

    if ( i < this->m_characters.size() )
    {
        const char nextCharacter = this->m_characters[ i + 1 ];
        if ( IsWord( nextCharacter ) || IsNumber( nextCharacter ) )
        {
            i++;
            return GetStringLiteralToken( characters, i );
        }
    }

    return characters;
}

Token Tokenizer::GetNumberToken(int& i)
{
    string characters;
    GetNumberLiteralToken(characters, i);
    Token token(Token::Type::Number);
    token.SetData(characters);
    return token;
}

string Tokenizer::GetNumberLiteralToken(string& characters, int& i)
{
    characters += this->m_characters[i];

    if ( i < this->m_characters.size() )
    {
        const char nextCharacter = this->m_characters[i + 1];
        if ( IsNumber( nextCharacter ) )
        {
            i++;
            return GetStringLiteralToken( characters, i );
        }
    }

    return characters;
}


Token Tokenizer::GetOperatorToken(const char character)
{
    Token token(Token::Type::Operator);
    token.SetData(character);
    return token;
}
