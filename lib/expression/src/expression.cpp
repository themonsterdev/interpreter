#include "Expression.h"

// Terminal Expression
#include "Terminal/Identifier.h"
#include "Terminal/Number.h"

// Non Terminal Expression
#include "Operator/AdditionExpression.h"
#include "Operator/SubtractionExpression.h"
#include "Operator/MultiplicationExpression.h"
#include "Operator/DivisionExpression.h"
#include "Operator/ModuloExpression.h"

#include <iostream>

Expression::Pointer Expression::Parse( TokenIt& begin, TokenIt& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Erreur: Expression::Parse(begin == end)").c_str()
		);
	}

	switch ( begin->GetType() )
	{
	case Token::Type::Number:
		return Expression::ParseExpressionFromNumber( begin, end );

	case Token::Type::Identifier:
		return Expression::ParseExpressionFromIdentifier( begin, end );

	default:
		throw exception(
			( string( "Expression inattendue: " ) + begin->GetData() ).c_str()
		);
	}
}

Expression::Pointer Expression::ParseExpressionFromNumber( TokenIt& begin, TokenIt& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Erreur: Expression::ParseExpressionFromNumber(begin == end)").c_str()
		);
	}

	Expression::Pointer pLeftExpression = make_shared<Number>( begin->GetData() );

	begin++;
	if ( begin != end )
	{
		if ( begin->GetType() == Token::Type::Operator )
		{
			return ParseExpressionFromOperator( pLeftExpression, begin, end );
		}
		else
		{
			begin--;
		}
	}
	else
	{
		begin--;
	}

	return pLeftExpression;
}

Expression::Pointer Expression::ParseExpressionFromIdentifier( TokenIt& begin, TokenIt& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Erreur: Expression::ParseExpressionFromIdentifier(begin == end)").c_str()
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

Expression::Pointer Expression::ParseExpressionFromOperator( Expression::Pointer leftExpression, TokenIt& begin, TokenIt& end )
{
	if ( begin == end )
	{
		throw exception(
			string("Erreur: Expression::ParseExpressionFromOperator(begin == end)").c_str()
		);
	}

	if ( begin->GetType() != Token::Type::Operator )
	{
		throw exception(
			string("Erreur: Expression::ParseExpressionFromOperator(begin->GetType() != Token::Type::Operator)").c_str()
		);
	}

	Expression::Pointer pExpression = nullptr;

	string tokenDataOperator = begin->GetData();
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
	else
	{
		throw exception(
			( string("Erreur: Expression::ParseExpressionFromOperator(begin->GetData(`") + tokenDataOperator + "`) non supporter)" ).c_str()
		);
	}

	begin++;
	if ( begin == end )
	{
		throw exception(
			string("Erreur: Expression::ParseExpressionFromOperator(`Opération invalid`) non supporter)").c_str()
		);
	}

	NonTerminalExpression* pNonTerminalExpression = reinterpret_cast<NonTerminalExpression*>(
		pExpression.get()
	);

	pNonTerminalExpression->SetRight(
		begin->GetType() == Token::Type::Number ? ParseExpressionFromNumber(begin, end) : ParseExpressionFromIdentifier(begin, end)
	);

	return pExpression;
}
