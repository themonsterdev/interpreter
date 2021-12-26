#include <iostream>
#include <fstream>
#include <sstream>

// Tokenizer
#include "Tokenizer.h"
#include "Token.h"

#include "Statement.h"

string GetStringFromFile(const char* filepath)
{
    ifstream is(filepath); // open file
    string programText;

    if (is)
    {
        char c;
        while (is.get(c)) // loop getting single characters
            programText += c;

        is.close(); // close file
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier " << filepath << endl;
    }

    return programText;
}

TokenList GetToken(const char* filepath)
{
    string programText(GetStringFromFile(filepath));
    Tokenizer tokenizer(programText);
    TokenList tokens = tokenizer.GetTokens();
    // Tokenizer::PrintTokens( tokens );
    return tokens;
}

Statement::StatementList GetStatements( Context& context, TokenList tokens )
{
    Statement::StatementList statements;
    Statement::Pointer pStatement;

    TokenIt itEnd = tokens.end();

    for (
        TokenIt it = tokens.begin();
        it != itEnd;
        ++it
    ) {
        pStatement = Statement::Create(context, it, itEnd);

        if (pStatement != nullptr && pStatement.get() != nullptr)
        {
            statements.push_back(pStatement);
        }
    }

    return statements;
}

void Execute( Context& context, Statement::StatementList statements )
{
    Statement::StatementList::iterator itEnd = statements.end();

    for (
        Statement::StatementList::iterator it = statements.begin();
        it != itEnd;
        ++it
    ) {
        it->get()->Execute(context);
    }
}

void printCommandOptions()
{
    cout << "Usage: Interprèteur [Options]" << endl << endl;

    cout << "Options:" << endl;
    cout << '\t' << "-f, --file <fichier.lsp>" << '\t' << "Analyse et exécution le <fichier>." << endl;
    cout << '\t' << "-h, --help          " << '\t' << "Afficher l'aide pour la commande." << endl;
}

int main(const int argc, const char* argv[])
{
    if (argc == 2)
    {
        string option(argv[1]);

        if (option == "-f" || option == "--file")
        {
            cout << "Usage: File <fichier>" << endl;
            return EXIT_FAILURE;
        }
        else if (option == "-h" || option == "--help")
        {
            printCommandOptions();
            return EXIT_SUCCESS;
        }
    }
    else if (argc == 3)
    {
        string option(argv[1]);

        if (option == "-f" || option == "--file")
        {
            try
            {
                string filename(argv[2]);

                TokenList tokens = GetToken(filename.c_str());

                Context context;
                Statement::StatementList statements = GetStatements(context, tokens);

                Execute(context, statements);
            }
            catch (exception e)
            {
                cout << "\x1B[91mErreur: " << e.what() << "\033[0m" << endl;
            }

            return EXIT_SUCCESS;
        }
    }

    printCommandOptions();
    return EXIT_FAILURE;
}
