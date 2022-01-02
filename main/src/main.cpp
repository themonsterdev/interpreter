#include "Client.h"

// Tokenizer
#include "Tokenizer/StreamTokenizer.h"
#include "Tokenizer/StringTokenizer.h"

int PrintingCommandHelp()
{
    cout << "Usage: Interprèteur [Options]" << endl << endl;

    cout << "Options:" << endl;
    cout << '\t' << "-t, --text <text>       " << '\t' << "Entreé du code." << endl;
    cout << '\t' << "-f, --file <fichier.lsp>" << '\t' << "Analyse et exécution le <fichier>." << endl;
    cout << '\t' << "-h, --help              " << '\t' << "Afficher l'aide pour la commande." << endl;
    cout << '\t' << "-v, --version           " << '\t' << "Numéro de version." << endl;

    return EXIT_SUCCESS;
}

int RunCodeCommand(AbstractTokenizer& tokenizer)
{
    tokenizer.Keywords({
        "print",
        "var"
    });

    Client client;
    client.Interpret(tokenizer);
    return EXIT_SUCCESS;
}

int StringCodeCommand(const char* expression)
{
    StringTokenizer tokenizer(expression);
    return RunCodeCommand(tokenizer);
}

int FileCodeCommand(const char* filename)
{
    StreamTokenizer tokenizer(filename);
    return RunCodeCommand(tokenizer);
}

int RunCommand(const int argc, const char* argv[])
{
    if (argc > 1)
    {
        const char* option = argv[1];

        if (strcmp(option, "-t") == 0 || strcmp(option, "--text") == 0)
        {
            if (argc > 2)
            {
                return StringCodeCommand(argv[2]);
            }

            cout << "Usage: Text <text>" << endl;
            return EXIT_SUCCESS;
        }
        else if (strcmp(option, "-f") == 0 || strcmp(option, "--file") == 0)
        {
            if (argc > 2)
            {
                return FileCodeCommand(argv[2]);
            }

            cout << "Usage: File <fichier.lsp>" << endl;
            return EXIT_SUCCESS;
        }
        else if (strcmp(option, "-v") == 0 || strcmp(option, "--version") == 0)
        {
            cout << "Interprèteur ";

            cout << INTERPRETER_VERSION_MAJOR << "."
                << INTERPRETER_VERSION_MINOR << "."
                << INTERPRETER_VERSION_PATCH
                << " (cli)"
                << endl;

            cout << "Copyright (c) 2021 ToToRiina" << endl;

            return EXIT_SUCCESS;
        }
    }

    return PrintingCommandHelp();
}

int main(const int argc, const char* argv[])
{
    try
    {
        return RunCommand(argc, argv);
    }
    catch (exception e)
    {
        cout << "\x1B[91mErreur: " << e.what() << "\033[0m" << endl;
    }

    return EXIT_FAILURE;
}
