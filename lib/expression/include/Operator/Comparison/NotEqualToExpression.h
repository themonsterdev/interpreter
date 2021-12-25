#ifndef NOT_EQUAL_TO_EXPRESSION_H
#define NOT_EQUAL_TO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - NotEqualToExpression
 */
class NotEqualToExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur NotEqualToExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	NotEqualToExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
