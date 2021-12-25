#ifndef AND_EXPRESSION_H
#define AND_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - AndExpression
 */
class AndExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur AndExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	AndExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
