#ifndef NON_TERMINAL_EXPRESSION_H
#define NON_TERMINAL_EXPRESSION_H

#include "Expression.h"

/**
 * NonTerminalExpression
 */
class NonTerminalExpression : public Expression
{
public:

	NonTerminalExpression(Expression* left, Expression* right = nullptr);

	virtual long Evaluate(Context& context) = 0;

	Expression* GetRight();
	void SetRight(Expression* right);

protected:

	Expression *m_left, *m_right;
};

#endif
