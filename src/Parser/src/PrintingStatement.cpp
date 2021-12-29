#include "PrintingStatement.h"
#include <iostream>

PrintingStatement::PrintingStatement(Token::Iterator& begin, Token::Iterator& end)
{
	if (begin == end || begin->type != (int)Token::Type::TT_WORD || begin->word != "print")
	{
		throw exception("Attend un mot clès print!");
	}

	cout << "PrintingStatement: ok" << endl;
}

void PrintingStatement::Interpret(Context* context)
{
	
}
