#include "Operator/Comparison/GreaterThanOrEqualToExpression.h"

GreaterThanOrEqualToExpression::GreaterThanOrEqualToExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long GreaterThanOrEqualToExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) >= m_right->Evaluate(context);
}
