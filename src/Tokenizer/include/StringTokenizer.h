#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include "AbstractTokenizer.h"

class StringTokenizer : public AbstractTokenizer
{
public:

    /**
     * Construit un tokenizer de chaîne pour la chaîne spécifiée.
     */
    StringTokenizer(string str);

    // Tokenizer
    virtual bool HasNext();
    virtual Token GetNext();

private:

    string m_swCharacters;
    size_t m_sCurrentIndex;
};

#endif
