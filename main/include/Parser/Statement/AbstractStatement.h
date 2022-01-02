#ifndef ABSTRACT_STATEMENT_H
#define ABSTRACT_STATEMENT_H

#include "Interface/StatementInterface.h"
#include "Tokenizer/Token.h"

/**
 * Classe AbstractStatement
 */
class AbstractStatement : public StatementInterface
{
protected:

	static void Expect(Token& token, Token::Type typeExpected);
};

#endif
