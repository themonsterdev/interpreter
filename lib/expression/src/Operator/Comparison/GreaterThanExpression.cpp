#include "Operator/Comparison/GreaterThanExpression.h"

GreaterThanExpression::GreaterThanExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long GreaterThanExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) > m_right->Evaluate(context);
}
