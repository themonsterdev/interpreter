#include "AdditionExpression.h"

AdditionExpression::AdditionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long AdditionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) + m_right->evaluate(context);
}
