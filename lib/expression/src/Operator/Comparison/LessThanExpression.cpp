#include "Operator/Comparison/LessThanExpression.h"

LessThanExpression::LessThanExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long LessThanExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) < m_right->Evaluate(context);
}
