#include "VariableStatement.h"

VariableStatement::VariableStatement(Context& context, TokenIt& it)
	: m_expression(nullptr)
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	if (tokenType == Token::Type::Keyword)
	{
		// Expect
		if (tokenData != "var")
		{
			throw exception("Erreur: Le jeton attendu doit être un 'var' ");
		}

		it++;
		if (it->GetType() != Token::Type::Identifier)
		{
			throw exception(
				(string("Erreur de syntaxe, token '") + tokenData + "' inattendu").c_str()
			);
		}

		tokenData = it->GetData();
		if (context.GetValue(tokenData) != -1)
		{
			throw exception(
				(string("Erreur: Redéfinition de la variable ") + tokenData).c_str()
			);
		}

		m_name = it->GetData();
		context.SetValue(m_name, 0);

		it++;
		if (it->GetType() != Token::Type::Operator || it->GetData() != "=")
		{
			it--;
			return;
		}

		it++;
		m_expression = Expression::Parse(it);
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

		m_name = it->GetData();
		context.SetValue(m_name, 0);

		it++;
		if (it->GetType() != Token::Type::Operator || it->GetData() != "=")
		{
			it--;
			return;
		}

		it++;
		m_expression = Expression::Parse(it);
	}
}

void VariableStatement::Execute(Context& context)
{
	context.SetValue(m_name, m_expression ? m_expression->Evaluate(context) : 0);
}
