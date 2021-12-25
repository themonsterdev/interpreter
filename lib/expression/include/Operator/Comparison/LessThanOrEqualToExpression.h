#ifndef LESS_THAN_OR_EQUAL_TO_EXPRESSION_H
#define LESS_THAN_OR_EQUAL_TO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - LessThanOrEqualToExpression
 */
class LessThanOrEqualToExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur LessThanOrEqualToExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	LessThanOrEqualToExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
