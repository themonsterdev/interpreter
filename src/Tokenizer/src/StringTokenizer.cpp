#include "StringTokenizer.h"

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

	return StringTokenizer::IsDelim(m_cCurrentChar)
		? HasNext()
		: true;
}

Token StringTokenizer::GetNext()
{
	if (m_cCurrentChar == '\0')
	{
		throw exception();
	}

	Token token;
	token.word += m_cCurrentChar;

	if (StringTokenizer::IsWord(m_cCurrentChar))
	{
		while (m_sCurrentIndex < m_swCharacters.length())
		{
			m_cCurrentChar = m_swCharacters[m_sCurrentIndex++];

			if (!StringTokenizer::IsWord(m_cCurrentChar) && !StringTokenizer::IsNumber(m_cCurrentChar))
			{
				break;
			}

			token.word += m_cCurrentChar;
		}

		token.type = (int)Token::Type::TT_WORD;
	}
	else if (StringTokenizer::IsNumber(m_cCurrentChar))
	{
		while (m_sCurrentIndex < m_swCharacters.length())
		{
			m_cCurrentChar = m_swCharacters[m_sCurrentIndex++];

			if (!StringTokenizer::IsNumber(m_cCurrentChar))
			{
				break;
			}

			token.word += m_cCurrentChar;
		}

		token.type		= (int)Token::Type::TT_NUMBER;
		token.number	= stod(token.word);
		token.word		= "";
	}
	else
	{
		token.type		= (int)m_cCurrentChar;
		token.character = m_cCurrentChar;
		token.word		= "";
	}

	m_cCurrentChar = '\0';

	return token;
}
