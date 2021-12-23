#include "Statement.h"

#include <iostream>

// Statement

Statement* Statement::create( Context& context, TokenIt& it )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	switch (tokenType)
	{
	case Token::Type::Keyword:
		{
			if ( tokenData == "var" )
			{
				return new AssignmentStatement( context, it );
			}
			else if ( tokenData == "print" )
			{
				return new PrintStatement( it );
			}
		}
		break;

	case Token::Type::Identifier:
		return new AssignmentStatement(context, it);
		break;

	case Token::Type::Operator:
		break;

	case Token::Type::Number:
		break;
	}

	throw exception(
		(string("Erreur: Déclaration inattendue, ") + Token::GetStringType(tokenType) + " " + tokenData).c_str()
	);
}

// AssignmentStatement

AssignmentStatement::AssignmentStatement(Context& context, TokenIt& it)
	: m_expression( nullptr )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	if ( tokenType == Token::Type::Keyword )
	{
		// Expect
		if ( tokenData != "var" )
		{
			throw exception( "Erreur: Le jeton attendu doit être un 'var' " );
		}

		it++;
		if ( it->GetType() != Token::Type::Identifier )
		{
			throw exception(
				(string("Erreur de syntaxe, token '") + tokenData + "' inattendu").c_str()
			);
		}

		tokenData = it->GetData();
		if (context.GetValue(tokenData) != -1)
		{
			throw exception(
				(string("Erreur: Redéfinition de la variable ") + tokenData).c_str()
			);
		}

		m_variable = it->GetData();
		context.SetValue(m_variable, 0);

		it++;
		if (it->GetType() != Token::Type::Operator || it->GetData() != "=")
		{
			it--;
			return;
		}

		it++;
		m_expression = Expression::Parse(it);
	}
	else if (tokenType == Token::Type::Identifier)
	{
		long identifierValue = context.GetValue(tokenData);
		if (identifierValue == -1)
		{
			throw exception(
				(string("Erreur: variable ") + tokenData + " indéfinit").c_str()
			);
		}

		m_variable = it->GetData();
		context.SetValue(m_variable, 0);

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
		throw exception("Erreur: Le token doit être de type 'Token::Type::Keyword' et les donnée égale = 'print'");
	}

	it++;
	m_expression = Expression::Parse(it);
}

void PrintStatement::Execute(Context& context)
{
	cout << m_expression->Evaluate(context) << endl;
}
