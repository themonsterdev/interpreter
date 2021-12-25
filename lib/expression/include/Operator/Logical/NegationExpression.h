#ifndef NEGATION_EXPRESSION_H
#define NEGATION_EXPRESSION_H

#include "TerminalExpression.h"

/**
 * NonTerminalExpression - TerminalExpression
 */
class NegationExpression : public TerminalExpression
{
public:

	/**
	 * Constructeur NegationExpression.
	 *
	 * @param value La valeur terminal.
	 */
	NegationExpression(string value);

	virtual long Evaluate(Context& context);
};

#endif
