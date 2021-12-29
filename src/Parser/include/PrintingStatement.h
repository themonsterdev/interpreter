#ifndef PRINTING_STATEMENT_H
#define PRINTING_STATEMENT_H

#include "Interface/StatementInterface.h"
#include "Token.h"

class PrintingStatement : public StatementInterface
{
public:

	PrintingStatement(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context* context);
};

#endif
