#include "Expression.h"
#include "TerminalExpression.h"
#include "AdditionExpression.h"
#include "SubtractionExpression.h"
#include "MultiplicationExpression.h"
#include "DivisionExpression.h"
#include "ModuloExpression.h"

#include <iostream>

Expression::ExprPtr Expression::Parse(TokenIt& it)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	Expression* pExpression = nullptr;

	switch ( tokenType )
	{
	case Token::Type::Number:
		{
			Expression* pLeftExpression;
			int tokenDataNumber;

			do {
				if ( pExpression == nullptr )
				{
					// Print left expression
					tokenDataNumber = stoi( tokenData );
					// cout << "Number left: " << tokenDataNumber << endl;
					pLeftExpression = new Number( tokenDataNumber );
					it++;
				}
				else
				{
					pLeftExpression = pExpression;
				}
				


				if ( it->GetType() == Token::Type::Operator )
				{
					string tokenDataOperator = it->GetData();

					if ( tokenDataOperator == "+" )
					{
						pExpression = new AdditionExpression( pLeftExpression );
					}
					else if ( tokenDataOperator == "-" )
					{
						pExpression = new SubtractionExpression( pLeftExpression );
					}
					else if ( tokenDataOperator == "*" )
					{
						pExpression = new MultiplicationExpression( pLeftExpression );
					}
					else if ( tokenDataOperator == "/" )
					{
						pExpression = new DivisionExpression( pLeftExpression );
					}
					else if ( tokenDataOperator == "%" )
					{
						pExpression = new ModuloExpression( pLeftExpression );
					}
					else
					{
						throw exception(
							( string( "Opérateur inattendu: " ) + tokenDataOperator ).c_str()
						);
					}
					// Print "Operator: ( + | - | = | ect )"
					// cout << "Operator: " << tokenDataOperator << endl;




					it++;
					if (it->GetType() != Token::Type::Number)
					{
						throw exception(
							(string("Unsupported operand types: Number ") + tokenDataOperator + " " + tokenData).c_str()
						);
					}

					// Print right expression
					tokenData = it->GetData();
					tokenDataNumber = stoi(tokenData);
					// cout << "Number right: " << tokenDataNumber << endl;

					reinterpret_cast<NonTerminalExpression*>(pExpression)
						->SetRight(new Number(tokenDataNumber));


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
		}
		break;

	case Token::Type::Identifier:
		pExpression = new Identifier( tokenData );

		/*it++;

		if (it->GetType() == Token::Type::Operator)
		{
			cout << "token " << it->GetData() << endl;
		}
		else
		{
			it--;
		}*/
		break;

	default:
		throw exception(
			(string("Expression inattendue: ") + tokenData).c_str()
		);
	}

	return ExprPtr(pExpression);
}
