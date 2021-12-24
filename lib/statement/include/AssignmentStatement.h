#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

/**
 * Classe AssignmentStatement
 *
 * Cette classe est utilisée pour assigner une variable.
 */
class AssignmentStatement : public Statement
{
public:

	/**
	 * Constructeur de l'instance AssignmentStatement.
	 * 
	 * @param context	La référence du context actuel.
	 * @param it		L'itération de token.
	 */
	AssignmentStatement(Context& context, TokenIt& it);

	virtual void Execute(Context& context);

private:

	string m_variable;

	Expression::Pointer m_expression;
};

#endif
