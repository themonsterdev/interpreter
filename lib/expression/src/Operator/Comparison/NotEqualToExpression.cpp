#include "Operator/Comparison/NotEqualToExpression.h"

NotEqualToExpression::NotEqualToExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long NotEqualToExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) != m_right->Evaluate(context);
}
