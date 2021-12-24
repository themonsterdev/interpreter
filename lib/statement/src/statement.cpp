#include "Statement.h"
#include "VariableStatement.h"
#include "AssignmentStatement.h"
#include "PrintStatement.h"

// Utilisez la fonction make_shared lorsque cela est possible.

Statement::Pointer Statement::Create( Context& context, TokenIt& it )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	switch (tokenType)
	{
	case Token::Type::Keyword:
		return Statement::CreateKeywordStatement( context, it );

	case Token::Type::Identifier:
		return make_shared<AssignmentStatement>( context, it );

	case Token::Type::Operator:
		break;

	case Token::Type::Number:
		break;
	}

	throw exception(
		( string("Erreur: Déclaration inattendue, " ) + Token::GetStringType( tokenType ) + " " + tokenData ).c_str()
	);
}

Statement::Pointer Statement::CreateKeywordStatement( Context& context, TokenIt& it )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	if ( tokenData == "var" )
	{
		return make_shared<VariableStatement>( context, it );
	}
	else if ( tokenData == "print" )
	{
		return make_shared<PrintStatement>( it );
	}
	else
	{
		throw exception(
			( string("Erreur: Déclaration keyword inattendue, " ) + Token::GetStringType( tokenType ) + " " + tokenData ).c_str()
		);
	}
}
