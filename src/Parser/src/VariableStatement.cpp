#include "VariableStatement.h"
#include <iostream>


VariableStatement::VariableStatement(Token::Iterator& begin, Token::Iterator& end)
{
	if (begin == end || begin->type != (int)Token::Type::TT_WORD)
	{
		throw exception("Attend un identifiant!");
	}

	cout << "VariableStatement: ok" << endl;
}

void VariableStatement::Interpret(Context* context)
{

}
