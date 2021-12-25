#ifndef EQUAL_TO_EXPRESSION_H
#define EQUAL_TO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - EqualToExpression
 */
class EqualToExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur EqualToExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	EqualToExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
