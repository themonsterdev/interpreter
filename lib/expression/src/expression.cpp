#include "Expression.h"
#include "TerminalExpression.h"
#include "AdditionExpression.h"
#include "SubtractionExpression.h"
#include "MultiplicationExpression.h"
#include "DivisionExpression.h"
#include "ModuloExpression.h"

#include <iostream>

Expression::ExprPtr Expression::parse(TokenIt& it)
{
	Token::Type tokenType = it->getType();
	string tokenData = it->getData();

	Expression* pExpression = nullptr;

	switch (tokenType)
	{
	case Token::Type::Number:
		{
			pExpression = new Number(stoi(tokenData));

			it++;

			if (it->getType() == Token::Type::Operator)
			{
				string tokenDataOperator = it->getData();

				if (tokenDataOperator == "+")
				{
					pExpression = new AdditionExpression(pExpression);
				}
				else if (tokenDataOperator == "-")
				{
					pExpression = new SubtractionExpression(pExpression);
				}
				else if (tokenDataOperator == "*")
				{
					pExpression = new MultiplicationExpression(pExpression);
				}
				else if (tokenDataOperator == "/")
				{
					pExpression = new DivisionExpression(pExpression);
				}
				else if (tokenDataOperator == "%")
				{
					pExpression = new ModuloExpression(pExpression);
				}
				else
				{
					throw exception(
						(string("Unexpected: ") + tokenDataOperator).c_str()
					);
				}

				it++;

				if (it->getType() != Token::Type::Number)
				{
					throw exception(
						(string("Unexpected: ") + tokenData).c_str()
					);
				}

				reinterpret_cast<NonTerminalExpression*>(pExpression)
					->setRight(
						new Number( stoi(it->getData() ) )
					);
			}
			else
			{
				it--;
			}
		}
		break;

	case Token::Type::Identifier:
		pExpression = new Identifier(tokenData);
		// it++;
		break;

	default:
		throw exception(
			(string("Unexpected : ") + tokenData).c_str()
		);
	}

	return ExprPtr(pExpression);
}
