#include "MultiplicationExpression.h"

MultiplicationExpression::MultiplicationExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long MultiplicationExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) * m_right->Evaluate(context);
}
