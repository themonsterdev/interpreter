#include "Parser/Statement/VariableStatement.h"

VariableStatement::VariableStatement(Token::Iterator& begin, Token::Iterator& end)
{
	assert(begin != end);											// Vérifie qu'un jeton est présent.

	if (begin->HasType((int)Token::Type::KEYWORD) && begin->GetWordValue() == "var")
	{
		begin++;													// Passer au prochain jeton de l'itération.
		assert(begin != end);										// Vérifie qu'un jeton est présent.
	}

	assert(begin->HasType((int)Token::Type::IDENTIFIER));			// Vérifie que c'est bien une chaine de caractère.
	m_name = begin->GetWordValue();									// Enregistre le nom de la variable.

	if (begin != end)												// Vérifie qu'un jeton est disponible.
	{
		begin++;													// Passer au prochain jeton de l'itération.
		assert(begin->HasType((int)'='));							// Vérifie que le jeton est bien un caractère d'assignement `=`.

		assert(begin != end);										// Vérifie qu'un jeton est présent.
		begin++;													// Passer au prochain jeton de l'itération.
		m_expression = Parser::GetLiteralExpression(begin, end);	// Obtenir une expression du jeton, uniquement si un jeton est présent.
		assert(m_expression != nullptr);							// Vérifie que l'expression à bien était créer.
	}
	else
	{
		m_expression = nullptr;
	}
}

void VariableStatement::Interpret(Context& context)
{
	if (m_expression != nullptr)														// Si une expression d'assignement à était créer.
	{
		m_expression->Interpret(context);												// Interpète l'expression.

		switch (m_expression->GetType())												// Switch sur le type de l'expression.
		{
		case (int)ExpressionInterface::Type::NUMBER:									// Si l'expression est un nombre.
		case (int)ExpressionInterface::Type::IDENTIFIER:								// Si l'expression est un identifiant.
			context.m_lVariables[m_name] = m_expression->GetNumber();					// Assigner la variable.
			break;
		}
	}
}
