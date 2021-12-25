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
	 * Pointeur Statement intelligent.
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
	 * @param  begin    L'itérateur pointant sur le premier élément de la séquence tokens.
	 * @param  end	    L'itérateur pointant sur l'élément le plus ancien de la séquence tokens.
	 * @return Pointer	Le pointeur Statement intelligent.
	 */
	static Pointer Create( Context& context, TokenIt& begin, TokenIt& end );

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

	static Pointer CreateKeywordStatement( Context& context, TokenIt& begin, TokenIt& end );
};

#endif
