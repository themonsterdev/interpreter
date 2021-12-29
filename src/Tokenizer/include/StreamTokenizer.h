#ifndef STREAM_TOKENIZER_H
#define STREAM_TOKENIZER_H

#include "AbstractTokenizer.h"

#include <fstream>  // std::ifstream

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

    // Tokenizer
    virtual bool HasNext();
    virtual Token GetNext();

private:

    ifstream m_sfs;
};

#endif
