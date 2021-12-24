#ifndef TERMINAL_EXPRESSION_H
#define TERMINAL_EXPRESSION_H

#include "Expression.h"

/**
 * Classe TerminalExpression
 * 
 * Cette classe permet de crée une expression terminal.
 */
class TerminalExpression : public Expression
{
public:

	TerminalExpression(string value);

	virtual long Evaluate(Context& context) = 0;

protected:

	string m_value;
};

#endif
