#include <iostream>

#include "tokenizer.h"

bool isIgnore( char character ) {
    return ( character == ' ' || character == '\n' );
}

bool isUnderscore( char character ) {
    return character == '_';
}

bool isLetter( char character ) {
    return ( character >= 'A' && character <= 'Z' )
        || ( character >= 'a' && character <= 'z' );
}

bool isWord( char character ) {
    return isUnderscore( character ) || isLetter( character );
}

bool isNumber( char character ) {
    return ( character >= '0' && character <= '9' );
}

bool isOperator( char character ) {
    return ( character == '=' || character == '+' );
}

vector<Token> Tokenizer::getTokens( const char* characters ) {
    size_t length = strlen( characters );
    Token token( Token::Unknown );
    char character;

    for ( int i = 0; i < length; i++ ) {
        character = characters[ i ];

        if ( isIgnore( character ) )
            continue;

        if ( isWord( character ) )
            token = getWordToken( character, &i );
        else if ( isNumber( character ) ) {
            cout << "isNumber" << endl;
        }
        else if ( isOperator( character ) ) {
            cout << "isOperator" << endl;
        }
        else {
            char* prefix = "Unexpected token: ";
            size_t l = strlen( prefix );
            char* errorStr = new char[ l ];

            for ( int j = 0; j < l; j++ )
                errorStr[ j ] = prefix[ j ];
            errorStr[ l ] = character;
            errorStr[ l + 1 ] = '\0';

            throw exception( errorStr );
        }

        m_tokens.push_back( token );
    }

    return m_tokens;
}

Token Tokenizer::getWordToken( const char character, int *i ) {
    cout << "isWord" << endl;
    Token token( Token::Identifier );
    return token;
}
