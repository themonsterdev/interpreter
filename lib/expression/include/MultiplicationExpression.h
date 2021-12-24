#ifndef MULTIPLICATION_EXPRESSION_H
#define MULTIPLICATION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - MultiplicationExpression
 */
class MultiplicationExpression : public NonTerminalExpression
{
public:

	MultiplicationExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
