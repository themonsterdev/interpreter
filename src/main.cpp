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

StatementList GetStatements( TokenList tokens )
{
    StatementList statements;

    for (
        TokenList::iterator it = tokens.begin();
        it != tokens.end();
        ++it
    ) {
        statements.push_back(
            StatementPtr( Statement::create(it) )
        );
    }
    return statements;
}

void Execute(StatementList statements)
{
    Context context;

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
        StatementList statements = GetStatements( tokens );
        Execute( statements );
    }
    catch ( exception e )
    {
        cout << e.what() << endl;
    }

    return 0;
}
