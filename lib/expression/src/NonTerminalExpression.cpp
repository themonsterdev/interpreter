#include "NonTerminalExpression.h"

NonTerminalExpression::NonTerminalExpression(Expression::Pointer left, Expression::Pointer right)
	: m_left(left)
	, m_right(right)
{}


Expression::Pointer NonTerminalExpression::GetRight()
{
	return m_right;
}

void NonTerminalExpression::SetRight(Expression::Pointer right)
{
	m_right = right;
}
