#include "Statement.h"
#include "VariableStatement.h"
#include "PrintStatement.h"

Statement::Pointer Statement::Create( Context& context, Token::Iterator& begin, Token::Iterator& end )
{
	if (begin == end)
	{
		throw exception(
			string("Erreur: Déclaration null").c_str()
		);
	}

	Token::Type tokenType = begin->GetType();
	string tokenData = begin->GetData();

	switch (tokenType)
	{
	case Token::Type::Keyword:
		return Statement::CreateKeywordStatement( context, begin, end );

	case Token::Type::Identifier:
		return make_shared<VariableStatement>( context, begin, end );

	default:
		throw exception(
			(string("Erreur: Déclaration inattendue, ") + Token::GetStringType(tokenType) + " " + tokenData).c_str()
		);
	}
}

Statement::Pointer Statement::CreateKeywordStatement( Context& context, Token::Iterator& begin, Token::Iterator& end )
{
	Token::Type tokenType = begin->GetType();
	string tokenData = begin->GetData();

	if ( tokenData == "var" )
	{
		return make_shared<VariableStatement>( context, begin, end );
	}
	else if ( tokenData == "print" )
	{
		return make_shared<PrintStatement>( begin, end );
	}
	else
	{
		throw exception(
			( string("Erreur: Déclaration keyword inattendue, " ) + Token::GetStringType( tokenType ) + " " + tokenData ).c_str()
		);
	}
}
