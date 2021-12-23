#ifndef STATEMENT_H
#define STATEMENT_H

#include <thread>
#include <list>

#include "Token.h"
#include "Context.h"

using namespace std;

/**
 * Classe Statement
 */
class Statement
{
public:

	static Statement* create( Context& context, TokenIt& it );

	virtual void Execute( Context& context ) = 0;

	virtual ~Statement() {};
};

typedef shared_ptr<Statement> StatementPtr;
typedef list<StatementPtr> StatementList;

#endif
