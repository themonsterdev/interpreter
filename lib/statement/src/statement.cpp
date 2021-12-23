#include "Statement.h"
#include "AssignmentStatement.h"
#include "PrintStatement.h"

Statement* Statement::create( Context& context, TokenIt& it )
{
	Token::Type tokenType = it->GetType();
	string tokenData = it->GetData();

	switch (tokenType)
	{
	case Token::Type::Keyword:
		{
			if ( tokenData == "var" )
			{
				return new AssignmentStatement( context, it );
			}
			else if ( tokenData == "print" )
			{
				return new PrintStatement( it );
			}
		}
		break;

	case Token::Type::Identifier:
		return new AssignmentStatement(context, it);
		break;

	case Token::Type::Operator:
		break;

	case Token::Type::Number:
		break;
	}

	throw exception(
		(string("Erreur: Déclaration inattendue, ") + Token::GetStringType(tokenType) + " " + tokenData).c_str()
	);
}
