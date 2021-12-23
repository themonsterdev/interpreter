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

	long getValue(string variable);
	long setValue(string variable, long value);

private:

	typedef map<std::string, long> VarMap;
	VarMap m_symbols;
};

#endif
