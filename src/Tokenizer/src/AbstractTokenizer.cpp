#include "AbstractTokenizer.h"

bool AbstractTokenizer::IsDelim(const char character)
{
	return character == ' '
		|| character == '\n';
}

bool AbstractTokenizer::IsWord(const char character)
{
	return character >= 'a' && character <= 'z'
		|| character >= 'A' && character <= 'Z'
		|| character == '_';
}

bool AbstractTokenizer::IsNumber(const char character)
{
	return character >= '0' && character <= '9';
}

AbstractTokenizer::AbstractTokenizer()
	: m_cCurrentChar('\0')
{}
