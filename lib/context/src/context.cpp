#include "Context.h"

long Context::GetValue(string variable)
{
	long nResult;
	VarMap::iterator it = this->m_symbols.find(variable);
	if (it == this->m_symbols.end())
		nResult = this->SetValue(variable, 0);
	else
		nResult = it->second;

	return nResult;
}

long Context::SetValue(string variable, long value)
{
	return this->m_symbols[variable] = value;
}
