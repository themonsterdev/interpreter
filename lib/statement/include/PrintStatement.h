#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

/**
 * Classe PrintStatement
 * 
 * Cette classe est utilisée pour imprimer un résultat dans la console.
 */
class PrintStatement : public Statement
{
public:

	/**
	 * Constructeur de l'instance PrintStatement.
	 * 
	 * @param it L'itération de token.
	 */
	PrintStatement(TokenIt& it);

	virtual void Execute(Context& context);

private:

	Expression::Pointer m_expression;
};

#endif
