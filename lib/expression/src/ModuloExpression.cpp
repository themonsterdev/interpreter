#include "ModuloExpression.h"

ModuloExpression::ModuloExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long ModuloExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) % m_right->evaluate(context);
}
