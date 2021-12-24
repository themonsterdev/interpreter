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
	 * Optenir la valeur de la variable spécifié.
	 * 
	 * @param variable Nom de la variable.
	 * @return void
	 */
	long GetValue(string variable);

	/**
	 * Ajoutée une valeur pour la variable spécifié.
	 *
	 * @param variable Nom de la variable.
	 * @param value valeur de la variable.
	 * @return void
	 */
	long SetValue(string variable, long value);

private:

	typedef map<std::string, long> VarMap;
	VarMap m_symbols;
};

#endif
