#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Context.h"
#include "Token.h"

#include <thread>
#include <list>

using namespace std;

/**
 * Classe Expression
 */
class Expression
{
public:

	typedef shared_ptr<Expression> ExprPtr;
	typedef list<ExprPtr> Exprs;
	typedef shared_ptr<Exprs> ExprsPtr;

	static ExprPtr parse(TokenIt& it);

	virtual ~Expression() {};

	virtual long evaluate(Context& context) = 0;
};

#endif
