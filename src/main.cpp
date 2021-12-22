#include <iostream>

// Tokenizer
#include "tokenizer.h"
#include "token.h"

#include "statement.h"

int main()
{
    try
    {
        string characters(
            "var identifier = 1 + 1\nprint identifier"
        );
        Tokenizer tokenizer( characters );
        TokenList tokens = tokenizer.getTokens();
        Tokenizer::printTokens(tokens);

        // StatementList statements;
        // for (
        //     TokenList::iterator it = tokens.begin();
        //     it != tokens.end();
        //     ++it
        // ) {
        //     statements.push_back(
        //         StatementPtr(Statement::create(it))
        //     );
        // }
    }
    catch ( exception e )
    {
        cout << e.what() << endl;
    }

    return 0;
}
