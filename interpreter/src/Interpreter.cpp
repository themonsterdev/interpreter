#include "Interpreter.h"

// Tokenizer
#include "StreamTokenizer.h"
#include "StringTokenizer.h"

string GetStringFromFile(const char* filepath)
{
    ifstream is(filepath); // open file
    string programText;

    if (is)
    {
        char character;
        while (!is.eof()) // loop getting single characters
        {
            is.get(character);
            programText += character;
        }

        is.close(); // close file
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier " << filepath << endl;
    }

    return programText;
}

Token::List GetToken(const char* filepath)
{
    string programText(GetStringFromFile(filepath));

    string delim({ ' ', '\n', '\r', '\t' });
    StringTokenizer st(programText, delim);
    string token;
    while (st.HasMoreTokens())
    {
        token = st.GetNextToken();
        cout << token << endl;
    }

    Tokenizer tokenizer(programText);
    Token::List tokens = tokenizer.GetTokens();
    // Tokenizer::PrintTokens( tokens );
    return tokens;
}

Statement::StatementList GetStatements(Context& context, Token::List tokens)
{
    Statement::StatementList statements;
    Statement::Pointer pStatement;

    Token::Iterator itEnd = tokens.end();

    for (
        Token::Iterator it = tokens.begin();
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

void Execute(Context& context, Statement::StatementList statements)
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
    cout << '\t' << "-b, --begin             " << '\t' << "Entreé du code." << endl;
    cout << '\t' << "-v, --version           " << '\t' << "Numéro de version." << endl;
    cout << '\t' << "-h, --help              " << '\t' << "Afficher l'aide pour la commande." << endl;
}

int Interpreter::Main(const int argc, const char* argv[])
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
        else if (option == "-v" || option == "--version")
        {
            cout << "Interprèteur ";

            cout << INTERPRETER_VERSION_MAJOR << "."
                << INTERPRETER_VERSION_MINOR << "."
                << INTERPRETER_VERSION_PATCH;

            cout << " (cli)" << endl;

            cout << "Copyright (c) 2021 ToToRiina" << endl;

            return EXIT_SUCCESS;
        }
        else if (option == "-b" || option == "--begin")
        {
            return ParseStringContinue();
        }
    }
    else if (argc == 3)
    {
        string option(argv[1]);

        if (option == "-f" || option == "--file")
        {
            string filename(argv[2]);
            return ParseFile(filename);
        }
    }

    string str;
    for (int i = 1; i < argc; i++)
    {
        str += string(argv[i]) + " ";
    }

    return ParseString(str.substr(0, str.size() - 1));
}

int Interpreter::ParseFile(string filename)
{
    cout << "ParseFile(" << filename << ")" << endl;

    string delim({ ' ', '\n', '\r', '\t' });
    StreamTokenizer st(filename, delim);
    st.WordChars('a', 'z');
    st.WordChars('A', 'Z');
    st.WordChars('_', '_');

    int tokenType;
    while (st.HasMoreTokens())
    {
        tokenType = st.GetNextToken();
        cout << "Token: " << tokenType << " - " << st.GetStringToken() << endl;
    }

    // Token::List tokens = GetToken(filename.c_str());

    // Context context;
    // Statement::StatementList statements = GetStatements(context, tokens);

    // Execute(context, statements);

    return EXIT_SUCCESS;
}

int Interpreter::ParseString(string str)
{
    cout << "ParseString(" << str << ")" << endl;

    Tokenizer tokenizer(str);
    Tokenizer::PrintTokens(tokenizer.GetTokens());

    return EXIT_SUCCESS;
}

int Interpreter::ParseStringContinue()
{
    cout << "ParseStringContinue()" << endl;

    string input;
    string token;

    while (cin >> input)
    {
        Tokenizer tokenizer(input);
        Tokenizer::PrintTokens(tokenizer.GetTokens());
    }

    return EXIT_SUCCESS;
}
