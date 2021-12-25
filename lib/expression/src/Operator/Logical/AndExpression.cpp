#include "Operator/Logical/AndExpression.h"

AndExpression::AndExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long AndExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) != 0 && m_right->Evaluate(context) != 0;
}
