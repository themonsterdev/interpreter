#include "Tokenizer/StreamTokenizer.h"
#include "Tokenizer/Token.h"

StreamTokenizer::StreamTokenizer(string filename)
	: ::AbstractTokenizer()
{
	m_sfs.open(filename);

	if (!m_sfs || !m_sfs.is_open())
	{
		throw((string("Impossible d'ouvrir le fichier ") + filename).c_str());
	}
}

bool StreamTokenizer::HasNext()
{
	if (m_sfs.eof())
	{
		return false;
	}

	m_sfs.get(m_cCurrentChar);

	return AbstractTokenizer::HasNext();
}

Token StreamTokenizer::GetNext()
{
	Token token = AbstractTokenizer::GetNext();

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

		// cout << wsValue << endl;

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

		// cout << wsValue << endl;

		token = Token(stol(wsValue));
	}
	else
	{
		// cout << m_cCurrentChar << endl;
		token = Token(m_cCurrentChar);
	}

	m_cCurrentChar = '\0';

	return token;
}
