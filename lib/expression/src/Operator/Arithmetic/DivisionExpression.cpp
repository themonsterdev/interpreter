#include "Operator/Arithmetic/DivisionExpression.h"

DivisionExpression::DivisionExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long DivisionExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) / m_right->Evaluate(context);
}
