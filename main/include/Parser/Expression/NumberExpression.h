#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "Parser/Expression/AbstractExpression.h"
#include "Parser/Expression/Operator/OperatorExpression.h"
#include "Parser/Parser.h"
#include "Tokenizer/Token.h"

/**
 * Interface NumberExpression
 * 
 * @see https://fr.wikipedia.org/wiki/Expression_(informatique)
 */
class NumberExpression : public AbstractExpression
{
public:

	NumberExpression(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context& context);
};

#endif
