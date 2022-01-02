#include "Parser/Expression/NumberExpression.h"

NumberExpression::NumberExpression(Token::Iterator& begin, Token::Iterator& end)
	: ::AbstractExpression()
{
	assert(begin != end);									// Vérifie qu'un jeton est bien présent.
	assert(begin->HasType((int)Token::Type::NUMBER));		// Vérifie que le jeton à bien le type nombre.

	m_lNumber = (long)begin->GetNumberValue();				// Définie la valeur du nombre stocké dans le jeton.
	SetType((int)Type::NUMBER);								// Définie l'expression de type nombre.
	begin++;												// Passer au prochain jeton de l'itération.
}

void NumberExpression::Interpret(Context& context)
{
	context.m_lValues.push(m_lNumber);
}
