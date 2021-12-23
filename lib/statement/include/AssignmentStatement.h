#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

class AssignmentStatement : public Statement
{
public:

	AssignmentStatement(Context& context, TokenIt& it);

	virtual void Execute(Context& context);

private:

	string m_variable;

	Expression::ExprPtr m_expression;
};

#endif
