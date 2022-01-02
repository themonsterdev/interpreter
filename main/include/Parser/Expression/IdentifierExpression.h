#ifndef VARIABLE_EXPRESSION_H
#define VARIABLE_EXPRESSION_H

#include "Parser/Expression/AbstractExpression.h"
#include "Parser/Parser.h"
#include "Tokenizer/Token.h"

/**
 * Interface IdentifierExpression
 * 
 * @see https://fr.wikipedia.org/wiki/Expression_(informatique)
 */
class IdentifierExpression : public AbstractExpression
{
public:

	IdentifierExpression(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context& context);
};

#endif
