#ifndef STATEMENT_H
#define STATEMENT_H

#include <thread>
#include <list>

#include "Token.h"
#include "Context.h"
#include "Expression.h"

using namespace std;

/**
 * Classe Statement
 */
class Statement
{
public:

	static Statement* create(TokenIt& it);

	virtual void Execute(Context& context) = 0;

	virtual ~Statement() {};
};

class AssignmentStatement : public Statement
{
public:
	AssignmentStatement(TokenIt& it);

	virtual void Execute(Context& context);

private:

	string m_variable;

	Expression::ExprPtr m_expression;
};

class PrintStatement : public Statement
{
public:

	PrintStatement(TokenIt& it);
	virtual void Execute(Context& context);

private:

	Expression::ExprPtr m_expression;
};

typedef shared_ptr<Statement> StatementPtr;
typedef list<StatementPtr> StatementList;

#endif
