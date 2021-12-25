#include "Operator/Comparison/EqualToExpression.h"

EqualToExpression::EqualToExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long EqualToExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) == m_right->Evaluate(context);
}
