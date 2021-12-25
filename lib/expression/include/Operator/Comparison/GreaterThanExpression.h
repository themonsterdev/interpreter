#ifndef GREATER_THAN_EXPRESSION_H
#define GREATER_THAN_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - GreaterThanExpression
 */
class GreaterThanExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur GreaterThanExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	GreaterThanExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
