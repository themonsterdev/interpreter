#include "statement.h"

#include <iostream>

// Statement

Statement* Statement::create(TokenIt& it)
{
	Token::Type tokenType = it->getType();
	string tokenData = it->getData();

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
		(string("Unexpected statement: ") + Token::getStringType(tokenType) + " " + tokenData).c_str()
	);
}

// AssignmentStatement

AssignmentStatement::AssignmentStatement(TokenIt& it)
	: m_expression( nullptr )
{
	Token::Type tokenType = it->getType();
	string tokenData = it->getData();

	if ( tokenType == Token::Type::Keyword )
	{
		// Expect
		if ( tokenData != "var" )
		{
			throw exception( "error 1" );
		}

		it++;
		if ( it->getType() != Token::Type::Identifier )
		{
			throw exception( "error 2" );
		}

		m_variable = it->getData();

		it++;
		if (it->getType() != Token::Type::Operator || it->getData() != "=")
		{
			it--;
			return;
		}

		it++;
		m_expression = Expression::parse(it);
	}
}

void AssignmentStatement::execute(Context& context)
{
	context.setValue(m_variable, m_expression ? m_expression->evaluate(context) : 0);
}

// PrintStatement

PrintStatement::PrintStatement(TokenIt& it)
{
	Token::Type tokenType = it->getType();
	string tokenData = it->getData();

	// Expect
	if ( tokenType != Token::Type::Keyword || tokenData != "print" )
	{
		throw exception("error 1");
	}

	it++;
	m_expression = Expression::parse(it);
}

void PrintStatement::execute(Context& context)
{
	cout << m_expression->evaluate(context) << endl;
}
