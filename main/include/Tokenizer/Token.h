#ifndef TOKEN_H
#define TOKEN_H

#include "stdafx.h"

class Token
{
public:

	typedef list<Token> List;
	typedef List::iterator Iterator;

	enum class Type : int
	{
		IDENTIFIER	= -5,
		KEYWORD		= -1,
		NUMBER		= -3
	};

	Token();
	Token(string ws, Type type = Type::IDENTIFIER);
	Token(const long d, Type type = Type::NUMBER);
	Token(const char c);

	bool	HasType(int type);
	int		GetType();

	char	GetCharValue();
	string	GetWordValue();
	long	GetNumberValue();

private:

	int		m_iType;

	string	m_wsValue;
	long	m_lValue;
};

#endif
