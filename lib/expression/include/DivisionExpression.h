#ifndef DIVISION_EXPRESSION_H
#define DIVISION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - DivisionExpression
 */
class DivisionExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur DivisionExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	DivisionExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
