#ifndef IDENTIFIER_EXPRESSION_H
#define IDENTIFIER_EXPRESSION_H

#include "TerminalExpression.h"

/**
 * Classe Identifier
 */
class Identifier : public TerminalExpression
{
public:

	Identifier(string value);

	virtual long Evaluate(Context& context);
};

#endif
