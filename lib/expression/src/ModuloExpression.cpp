#include "ModuloExpression.h"

ModuloExpression::ModuloExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long ModuloExpression::Evaluate(Context& context)
{
	return m_left->Evaluate(context) % m_right->Evaluate(context);
}
