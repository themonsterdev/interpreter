#ifndef TERMINAL_EXPRESSION_H
#define TERMINAL_EXPRESSION_H

#include "Expression.h"

/**
 * Classe TerminalExpression
 */
class TerminalExpression : public Expression
{
public:

	TerminalExpression(string name);

	virtual long evaluate(Context& context);

private:

	string m_name;
};

class Number : public Expression
{
public:

	Number(long number);
	virtual long evaluate(Context& context);

private:

	long m_number;
};

class Identifier : public Expression
{
public:

	Identifier(string identifier);
	virtual long evaluate(Context& context);

private:

	string m_identifier;
};

#endif
