#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Context.h"
#include "Token.h"

#include <memory>
#include <vector>

using namespace std;

/**
 * Classe Expression
 * 
 * @see https://en.wikipedia.org/wiki/Expression_(computer_science)
 * @see https://fr.wikipedia.org/wiki/Expression_(informatique)
 */
class Expression
{
public:

	/**
	 * Pointeur d'expression intelligent.
	 *
	 * @return shared_ptr<Expression>
	 */
	typedef shared_ptr<Expression> Pointer;

	/**
	 * La listes de pointeur d'expression.
	 *
	 * @return vector<Pointer>
	 */
	typedef vector<Pointer> ExpressionList;

	/**
	 * Crée un pointeur d'expression avec l'itération de token spécifié.
	 *
	 * @param  begin   L'itérateur pointant sur le premier élément de la séquence tokens.
	 * @param  end	   L'itérateur pointant sur l'élément le plus ancien de la séquence tokens.
	 * @return Pointer Le pointeur d'expression intelligent.
	 */
	static Pointer Parse( TokenIt& begin, TokenIt& end );

	/**
	 * Déstruction de l'instance Expression.
	 */
	virtual ~Expression() = default;

	/**
	 * Evalue l'expression enregistrée.
	 *
	 * @param  context La référence du context actuel.
	 * @return long
	 */
	virtual long Evaluate( Context& context ) = 0;

private:

	static Pointer ParseExpressionFromNumber( TokenIt& begin, TokenIt& end );
	static Pointer ParseExpressionFromIdentifier( TokenIt& begin, TokenIt& end );
	static Pointer ParseExpressionFromOperator( Pointer leftExpression, TokenIt& begin, TokenIt& end );
};

#endif
