#include "SubtractionExpression.h"

SubtractionExpression::SubtractionExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long SubtractionExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) - m_right->Evaluate(context);
}
