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

	long GetValue(string variable);
	long SetValue(string variable, long value);

private:

	typedef map<std::string, long> VarMap;
	VarMap m_symbols;
};

#endif
