#include "Tokenizer/StringTokenizer.h"

StringTokenizer::StringTokenizer(string str)
	: ::AbstractTokenizer()
	, m_swCharacters(str)
	, m_sCurrentIndex(0)
{}

bool StringTokenizer::HasNext()
{
	if (m_sCurrentIndex == m_swCharacters.length())
	{
		return false;
	}

	m_cCurrentChar = m_swCharacters[m_sCurrentIndex++];

	return __super::HasNext();
}

Token StringTokenizer::GetNext()
{
	Token token = __super::GetNext();

	string wsValue;
	wsValue += m_cCurrentChar;

	if (StringTokenizer::IsWord(m_cCurrentChar))
	{
		while (m_sCurrentIndex < m_swCharacters.length())
		{
			m_cCurrentChar = m_swCharacters[m_sCurrentIndex++];

			if (!StringTokenizer::IsWord(m_cCurrentChar) && !StringTokenizer::IsNumber(m_cCurrentChar)) break;

			wsValue += m_cCurrentChar;
		}

		bool isKeyword = IsKeyword(wsValue);
		token = Token(wsValue, isKeyword ? Token::Type::KEYWORD : Token::Type::IDENTIFIER);
	}
	else if (StringTokenizer::IsNumber(m_cCurrentChar))
	{
		while (m_sCurrentIndex < m_swCharacters.length())
		{
			m_cCurrentChar = m_swCharacters[m_sCurrentIndex++];

			if (!StringTokenizer::IsNumber(m_cCurrentChar)) break;

			wsValue += m_cCurrentChar;
		}

		token = Token(stol(wsValue));
	}
	else
	{
		token = Token(m_cCurrentChar);
	}

	m_cCurrentChar = '\0';

	return token;
}
