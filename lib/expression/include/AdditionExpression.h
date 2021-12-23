#ifndef ADDITION_EXPRESSION_H
#define ADDITION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - AdditionExpression
 */
class AdditionExpression : public NonTerminalExpression
{
public:

	AdditionExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

#endif
