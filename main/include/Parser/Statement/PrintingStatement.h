#ifndef PRINTING_STATEMENT_H
#define PRINTING_STATEMENT_H

#include "Parser/Statement/AbstractStatement.h"
#include "Parser/Expression/Interface/ExpressionInterface.h"
#include "Tokenizer/Token.h"
#include "Parser/Parser.h"

class PrintingStatement : public AbstractStatement
{
public:

	PrintingStatement(Token::Iterator& begin, Token::Iterator& end);

	virtual void Interpret(Context& context);

private:

	ExpressionInterface::Pointer m_expression;
};

#endif
