#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>

#include "token.h"

using namespace std;

class Tokenizer {
public:

    vector<Token> getTokens( const char* characters );

    Token getWordToken( const char character, int *i );

private:

    vector<Token> m_tokens;
};


#endif
