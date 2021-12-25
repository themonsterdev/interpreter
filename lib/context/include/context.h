#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <map>

using namespace std;

/**
 * Classe Context
 */
class Context
{
public:

	/**
	 * Obtenir la valeur de la variable spécifiée.
	 * 
	 * @param variable Nom de la variable.
	 * @return long
	 */
	long GetValue(string variable);

	/**
	 * Ajout d'une valeur pour la variable spécifiée.
	 *
	 * @param variable Nom de la variable.
	 * @param value valeur de la variable.
	 * @return void
	 */
	void SetValue(string variable, long value);

private:

	typedef map<std::string, long> VariableMap;
	VariableMap m_variables;
};

#endif
