#include "Operator/Comparison/LessThanOrEqualToExpression.h"

LessThanOrEqualToExpression::LessThanOrEqualToExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long LessThanOrEqualToExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) <= m_right->Evaluate(context);
}
