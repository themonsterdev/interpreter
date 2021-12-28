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
	 * @param  begin    L'itérateur pointant sur le premier élément de la séquence tokens.
	 * @param  end	    L'itérateur pointant sur l'élément le plus ancien de la séquence tokens.
	 */
	PrintStatement( Token::Iterator& begin, Token::Iterator& end );

	virtual void Execute(Context& context);

private:

	Expression::Pointer m_expression;
};

#endif
