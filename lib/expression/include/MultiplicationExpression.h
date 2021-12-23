#ifndef MULTIPLICATION_EXPRESSION_H
#define MULTIPLICATION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - MultiplicationExpression
 */
class MultiplicationExpression : public NonTerminalExpression
{
public:

	MultiplicationExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

#endif
