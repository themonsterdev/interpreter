#include "SubtractionExpression.h"

SubtractionExpression::SubtractionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long SubtractionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) - m_right->evaluate(context);
}
