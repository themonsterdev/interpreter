#include "Expression.h"

// Terminal Expression
#include "Identifier.h"
#include "Number.h"

// Non Terminal Expression
#include "AdditionExpression.h"
#include "SubtractionExpression.h"
#include "MultiplicationExpression.h"
#include "DivisionExpression.h"
#include "ModuloExpression.h"

#include <iostream>

Expression::Pointer Expression::Parse(TokenIt& it)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	Expression* pExpression = nullptr;

	switch ( tokenType )
	{
	case Token::Type::Number:
		return Expression::ParseExpressionFromNumber( it );

	case Token::Type::Identifier:
		return Expression::ParseExpressionFromIdentifier( it );

	default:
		throw exception(
			( string( "Expression inattendue: " ) + tokenData ).c_str()
		);
	}

	return Expression::Pointer(pExpression);
}

Expression::Pointer Expression::ParseExpressionFromNumber(TokenIt& it)
{
	string tokenData = it->GetData();

	Expression::Pointer pLeftExpression;
	Expression::Pointer pExpression = nullptr;

	do {
		if (pExpression == nullptr)
		{
			// Print left expression
			pLeftExpression = make_shared<Number>(tokenData);
			it++;
		}
		else
		{
			pLeftExpression = pExpression;
		}



		if (it->GetType() == Token::Type::Operator)
		{
			string tokenDataOperator = it->GetData();

			if (tokenDataOperator == "+")
			{
				pExpression = make_shared<AdditionExpression>(pLeftExpression);
			}
			else if (tokenDataOperator == "-")
			{
				pExpression = make_shared<SubtractionExpression>(pLeftExpression);
			}
			else if (tokenDataOperator == "*")
			{
				pExpression = make_shared<MultiplicationExpression>(pLeftExpression);
			}
			else if (tokenDataOperator == "/")
			{
				pExpression = make_shared<DivisionExpression>(pLeftExpression);
			}
			else if (tokenDataOperator == "%")
			{
				pExpression = make_shared<ModuloExpression>(pLeftExpression);
			}
			else
			{
				throw exception(
					(string("Opérateur inattendu: ") + tokenDataOperator).c_str()
				);
			}

			it++;
			if (it->GetType() != Token::Type::Number)
			{
				throw exception(
					(string("Unsupported operand types: Number ") + tokenDataOperator + " " + tokenData).c_str()
				);
			}

			// Print right expression
			tokenData = it->GetData();

			reinterpret_cast<NonTerminalExpression*>(pExpression.get())
				->SetRight(make_shared<Number>(tokenData));

			it++;
			if (it->GetType() != Token::Type::Operator)
			{
				it--;
			}
		}
		else
		{
			it--;
		}
	} while (it->GetType() == Token::Type::Operator);

	return Expression::Pointer(pExpression);
}

Expression::Pointer Expression::ParseExpressionFromIdentifier(TokenIt& it)
{
	return make_shared<Identifier>(it->GetData());
}
