#include "Statement.h"

#include <iostream>

// Statement

Statement* Statement::create(TokenIt& it)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	switch (tokenType)
	{
	case Token::Type::Keyword:
		{
			if ( tokenData == "var" )
			{
				return new AssignmentStatement( it );
			}
			else if ( tokenData == "print" )
			{
				return new PrintStatement( it );
			}
		}
		break;

	case Token::Type::Identifier:
		break;

	case Token::Type::Operator:
		break;

	case Token::Type::Number:
		break;
	}

	throw exception(
		(string("Unexpected statement: ") + Token::GetStringType(tokenType) + " " + tokenData).c_str()
	);
}

// AssignmentStatement

AssignmentStatement::AssignmentStatement(TokenIt& it)
	: m_expression( nullptr )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	if ( tokenType == Token::Type::Keyword )
	{
		// Expect
		if ( tokenData != "var" )
		{
			throw exception( "error 1" );
		}

		it++;
		if ( it->GetType() != Token::Type::Identifier )
		{
			throw exception( "error 2" );
		}

		m_variable = it->GetData();

		it++;
		if (it->GetType() != Token::Type::Operator || it->GetData() != "=")
		{
			it--;
			return;
		}

		it++;
		m_expression = Expression::Parse(it);
	}
}

void AssignmentStatement::Execute(Context& context)
{
	context.SetValue(m_variable, m_expression ? m_expression->Evaluate(context) : 0);
}

// PrintStatement

PrintStatement::PrintStatement(TokenIt& it)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	// Expect
	if ( tokenType != Token::Type::Keyword || tokenData != "print" )
	{
		throw exception("error 1");
	}

	it++;
	m_expression = Expression::Parse(it);
}

void PrintStatement::Execute(Context& context)
{
	cout << m_expression->Evaluate(context) << endl;
}
