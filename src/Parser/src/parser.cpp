#include "Parser.h"

// Statement
#include "PrintingStatement.h"
#include "VariableStatement.h"

#include <iostream>
#include <stack>

Parser::StatementList Parser::Parse(Token::List& tokens)
{
	StatementList statements;
	
	Token::Iterator end = tokens.end();

	for (Token::Iterator begin = tokens.begin(); begin != end; begin++)
	{
		switch (begin->type)
		{
		case (int)Token::Type::TT_WORD:
			if (begin->word == "print")
			{
				statements.push(make_shared<PrintingStatement>(begin, end));
			}
			else if (begin->word == "var")
			{
				cout << "Statement->Variable: " << begin->word << endl;
			}
			else
			{
				cout << "Expression->Identifier: " << begin->word << endl;
			}
			break;

		case (int)Token::Type::TT_NUMBER:
			cout << "Token->number: " << begin->number << endl;
			break;

		default:
			cout << "Token->character: " << begin->character << endl;
			break;
		}
	}

	return statements;
}
