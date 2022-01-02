#include "Parser/Expression/AbstractExpression.h"

AbstractExpression::AbstractExpression()
{
	m_iType			= (int)Type::NONE;

	m_wsIdentifier	= "";
	m_bBoolean		= false;
	m_lNumber		= 0;
}

void AbstractExpression::SetType(int type)
{
	m_iType = type;
}

int AbstractExpression::GetType()
{
	return m_iType;
}

string AbstractExpression::GetIdentifier()
{
	return m_wsIdentifier;
}

bool AbstractExpression::GetBoolean()
{
	return m_bBoolean;
}

long AbstractExpression::GetNumber()
{
	return m_lNumber;
}
