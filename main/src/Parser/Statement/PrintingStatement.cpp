#include "Parser/Statement/PrintingStatement.h"

// Expression
#include "Parser/Expression/AbstractExpression.h"
#include "Parser/Expression/NumberExpression.h"

// Expression/Operator
#include "Parser/Expression/Operator/OperatorExpression.h"

PrintingStatement::PrintingStatement(Token::Iterator& begin, Token::Iterator& end)
{
	assert(begin != end);										// Vérifie qu'un jeton est présent.
	assert(begin->HasType((int)Token::Type::KEYWORD));			// Vérifie que c'est bien une chaine de caractère.
	assert(begin->GetWordValue() == "print");					// Vérifie que c'est bien le mot clès `print`.
	begin++;													// Passer au prochain jeton de l'itération.

	m_expression = Parser::GetLiteralExpression(begin, end);	// Obtenir une expression du jeton.
	assert(m_expression != nullptr);							// Vérifie que l'expression à bien était optenue.
}

void PrintingStatement::Interpret(Context& context)
{
	 m_expression->Interpret(context);

	 switch (m_expression->GetType())
	 {
	 case (int)ExpressionInterface::Type::NUMBER:
		 {
			 long lValue = context.m_lValues.top();
			 context.m_lValues.pop();

			 cout << "\x1B[36m" << "print" << "\033[0m" << ": ";
			 cout << "\x1B[33m" << lValue << "\033[0m" << endl;
		 }
		 break;

	 case (int)ExpressionInterface::Type::IDENTIFIER:
		 {
			 long lValue = context.m_lValues.top();
			 context.m_lValues.pop();

			 cout << "\x1B[36m" << "print" << "\033[0m" << ": ";
			 cout << "\x1B[33m" << lValue << "\033[0m" << endl;
		 }
		 break;
	 }
}
