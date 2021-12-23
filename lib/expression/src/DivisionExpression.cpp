#include "DivisionExpression.h"

DivisionExpression::DivisionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long DivisionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) / m_right->evaluate(context);
}
