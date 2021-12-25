#ifndef VARIABLE_STATEMENT_H
#define VARIABLE_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

/**
 * Classe VariableStatement
 *
 * Cette classe est utilisée pour assigner une variable.
 */
class VariableStatement : public Statement
{
public:

	/**
	 * Constructeur de l'instance VariableStatement.
	 * 
	 * @param context	La référence du context actuel.
	 * @param it		L'itération de token.
	 */
	VariableStatement(Context& context, TokenIt& begin, TokenIt& end);

	virtual void Execute(Context& context);

private:

	string m_name;

	Expression::Pointer m_expression;
};

#endif
