#ifndef MULTIPLICATION_EXPRESSION_H
#define MULTIPLICATION_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - MultiplicationExpression
 */
class MultiplicationExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur MultiplicationExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	MultiplicationExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
