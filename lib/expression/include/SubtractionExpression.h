#ifndef SUBTRACTION_EXPRESSION_H
#define SUBTRACTION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - SubtractionExpression
 */
class SubtractionExpression : public NonTerminalExpression
{
public:

	SubtractionExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

#endif
