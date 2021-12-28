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
 * # Déclaration et définition
 * 
 * Il faut bien différencier la déclaration et la définition.
 * 
 * - La déclaration ne fait qu'indiquer l'existence d'une entité informatique sans la créer
 * - La définition l'instancie, c'est-à-dire qu'elle la crée.
 * 
 * Par exemple, l'implémentation d'une routine est sa définition.
 * 
 * #        |  Déclaration                                           | Définition
 * -------- | ------------------------------------------------------ | --------------------------------------------
 * Variable | \code{.lsp} extern int Var; \endcode                   | \code{.lsp} int Var; \endcode
 * Fonction | \code{.lsp} int Somme ( int Var1, int Var2 ); \endcode | \code{.lsp} int Somme ( int Var1, int Var2 ) { return Var1 + Var2; } \endcode
 * 
 * Dans certains langages de programmation, tel que le langage C/C++, la définition inclut la
 * déclaration, ce qui signifie que la présence de la définition dans une unité (module) d'un
 * programme permet d'y omettre la déclaration.
 * 
 * # Précision du type de l'entité informatique dans la déclaration
 * 
 * Une déclaration (et par conséquent une définition) comporte souvent un type ; c'est le type
 * retourné par l'entité informatique. Voici par exemple la définition d'un entier, valable dans
 * plusieurs langages de programmation :
 * 
 * \code{.lsp}
 * int i;
 * \endcode
 * 
 * Dans d'autres langages, le type n'a pas besoin d'être précisé ; il sera déterminé en fonction
 * de l'initialiseur de la variable. Par exemple, avec C++1x, cette instruction définit une variable
 * de type caractère :
 * 
 * \code{.lsp}
 * auto c = '.';
 * \endcode
 * 
 * Ce concept s'appelle l'inférence de types.
 * 
 * # Liste de déclarations
 * 
 * Il est souvent possible de déclarer plusieurs variables en une seule instruction. Par exemple, en langage C :
 * 
 * \code{.lsp}
 * int i, j;
 * \endcode
 * 
 * Leur type doit alors être commun (ici entier).
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
	static Pointer Create( Context& context, Token::Iterator& begin, Token::Iterator& end );

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

	static Pointer CreateKeywordStatement( Context& context, Token::Iterator& begin, Token::Iterator& end );
};

#endif
