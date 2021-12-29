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

	~StatementInterface() = default;

	virtual void Interpret(Context* context) = 0;
};

#endif
