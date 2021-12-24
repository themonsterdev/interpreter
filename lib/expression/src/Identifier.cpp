#include "Identifier.h"

Identifier::Identifier(string value)
	: ::TerminalExpression(value)
{}

long Identifier::Evaluate(Context& context)
{
	return context.GetValue(this->m_value);
}
