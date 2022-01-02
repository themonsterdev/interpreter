#include "Parser/Statement/AbstractStatement.h"

void AbstractStatement::Expect(Token& token, Token::Type typeExpected)
{
	assert(token.HasType((int)typeExpected));
}
