#ifndef MODULO_EXPRESSION_H
#define MODULO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - ModuloExpression
 */
class ModuloExpression : public NonTerminalExpression
{
public:

	/**
	 * Constructeur ModuloExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	ModuloExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context);
};

#endif
