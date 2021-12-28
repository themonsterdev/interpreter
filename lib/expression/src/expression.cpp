#include "Expression.h"

// Terminal Expression
#include "Terminal/Identifier.h"
#include "Terminal/Number.h"

// Opérateurs arithmétiques
#include "Operator/Arithmetic/AdditionExpression.h"
#include "Operator/Arithmetic/SubtractionExpression.h"
#include "Operator/Arithmetic/MultiplicationExpression.h"
#include "Operator/Arithmetic/DivisionExpression.h"
#include "Operator/Arithmetic/ModuloExpression.h"

// Opérateurs de comparaison
#include "Operator/Comparison/EqualToExpression.h"
#include "Operator/Comparison/GreaterThanExpression.h"
#include "Operator/Comparison/GreaterThanOrEqualToExpression.h"
#include "Operator/Comparison/LessThanExpression.h"
#include "Operator/Comparison/LessThanOrEqualToExpression.h"
#include "Operator/Comparison/NotEqualToExpression.h"
// #include "Operator/Comparison/ThreeWayExpression.h"

// Opérateurs logiques
// #include "Operator/Logical/AndExpression.h"
// #include "Operator/Logical/NegationExpression.h"
// #include "Operator/Logical/OrExpression.h"

#include <iostream>

Expression::Pointer Expression::Parse( Token::Iterator& begin, Token::Iterator& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Expression::Parse(begin == end)").c_str()
		);
	}

	switch ( begin->GetType() )
	{
	case Token::Type::Number:
		return Expression::ParseExpressionFromNumber( begin, end );

	case Token::Type::Identifier:
		return Expression::ParseExpressionFromIdentifier( begin, end );

	case Token::Type::Operator:
		return Expression::ParseExpressionFromOperator(nullptr, begin, end);

	default:
		throw exception(
			( string( "Expression inattendue: " ) + begin->GetData() ).c_str()
		);
	}
}

Expression::Pointer Expression::ParseExpressionFromNumber( Token::Iterator& begin, Token::Iterator& end)
{
	if ( begin == end )
	{
		throw exception(
			string("Expression::ParseExpressionFromNumber(begin == end)").c_str()
		);
	}

	Expression::Pointer pExpression = make_shared<Number>( begin->GetData() );

	begin++;
	if ( begin != end && begin->GetType() == Token::Type::Operator)
	{
		return ParseExpressionFromOperator(pExpression, begin, end);
	}
	begin--;

	return pExpression;
}

Expression::Pointer Expression::ParseExpressionFromIdentifier( Token::Iterator& begin, Token::Iterator& end)
{
	if ( begin == end )
	{
		throw exception(
			string("Expression::ParseExpressionFromIdentifier(begin == end)").c_str()
		);
	}

	Expression::Pointer pExpression = make_shared<Identifier>(begin->GetData());

	begin++;
	if (begin != end && begin->GetType() == Token::Type::Operator)
	{
		return ParseExpressionFromOperator(pExpression, begin, end);
	}
	begin--;

	return pExpression;
}

Expression::Pointer Expression::ParseExpressionFromOperator( Expression::Pointer leftExpression, Token::Iterator& begin, Token::Iterator& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Expression::ParseExpressionFromOperator(begin == end)").c_str()
		);
	}

	if ( begin->GetType() != Token::Type::Operator )
	{
		throw exception(
			string("Expression::ParseExpressionFromOperator(begin->GetType() != Token::Type::Operator)").c_str()
		);
	}

	Expression::Pointer pExpression = nullptr;

	string tokenDataOperator = begin->GetData();

	// Opérateurs arithmétiques
	if ( tokenDataOperator == "+" )
	{
		pExpression = make_shared<AdditionExpression>( leftExpression );
	}
	else if ( tokenDataOperator == "-" )
	{
		pExpression = make_shared<SubtractionExpression>( leftExpression );
	}
	else if ( tokenDataOperator == "*" )
	{
		pExpression = make_shared<MultiplicationExpression>( leftExpression );
	}
	else if ( tokenDataOperator == "/" )
	{
		pExpression = make_shared<DivisionExpression>( leftExpression );
	}
	else if ( tokenDataOperator == "%" )
	{
		pExpression = make_shared<ModuloExpression>( leftExpression );
	}
	// Opérateurs de comparaison
	else if (tokenDataOperator == "=")
	{
		begin++;
		if (begin != end && begin->GetData() == "=")
		{
			pExpression = make_shared<EqualToExpression>(leftExpression);
		}
		else
		{
			throw exception(
				string("if (begin != end && begin->GetData() == ").c_str()
			);
		}
	}
	else if (tokenDataOperator == ">")
	{
		begin++;
		if (begin != end && begin->GetData() == "=")
		{
			pExpression = make_shared<GreaterThanOrEqualToExpression>(leftExpression);
		}
		else
		{
			begin--;

			pExpression = make_shared<GreaterThanExpression>(leftExpression);
		}
	}
	else if (tokenDataOperator == "<")
	{
		begin++;
		if (begin != end && begin->GetData() == "=")
		{
			pExpression = make_shared<LessThanOrEqualToExpression>(leftExpression);
		}
		else
		{
			begin--;

			pExpression = make_shared<LessThanExpression>(leftExpression);
		}
	}
	else if (tokenDataOperator == "!")
	{
		begin++;
		if (begin != end && begin->GetData() == "=")
		{
			pExpression = make_shared<NotEqualToExpression>(leftExpression);
		}
		else
		{
			throw exception(
				string("if (begin != end && begin->GetData() == `=`)").c_str()
			);
		}
	}
	else
	{
		throw exception(
			( string("Expression::ParseExpressionFromOperator(begin->GetData(`") + tokenDataOperator + "`) non supporter)" ).c_str()
		);
	}

	begin++;
	if ( begin == end )
	{
		throw exception(
			string("Expression::ParseExpressionFromOperator(`Opération invalid`))").c_str()
		);
	}
	NonTerminalExpression* pNonTerminalExpression = reinterpret_cast<NonTerminalExpression*>(
		pExpression.get()
	);
	pNonTerminalExpression->SetRight(
		Expression::Parse(begin, end)
	);
	return pExpression;
}
