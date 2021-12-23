#ifndef DIVISION_EXPRESSION_H
#define DIVISION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - DivisionExpression
 */
class DivisionExpression : public NonTerminalExpression
{
public:

	DivisionExpression(Expression* left, Expression* right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
