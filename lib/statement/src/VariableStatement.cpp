#include "VariableStatement.h"

VariableStatement::VariableStatement(Context& context, Token::Iterator& begin, Token::Iterator& end )
	: m_expression(nullptr)
{
	Token::Type tokenType = begin->GetType();
	string tokenData = begin->GetData();

	if (tokenType == Token::Type::Keyword)
	{
		// Expect
		if (tokenData != "var")
		{
			throw exception("Erreur: Le jeton attendu doit être un 'var' ");
		}

		begin++;
		if (begin->GetType() != Token::Type::Identifier)
		{
			throw exception(
				(string("Erreur de syntaxe, token '") + tokenData + "' inattendu").c_str()
			);
		}

		tokenData = begin->GetData();
		if (context.GetValue(tokenData) != -1)
		{
			throw exception(
				(string("Erreur: Redéfinition de la variable ") + tokenData).c_str()
			);
		}

		m_name = begin->GetData();
		context.SetValue(m_name, 0);

		begin++;
		if (begin->GetType() != Token::Type::Operator || begin->GetData() != "=")
		{
			throw exception(
				(string("Erreur: l'expression attendu était un `=`")).c_str()
			);
		}

		begin++;
		m_expression = Expression::Parse(begin, end);
	}
	else if (tokenType == Token::Type::Identifier)
	{
		long identifierValue = context.GetValue(tokenData);
		if (identifierValue == -1)
		{
			throw exception(
				(string("Erreur: variable ") + tokenData + " indéfinit").c_str()
			);
		}

		m_name = begin->GetData();
		context.SetValue(m_name, 0);

		begin++;
		if (begin->GetType() != Token::Type::Operator || begin->GetData() != "=")
		{
			begin--;
			return;
		}

		begin++;
		m_expression = Expression::Parse(begin, end);
	}
}

void VariableStatement::Execute(Context& context)
{
	context.SetValue(m_name, m_expression ? m_expression->Evaluate(context) : 0);
}
