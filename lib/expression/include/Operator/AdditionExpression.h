#ifndef ADDITION_EXPRESSION_H
#define ADDITION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - AdditionExpression
 */
class AdditionExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur AdditionExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	AdditionExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
