#include "TerminalExpression.h"

// TerminalExpression

TerminalExpression::TerminalExpression(string name)
	: m_name(name)
{}

long TerminalExpression::evaluate(Context& context)
{
	return context.getValue(m_name);
}

// Number

Number::Number(long number)
	: m_number(number)
{}

long Number::evaluate(Context&)
{
	return m_number;
}

// Identifier

Identifier::Identifier(string identifier)
	: m_identifier(identifier)
{}

long Identifier::evaluate(Context& context)
{
	return context.getValue(m_identifier);
}
