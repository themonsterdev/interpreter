#include "NonTerminalExpression.h"

NonTerminalExpression::NonTerminalExpression(Expression* left, Expression* right)
	: m_left(left)
	, m_right(right)
{}


Expression* NonTerminalExpression::GetRight()
{
	return m_right;
}

void NonTerminalExpression::SetRight(Expression* right)
{
	m_right = right;
}
