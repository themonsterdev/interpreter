#include "TerminalExpression.h"

// TerminalExpression

TerminalExpression::TerminalExpression(string name)
	: m_name(name)
{}

long TerminalExpression::Evaluate(Context& context)
{
	return context.GetValue(m_name);
}

// Number

Number::Number(long number)
	: m_number(number)
{}

long Number::Evaluate(Context&)
{
	return m_number;
}

// Identifier

Identifier::Identifier(string identifier)
	: m_identifier(identifier)
{}

long Identifier::Evaluate(Context& context)
{
	return context.GetValue(m_identifier);
}
