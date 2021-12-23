#include <iostream>
#include <fstream>
#include <sstream>

// Tokenizer
#include "Tokenizer.h"
#include "Token.h"

#include "Statement.h"

string getStringFromFile(const char* filepath)
{
    string programText;
    ifstream is(filepath);
    cout << filepath << endl;

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

TokenList getToken(const char* filepath)
{
    string programText = getStringFromFile(filepath);
    Tokenizer tokenizer(programText);
    TokenList tokens = tokenizer.getTokens();
    // Tokenizer::printTokens( tokens );
    return tokens;
}

StatementList getStatements( TokenList tokens )
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

int main(const int argc, const char* argv[])
{
    if (argc == 1)
    {
        cout << "Usage: Interpreter" << endl;
        return 1;
    }

    try
    {
        TokenList tokens = getToken(argv[1]);
        StatementList statements = getStatements( tokens );

        Context context;

        for (
            StatementList::iterator it = statements.begin();
            it != statements.end();
            ++it
        ) {
            it->get()->execute(context);
        }
    }
    catch ( exception e )
    {
        cout << e.what() << endl;
    }

    return 0;
}
