#ifndef ADDITION_EXPRESSION_H
#define ADDITION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - AdditionExpression
 */
class AdditionExpression : public NonTerminalExpression
{
public:

	AdditionExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
