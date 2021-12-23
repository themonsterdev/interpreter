#ifndef MODULO_EXPRESSION_H
#define MODULO_EXPRESSION_H

#include "NonTerminalExpression.h"

/**
 * NonTerminalExpression - ModuloExpression
 */
class ModuloExpression : public NonTerminalExpression
{
public:

	ModuloExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

#endif
