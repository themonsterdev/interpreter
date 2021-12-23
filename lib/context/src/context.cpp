#include "context.h"

long Context::getValue(string variable)
{
	long nResult;
	VarMap::iterator it = m_symbols.find(variable);
	if (it == m_symbols.end())
		nResult = this->setValue(variable, 0);
	else
		nResult = it->second;

	return nResult;
}

long Context::setValue(string variable, long value)
{
	return m_symbols[variable] = value;
}
