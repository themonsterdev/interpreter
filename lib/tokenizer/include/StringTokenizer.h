#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include <string>   // std::string

using namespace std;

class StringTokenizer
{
public:

    /**
     * Construit un tokenizer de chaîne pour la chaîne spécifiée.
     */
    StringTokenizer(string str);
    StringTokenizer(string str, string delim);
    StringTokenizer(string str, string delim, bool returnDelims);

    /**
     * Calcule le nombre de fois que la méthode nextToken de ce tokenizer peut être appelée avant de générer une exception.
     */
    int CountTokens();

    /**
     * Teste s'il y a plus de tokens disponibles dans la chaîne de ce tokenizer.
     */
    bool HasMoreTokens();

    /**
     * Retourne le prochain token de ce tokenizer de chaîne.
     */
    string GetNextToken() noexcept(false);

private:

    string m_str;
    string m_delim;
    bool m_returnDelims;
    int m_tokenCount;

    string::iterator m_itBegin;
    string::iterator m_itEnd;

    string GetStringLiteralToken(string& characters);
    bool IsIgnoredToken();
};

#endif
