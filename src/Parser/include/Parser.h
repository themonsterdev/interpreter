#ifndef PARSER_H
#define PARSER_H

#include "Interface/StatementInterface.h"
#include "Token.h"

#include <memory>
#include <stack>
#include <list>

using namespace std;

/**
 * Classe Parser
 * 
 * Cette classe permet de faire une analyse syntaxique.
 * 
 * @see https://fr.wikipedia.org/wiki/Analyse_syntaxique
 */
class Parser
{
public:

	typedef shared_ptr<StatementInterface>	Statement;
	typedef stack<Statement>				StatementList;

	StatementList Parse(Token::List& tokens);

private:

	StatementList m_statements;
};

#endif
