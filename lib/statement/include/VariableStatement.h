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
	 * @param  begin    L'itérateur pointant sur le premier élément de la séquence tokens.
	 * @param  end	    L'itérateur pointant sur l'élément le plus ancien de la séquence tokens.
	 */
	VariableStatement(Context& context, Token::Iterator& begin, Token::Iterator& end );

	virtual void Execute(Context& context);

private:

	string m_name;

	Expression::Pointer m_expression;
};

#endif
