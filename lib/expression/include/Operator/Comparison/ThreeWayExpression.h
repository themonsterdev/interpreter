#ifndef THREE_WAY_EXPRESSION_H
#define THREE_WAY_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - ThreeWayExpression
 */
class ThreeWayExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur ThreeWayExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	ThreeWayExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
