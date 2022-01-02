#ifndef VARIABLE_STATEMENT_H
#define VARIABLE_STATEMENT_H

#include "Parser/Statement/AbstractStatement.h"
#include "Parser/Expression/Interface/ExpressionInterface.h"

#include "Parser/Parser.h"
#include "Tokenizer/Token.h"

class VariableStatement : public AbstractStatement
{
public:

	VariableStatement(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context& context);

private:

	string m_name;

	ExpressionInterface::Pointer m_expression;
};

#endif
