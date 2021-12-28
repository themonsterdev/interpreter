#ifndef STREAM_TOKENIZER_H
#define STREAM_TOKENIZER_H

#include "Token.h"

#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <vector>

using namespace std;

/**
 * Classe StreamTokenizer
 */
class StreamTokenizer
{
public:

    /**
    * Type d'énumération de jeton.
    */
    enum class TokenType : int
    {
        TT_WORD     = -4,  /**< Le type de jeton TT_WORD est un mot. */
        TT_NUMBER   = -3,  /**< Le type de jeton TT_NUMBER est un nombre. */
        TT_EOL      = -2,  /**< Le type de jeton TT_EOL est une fin de ligne. */
        TT_EOF      = -1   /**< Le type de jeton TT_EOF est la fin du flux. */
    };

    /**
     * Construit un tokenizer de chaîne pour la chaîne spécifiée.
     */
    StreamTokenizer(string filename);
    StreamTokenizer(string filename, string delim);
    StreamTokenizer(string filename, string delim, bool returnDelims);

    void WordChars(char low, char high);

    /**
     * Calcule le nombre de fois que la méthode nextToken de ce tokenizer peut être appelée avant de générer une exception.
     * 
     * @return int
     */
    int CountTokens();

    /**
     * Teste s'il y a plus de tokens disponibles dans la chaîne de ce tokenizer.
     * 
     * @return bool
     */
    bool HasMoreTokens();

    /**
     * Analyse le jeton suivant à partir du flux d'entrée de ce tokenizer.
     * 
     * @return int
     */
    int GetNextToken();

    /**
     * Si le jeton actuel est un nombre, ce champ contient la valeur de ce nombre.
     * Le jeton actuel est un nombre lorsque la valeur du champ ttype est TT_NUMBER.
     *
     * @return double
     */
    double GetNumberToken();

    /**
     * Si le jeton actuel est un jeton de type mot, ce champ contient une chaîne donnant les caractères du jeton de type mot.
     * Si le jeton actuel est un jeton de chaîne entre guillemets, ce champ contient le corps de la chaîne.
     * 
     * Le jeton actuel est un mot lorsque la valeur du champ ttype est TT_WORD. Le jeton actuel est un jeton de chaîne entre
     * guillemets lorsque la valeur du champ ttype est un caractère entre guillemets.
     *
     * @return string
     */
    string GetStringToken();

private:

    ifstream m_is;
    string m_delim;
    bool m_returnDelims;
    int m_tokenCount;

    char m_currentCharacter;
    vector<vector<char>> m_vWordChars;

    double m_numberToken;
    string m_strToken;

    bool m_isStr;
    bool m_isNumber;

    void OpenFile(string filename);
    int GetStringLiteralToken();
    bool IsDelimToken();
};

#endif
