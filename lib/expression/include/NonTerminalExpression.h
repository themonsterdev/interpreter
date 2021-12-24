#ifndef NON_TERMINAL_EXPRESSION_H
#define NON_TERMINAL_EXPRESSION_H

#include "Expression.h"

/**
 * NonTerminalExpression
 * 
 * Cette classe permet de crée une expression non terminal.
 */
class NonTerminalExpression : public Expression
{
public:

	/**
	 * Constructeur NonTerminalExpression.
	 *
	 * @param  left Pointer de l'expression gauche.
	 * @param  right Pointer de l'expression droite.
	 */
	NonTerminalExpression(Expression::Pointer left, Expression::Pointer right = nullptr);

	virtual long Evaluate(Context& context) = 0;

	/**
	 * Optenir l'expression de droite.
	 *
	 * @return Pointer
	 */
	Expression::Pointer GetRight();

	/**
	 * Ajouter l'expression de droite.
	 *
	 * @return void
	 */
	void SetRight(Expression::Pointer right);

protected:

	Expression::Pointer m_left, m_right;
};

#endif
