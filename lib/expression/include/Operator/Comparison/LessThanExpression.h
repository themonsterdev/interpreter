#ifndef LESS_THAN_EXPRESSION_H
#define LESS_THAN_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - LessThanExpression
 */
class LessThanExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur LessThanExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	LessThanExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
