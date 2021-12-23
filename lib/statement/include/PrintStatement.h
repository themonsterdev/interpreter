#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

class PrintStatement : public Statement
{
public:

	PrintStatement(TokenIt& it);
	virtual void Execute(Context& context);

private:

	Expression::ExprPtr m_expression;
};

#endif
