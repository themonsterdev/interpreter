#include "Client.h"

void PrintingCommandHelp()
{
    cout << "Usage: Interprèteur [Options]" << endl << endl;

    cout << "Options:" << endl;
    cout << '\t' << "-l, --line_code         " << '\t' << "Entreé du code." << endl;
    cout << '\t' << "-f, --file <fichier.lsp>" << '\t' << "Analyse et exécution le <fichier>." << endl;
    cout << '\t' << "-h, --help              " << '\t' << "Afficher l'aide pour la commande." << endl;
    cout << '\t' << "-v, --version           " << '\t' << "Numéro de version." << endl;
}

int LineCodeCommand(const char* expression)
{
    Client* pClient = Client::Get();

    StringTokenizer tokenizer(expression != nullptr ? expression : "");
    pClient->Interpret(tokenizer);

    string expressionLine;
    while (getline(cin, expressionLine))
    {
        tokenizer = StringTokenizer(expressionLine.c_str());
        pClient->Interpret(tokenizer);
    }

    return EXIT_SUCCESS;
}

int FileCodeCommand(const char* filename)
{
    Client* pClient = Client::Get();
    StreamTokenizer tokenizer(filename);
    pClient->Interpret(tokenizer);
    return EXIT_SUCCESS;
}

int RunCommand(const int argc, const char* argv[])
{
    if (argc > 1)
    {
        const char* option = argv[1];

        if (strcmp(option, "-l") == 0 || strcmp(option, "--line_code") == 0)
        {
            return LineCodeCommand(argc == 2 ? nullptr : argv[2]);
        }
        else if (strcmp(option, "-f") == 0 || strcmp(option, "--file") == 0)
        {
            if (argc > 2)
            {
                return FileCodeCommand(argv[2]);
            }

            cout << "Usage: File <fichier>" << endl;
            return EXIT_SUCCESS;
        }
        else if (strcmp(option, "-h") == 0 || strcmp(option, "--help") == 0)
        {
            PrintingCommandHelp();
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

    PrintingCommandHelp();
    return EXIT_SUCCESS;
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
