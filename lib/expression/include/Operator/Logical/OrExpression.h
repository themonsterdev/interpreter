#ifndef OR_EXPRESSION_H
#define OR_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - OrExpression
 */
class OrExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur OrExpression.
	 *
	 * @param left  Pointer de l'expression gauche.
	 * @param right Pointer de l'expression droite.
	 */
	OrExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
