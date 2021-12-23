#include "AdditionExpression.h"

AdditionExpression::AdditionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long AdditionExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) + m_right->Evaluate(context);
}