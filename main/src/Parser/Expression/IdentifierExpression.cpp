#include "Parser/Expression/IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(Token::Iterator& begin, Token::Iterator& end)
	: ::AbstractExpression()
{
	assert(begin != end);
	assert(begin->HasType((int)Token::Type::IDENTIFIER));

	m_wsIdentifier = begin->GetWordValue();
	SetType((int)Type::IDENTIFIER);
	begin++;
}

void IdentifierExpression::Interpret(Context& context)
{
	map<string, long>::iterator it = context.m_lVariables.find(m_wsIdentifier);
	assert(it != context.m_lVariables.end());
	context.m_lValues.push(it->second);
}
