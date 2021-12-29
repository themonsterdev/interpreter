#include "StreamTokenizer.h"
#include "Token.h"

#include <iostream> // std::cout

StreamTokenizer::StreamTokenizer(string filename)
	: ::AbstractTokenizer()
{
	m_sfs.open(filename);

	if (!m_sfs.is_open())
	{
		throw exception((string("Impossible d'ouvrir le fichier ") + filename).c_str());
	}
}

bool StreamTokenizer::HasNext()
{
	if (m_sfs.eof())
	{
		return false;
	}

	m_sfs.get(m_cCurrentChar);

	return StreamTokenizer::IsDelim(m_cCurrentChar)
		? HasNext()
		: true;
}

Token StreamTokenizer::GetNext()
{
	if (m_cCurrentChar == '\0')
	{
		throw exception();
	}

	Token token;
	token.word += m_cCurrentChar;

	if (StreamTokenizer::IsWord(m_cCurrentChar))
	{
		while (!m_sfs.eof())
		{
			m_sfs.get(m_cCurrentChar);

			if (!StreamTokenizer::IsWord(m_cCurrentChar) && !StreamTokenizer::IsNumber(m_cCurrentChar))
			{
				break;
			}

			token.word += m_cCurrentChar;
		}

		token.type = (int)Token::Type::TT_WORD;
	}
	else if (StreamTokenizer::IsNumber(m_cCurrentChar))
	{
		while (!m_sfs.eof())
		{
			m_sfs.get(m_cCurrentChar);

			if (!StreamTokenizer::IsNumber(m_cCurrentChar))
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
