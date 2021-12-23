#include <iostream>
#include <fstream>
#include <sstream>

// Tokenizer
#include "Tokenizer.h"
#include "Token.h"

#include "Statement.h"

string GetStringFromFile(const char* filepath)
{
    string programText;
    ifstream is(filepath);
    // cout << filepath << endl;

    if (is)
    {
        while (!is.eof())
        {
            char c;
            is.get(c);
            programText += c;
        }
    }
    else
    {
        cout << "Could not open file " << filepath << endl;
    }

    return programText;
}

TokenList GetToken(const char* filepath)
{
    string programText = GetStringFromFile(filepath);
    Tokenizer tokenizer(programText);
    TokenList tokens = tokenizer.GetTokens();
    // Tokenizer::PrintTokens( tokens );
    return tokens;
}

StatementList GetStatements( Context& context, TokenList tokens )
{
    StatementList statements;
    Statement* pStatement;

    for (
        TokenList::iterator it = tokens.begin();
        it != tokens.end();
        ++it
    ) {
        pStatement = Statement::create( context, it );
        if ( pStatement != nullptr )
        {
            statements.push_back( StatementPtr( pStatement ) );
        }
    }
    return statements;
}

void Execute( Context& context, StatementList statements )
{
    StatementList::iterator itEnd = statements.end();

    for (
        StatementList::iterator it = statements.begin();
        it != itEnd;
        ++it
    ) {
        it->get()->Execute(context);
    }
}

int main(const int argc, const char* argv[])
{
    if (argc == 1)
    {
        cout << "Usage: Interpreter" << endl;
        return 1;
    }

    try
    {
        TokenList tokens = GetToken( argv[1] );

        Context context;
        StatementList statements = GetStatements( context, tokens );
        Execute( context, statements );
    }
    catch ( exception e )
    {
        cout << e.what() << endl;
    }

    return 0;
}
