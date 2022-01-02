#include "Tokenizer/StreamTokenizer.h"
#include "Tokenizer/Token.h"

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

	return __super::HasNext();
}

Token StreamTokenizer::GetNext()
{
	Token token = __super::GetNext();

	string wsValue;
	wsValue += m_cCurrentChar;

	if (StreamTokenizer::IsWord(m_cCurrentChar))
	{
		while (!m_sfs.eof())
		{
			m_sfs.get(m_cCurrentChar);

			if (!StreamTokenizer::IsWord(m_cCurrentChar) && !StreamTokenizer::IsNumber(m_cCurrentChar))
			{
				break;
			}

			wsValue += m_cCurrentChar;
		}

		bool isKeyword = IsKeyword(wsValue);
		token = Token(wsValue, isKeyword ? Token::Type::KEYWORD : Token::Type::IDENTIFIER);
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
