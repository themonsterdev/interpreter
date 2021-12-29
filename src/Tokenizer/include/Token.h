#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <list>

using namespace std;

class Token
{
public:

	typedef list<Token> List;
	typedef List::iterator Iterator;

	enum class Type : int
	{
		TT_WORD		= -4,
		TT_NUMBER	= -3,
		TT_EOL		= -2,
		TT_EOF		= EOF
	};

	int		type;
	string	word;
	char	character;
	double	number;
};

#endif
