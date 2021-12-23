#include "MultiplicationExpression.h"

MultiplicationExpression::MultiplicationExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long MultiplicationExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) * m_right->evaluate(context);
}
