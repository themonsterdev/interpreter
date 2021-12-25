#ifndef GREATER_THAN_OR_EQUAL_TO_EXPRESSION_H
#define GREATER_THAN_OR_EQUAL_TO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - GreaterThanOrEqualToExpression
 */
class GreaterThanOrEqualToExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur GreaterThanOrEqualToExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	GreaterThanOrEqualToExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
