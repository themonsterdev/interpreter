#ifndef STATEMENT_H
#define STATEMENT_H

#include <memory>
#include <vector>

#include "Context.h"
#include "Token.h"

using namespace std;

/**
 * Classe Statement
 * 
 * Cette classe permet d'indiquer à l'intérpéteur l'existence d'une entité informatique (Variable, Routine, Ect).
 * 
 * Il est nécessaire de déclarer les entités informatiques avant de pouvoir les utiliser.
 * 
 * @see https://fr.wikipedia.org/wiki/D%C3%A9claration_(informatique)
 * @see https://en.wikipedia.org/wiki/Statement_(computer_science)
 */
class Statement
{
public:

	/**
	 * Pointeur de déclaration intelligent.
	 * 
	 * @return shared_ptr<Statement>
	 */
	typedef shared_ptr<Statement> Pointer;

	/**
	 * La listes de pointeur de déclaration.
	 *
	 * @return vector<Pointer>
	 */
	typedef vector<Pointer> StatementList;

	/**
	 * Crée une nouvelle instance de déclaration.
	 *
	 * @param  context	La référence du context actuel.
	 * @param  it		L'itération de token.
	 * @return Pointer	Le pointeur de la nouvelle déclaration.
	 */
	static Pointer Create( Context& context, TokenIt& it );

	/**
	 * Déstruction de l'instance Statement.
	 */
	virtual ~Statement() = default;

	/**
	 * Exécute les instructions déclarer.
	 *
	 * @param  context	La référence du context actuel.
	 * @return void
	 */
	virtual void Execute( Context& context ) = 0;

private:

	static Pointer CreateKeywordStatement( Context& context, TokenIt& it );
};

#endif
