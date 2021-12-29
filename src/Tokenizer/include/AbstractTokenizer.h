#ifndef ABSTRACT_TOKENIZER_H
#define ABSTRACT_TOKENIZER_H

#include "Interface/TokenizerInterface.h"

class AbstractTokenizer : public TokenizerInterface
{
protected:

	static bool IsDelim(const char character);
	static bool IsWord(const char character);
	static bool IsNumber(const char character);

public:

	AbstractTokenizer();
	virtual ~AbstractTokenizer() = default;

protected:

	char m_cCurrentChar;
};

#endif
