#include "DivisionExpression.h"

DivisionExpression::DivisionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long DivisionExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) / m_right->Evaluate(context);
}
