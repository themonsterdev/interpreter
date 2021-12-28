#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"

using namespace std;

/**
 * Classe Tokenizer
 * 
 * Cette classe fais une analyse lexical sur une chaine de caractères données.
 * 
 * @see https://fr.wikipedia.org/wiki/Analyse_lexicale
 */
class Tokenizer
{
public:

    /**
     * Imprime les tokens générer
     *
     * @return void
     */
    static void PrintTokens(Token::List tokens);

    /**
     * Constructeur Tokenizer
     * 
     * @param characters les caractère d'entrée du program/script
     */
    Tokenizer( string characters );

    /**
     * Récupèrer les tokens de la chaine de characters.
     * 
     * @return vector<Token> les tokens générer
     */
    Token::List GetTokens();

private:

    Token GetWordToken( int& i );
    string GetStringLiteralToken(string& characters, int& i);

    Token GetNumberToken( int& i );
    string GetNumberLiteralToken(string& characters, int& i);

    Token GetOperatorToken( const char character );

    string m_characters;
};

#endif
