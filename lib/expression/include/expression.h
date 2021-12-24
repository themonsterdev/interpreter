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
	 * @param  it L'itération de token.
	 * @return Pointer
	 */
	static Pointer Parse(TokenIt& it);

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

	static Pointer ParseExpressionFromNumber(TokenIt& it);
	static Pointer ParseExpressionFromIdentifier(TokenIt& it);
};

#endif
