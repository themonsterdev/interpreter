#ifndef STATEMENT_INTERFACE_H
#define STATEMENT_INTERFACE_H

#include "Context.h"

/**
 * Interface StatementInterface
 * 
 * @see https://www.w3schools.com/js/js_if_else.asp
 */
class StatementInterface
{
public:

	typedef shared_ptr<StatementInterface>	Pointer;	// Définie un type de pointeur de déclaration.
	typedef queue<Pointer>					Queue;		// Définie un type de fil d'attente de déclarations.

	virtual ~StatementInterface() = default;

	virtual void Interpret(Context& context) = 0;
};

#endif
