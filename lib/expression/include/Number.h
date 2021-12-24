#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "TerminalExpression.h"

/**
 * Classe Number
 */
class Number : public TerminalExpression
{
public:

	/**
	 * Constructeur Number.
	 *
	 * @param value La valeur de type numérique.
	 */
	Number(string value);

	virtual long Evaluate(Context& context);
};

#endif
