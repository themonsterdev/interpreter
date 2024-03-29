#ifndef STREAM_TOKENIZER_H
#define STREAM_TOKENIZER_H

#include "AbstractTokenizer.h"

/**
 * Classe StreamTokenizer
 */
class StreamTokenizer : public AbstractTokenizer
{
public:

    /**
     * Construit un tokenizer de chaîne pour la chaîne spécifiée.
     */
    StreamTokenizer(string filename);
    ~StreamTokenizer() {
        m_sfs.close();
    }

    // Tokenizer
    virtual bool HasNext();
    virtual Token GetNext();

private:

    ifstream m_sfs;
};

#endif
