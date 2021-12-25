#include "Terminal/Identifier.h"

Identifier::Identifier(string value)
	: ::TerminalExpression(value)
{}

long Identifier::Evaluate(Context& context)
{
	long identifierValue = context.GetValue( this->m_value );
	if (identifierValue == -1)
	{
		throw exception(
			(string("Erreur: variable ") + this->m_value + " indéfinit").c_str()
		);
	}

	return identifierValue;
}
