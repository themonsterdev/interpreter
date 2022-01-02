#ifndef PARSER_H
#define PARSER_H

#include "Statement/Interface/StatementInterface.h"
#include "Expression/Interface/ExpressionInterface.h"

#include "Tokenizer/Token.h"

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

	static StatementInterface::Pointer GetStatement(Token::Iterator& begin, Token::Iterator& end);

	static ExpressionInterface::Pointer GetLiteralExpression(Token::Iterator& begin, Token::Iterator& end);
	static ExpressionInterface::Pointer GetLiteralNumberExpression(Token::Iterator& begin, Token::Iterator& end);
	static ExpressionInterface::Pointer GetOperatorExpression(ExpressionInterface::Pointer operand1, Token::Iterator& begin, Token::Iterator& end);

	StatementInterface::Queue Parse(Token::List& tokens);

};

#endif
