#ifndef SUBTRACTION_EXPRESSION_H
#define SUBTRACTION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - SubtractionExpression
 */
class SubtractionExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur SubtractionExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	SubtractionExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
