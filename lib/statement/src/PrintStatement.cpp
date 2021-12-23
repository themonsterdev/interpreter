#include "PrintStatement.h"

#include <iostream>

// PrintStatement

PrintStatement::PrintStatement(TokenIt& it)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	// Expect
	if (tokenType != Token::Type::Keyword || tokenData != "print")
	{
		throw exception("Erreur: Le token doit être de type 'Token::Type::Keyword' et les donnée égale = 'print'");
	}

	it++;
	m_expression = Expression::Parse(it);
}

void PrintStatement::Execute(Context& context)
{
	cout << m_expression->Evaluate(context) << endl;
}
