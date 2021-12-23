#include "NonTerminalExpression.h"

NonTerminalExpression::NonTerminalExpression(Expression* left, Expression* right)
	: m_left(left)
	, m_right(right)
{}


Expression* NonTerminalExpression::getRight()
{
	return m_right;
}

void NonTerminalExpression::setRight(Expression* right)
{
	m_right = right;
}
