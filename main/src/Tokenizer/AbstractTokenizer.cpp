#include "Tokenizer/AbstractTokenizer.h"

bool AbstractTokenizer::IsDelim(const char character)
{
	return character == ' '
		|| character == '\n'
		|| character == '\0';
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

bool AbstractTokenizer::HasNext()
{
	return AbstractTokenizer::IsDelim(m_cCurrentChar) ? HasNext() : true;
}

Token AbstractTokenizer::GetNext()
{
	if (m_cCurrentChar == '\0')
	{
		throw exception("AbstractTokenizer::GetNext");
	}

	return Token('\0');
}

void AbstractTokenizer::Keywords(list<string> keywords)
{
	m_keywords = keywords;
}

bool AbstractTokenizer::IsKeyword(string wsValue)
{
	bool isKeyword = false;
	list<string>::iterator end = m_keywords.end();

	for (list<string>::iterator begin = m_keywords.begin(); begin != end; begin++)
	{
		if (wsValue == *begin)
		{
			isKeyword = true;
			break;
		}
	}

	return isKeyword;
}
