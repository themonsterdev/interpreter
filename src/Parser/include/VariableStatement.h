#ifndef VARIABLE_STATEMENT_H
#define VARIABLE_STATEMENT_H

#include "Interface/StatementInterface.h"
#include "Token.h"

class VariableStatement : public StatementInterface
{
public:

	VariableStatement(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context* context);
};

#endif
