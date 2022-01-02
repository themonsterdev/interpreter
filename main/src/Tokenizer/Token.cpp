#include "Tokenizer/Token.h"

Token::Token()
	: m_iType('\0')
	, m_wsValue("")
	, m_lValue(0)
{}

Token::Token(string ws, Type type)
	: m_iType((int)type)
	, m_wsValue(ws)
	, m_lValue(0)
{}

Token::Token(const long d, Type type)
	: m_iType((int)type)
	, m_wsValue("")
	, m_lValue(d)
{}

Token::Token(const char c)
	: m_iType((int)c)
	, m_wsValue("")
	, m_lValue(0)
{}

bool Token::HasType(int type)
{
	return (int)m_iType == type;
}

int	Token::GetType()
{
	return m_iType;
}

char Token::GetCharValue()
{
	return static_cast<char>(GetType());
}

string Token::GetWordValue()
{
	return m_wsValue;
}

long Token::GetNumberValue()
{
	return m_lValue;
}
