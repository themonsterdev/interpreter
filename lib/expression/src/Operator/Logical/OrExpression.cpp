#include "Operator/Logical/OrExpression.h"

OrExpression::OrExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long OrExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) != 0 || m_right->Evaluate(context) != 0;
}
