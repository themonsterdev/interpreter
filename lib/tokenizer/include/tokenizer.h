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
    static void printTokens(TokenList tokens);

    /**
     * Constructeur Tokenizer
     * 
     * @param string les caractère d'entrée du program/script
     */
    Tokenizer( string characters );

    /**
     * Récupèrer les tokens de la chaine de characters.
     * 
     * @return vector<Token> les tokens générer
     */
    TokenList getTokens();

private:

    Token getWordToken( int& i );
    string getStringLiteralToken(string& characters, int& i);

    Token getNumberToken( int& i );
    string getNumberLiteralToken(string& characters, int& i);

    Token getOperatorToken( const char character );

    string m_characters;
};

#endif
