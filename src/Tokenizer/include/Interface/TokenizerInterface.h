#ifndef TOKENIZER_INTERFACE_H
#define TOKENIZER_INTERFACE_H

#include "Token.h"
#include <string> // std::string

using namespace std;

/**
 * Classe Tokenizer
 * 
 * Cette classe fais une analyse lexical sur une chaine de caractères données.
 * 
 * @see https://fr.wikipedia.org/wiki/Analyse_lexicale
 * @see https://en.wikipedia.org/wiki/Iterator_pattern
 */
class TokenizerInterface
{
public:

	~TokenizerInterface() = default;

	virtual bool HasNext() = 0;
	virtual Token GetNext() = 0;
};

#endif
