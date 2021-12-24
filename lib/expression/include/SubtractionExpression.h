#ifndef SUBTRACTION_EXPRESSION_H
#define SUBTRACTION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - SubtractionExpression
 */
class SubtractionExpression : public NonTerminalExpression
{
public:

	SubtractionExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
