#include "Parser/Parser.h"

// Statement
#include "Parser/Statement/PrintingStatement.h"
#include "Parser/Statement/VariableStatement.h"

// Expression
#include "Parser/Expression/NumberExpression.h"
#include "Parser/Expression/IdentifierExpression.h"

// Expression Operator Arithmetic
#include "Parser/Expression/Operator/Arithmetic/AdditionExpression.h"
#include "Parser/Expression/Operator/Arithmetic/DivisionExpression.h"
#include "Parser/Expression/Operator/Arithmetic/ModuloExpression.h"
#include "Parser/Expression/Operator/Arithmetic/MultiplicationExpression.h"
#include "Parser/Expression/Operator/Arithmetic/SubtractionExpression.h"

StatementInterface::Pointer Parser::GetStatement(Token::Iterator& begin, Token::Iterator& end)
{
	assert(begin != end);											// Vérifie qu'un jeton est bien présent.

	switch (begin->GetType())										// Switch sur le type du jeton.
	{
	case (int)Token::Type::KEYWORD:									// Le jeton est de type chaine de caractères.
		{
			string wsTokenValue = begin->GetWordValue();
			if (wsTokenValue == "print")							// Si le mot clès est égale à `print`.
				return make_shared<PrintingStatement>(begin, end);	// Crée un pointeur de déclaration `print`.
			else if (wsTokenValue == "var")							// Si le mot clès est égale à `var`.
				return make_shared<VariableStatement>(begin, end);	// Crée un pointeur de déclaration `var`.
		}
		break;

	case (int)Token::Type::IDENTIFIER:							// Le jeton est de type chaine de caractères.
		return make_shared<VariableStatement>(begin, end);		// Crée un pointeur de déclaration `print`.
		break;
	}

	// Sinon retourne une erreur.
	string error("Unexpected: ");
	error += to_string(begin->GetType());
	throw exception(error.c_str());
}

ExpressionInterface::Pointer Parser::GetLiteralExpression(Token::Iterator& begin, Token::Iterator& end)
{
	if (begin != end)																// Si un jeton est présent.
	{
		ExpressionInterface::Pointer pExpression;									// Définie un pointeur d'expression.

		switch (begin->GetType())													// Switch sur le type de l'expression.
		{
		case (int)Token::Type::NUMBER:												// Se jeton est de type nombre litéral
			pExpression = Parser::GetLiteralNumberExpression(begin, end);			// Crée l'expression d'un nombre.
			break;

		case (int)Token::Type::IDENTIFIER:											// Le jeton est de type chaine de caractères.
			return make_shared<IdentifierExpression>(begin, end);					// Crée un pointeur d'expression `identifier`.
			break;

		default:																	// Si aucune expressions à correspondu.
			pExpression = nullptr;													// Définie le pointeur d'expression null.
			break;
		}

		return pExpression;															// Retourne le pointeur de l'expression.
	}

	return nullptr;
}

ExpressionInterface::Pointer Parser::GetLiteralNumberExpression(Token::Iterator& begin, Token::Iterator& end)
{
	assert(begin != end);																	// Vérifie qu'un jeton est bien présent.
	assert(begin->HasType((int)Token::Type::NUMBER));										// Vérifie que le jeton est bien un nombre.

	ExpressionInterface::Pointer pExpression = make_shared<NumberExpression>(begin, end);	// Définie un pointeur d'expression.
	assert(pExpression != nullptr);															// Vérifie que l'expression à bien était crée.

	return Parser::GetOperatorExpression(pExpression, begin, end);							// Retourne le pointeur de l'expression.
}

ExpressionInterface::Pointer Parser::GetOperatorExpression(ExpressionInterface::Pointer operand1, Token::Iterator& begin, Token::Iterator& end)
{
	if (begin != end)																	// Si un jeton est encore présent.
	{
		ExpressionInterface::Pointer pExpression;										// Définie un pointeur d'expression.

		switch (begin->GetType())														// Switch sur le type du jeton.
		{
		case (int)'+':																	// Si le jeton est de type '='.
			pExpression = make_shared<AdditionExpression>(operand1, begin, end);		// Définie un pointeur d'expression.
			assert(pExpression != nullptr);												// Vérifie que le pointeur n'est pas null.
			break;

		case (int)'/':																	// Si le jeton est de type '/'.
			pExpression = make_shared<DivisionExpression>(operand1, begin, end);		// Définie un pointeur d'expression.
			assert(pExpression != nullptr);												// Vérifie que le pointeur n'est pas null.
			break;

		case (int)'%':																	// Si le jeton est de type '%'.
			pExpression = make_shared<ModuloExpression>(operand1, begin, end);			// Définie un pointeur d'expression.
			assert(pExpression != nullptr);												// Vérifie que le pointeur n'est pas null.
			break;

		case (int)'*':																	// Si le jeton est de type '*'.
			pExpression = make_shared<MultiplicationExpression>(operand1, begin, end);	// Définie un pointeur d'expression.
			assert(pExpression != nullptr);												// Vérifie que le pointeur n'est pas null.
			break;

		case (int)'-':																	// Si le jeton est de type '-'.
			pExpression = make_shared<SubtractionExpression>(operand1, begin, end);		// Définie un pointeur d'expression.
			assert(pExpression != nullptr);												// Vérifie que le pointeur n'est pas null.
			break;

		default:																		// Si le jeton est pas une opération.
			pExpression = nullptr;														// Définie le pointeur null.
			break;
		}

		if (pExpression != nullptr)														// Si l'expression d'une opération à était créer.
			return Parser::GetOperatorExpression(pExpression, begin, end);				// Retourne une nouvelle opération sinon la courante.
	}

	return operand1;																	// Retourne le pointeur de l'expression courante.
}

// Parser

StatementInterface::Queue Parser::Parse(Token::List& tokens)
{
	StatementInterface::Queue statements;				// Définie une liste de déclaration.
	StatementInterface::Pointer pStatement;				// Définie un pointeur de déclaration.

	Token::Iterator begin = tokens.begin();				// Définie le premier jeton.
	Token::Iterator end = tokens.end();					// Définie la fin de l'itération.

	while (begin != end)								// Tant qu'un jeton est présent.
	{
		pStatement = Parser::GetStatement(begin, end);	// Définie le pointeur de déclaration pour se jeton.
		assert(pStatement != nullptr);					// Vérifie que la d'éclaration n'est pas null.
		statements.push(pStatement);					// Ajoute la déclaration à la liste.
	}

	return statements;									// Retourne la liste de déclarations.
}
