#include "Context.h"

long Context::GetValue(string variable)
{
	long nResult;
	VariableMap::iterator it = this->m_variables.find(variable);

	if (it != this->m_variables.end())
		nResult = it->second;
	else
	{
		nResult = -1; // Valeur par défaut pour la variable si elle est déclaré mes non défini
		this->SetValue(variable, nResult);
	}

	return nResult;
}

void Context::SetValue(string variable, long value)
{
	this->m_variables[variable] = value;
}
