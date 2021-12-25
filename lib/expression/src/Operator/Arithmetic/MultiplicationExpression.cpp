#include "Operator/Arithmetic/MultiplicationExpression.h"

MultiplicationExpression::MultiplicationExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long MultiplicationExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) * m_right->Evaluate(context);
}
