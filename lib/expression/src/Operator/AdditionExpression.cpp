#include "Operator/AdditionExpression.h"

AdditionExpression::AdditionExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long AdditionExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) + m_right->Evaluate(context);
}
