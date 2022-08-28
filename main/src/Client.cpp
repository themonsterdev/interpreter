#include "Client.h"

void Client::Interpret(TokenizerInterface& tokenizer)
{
    Token::List tokens                      = Client::Tokenize(tokenizer);  // Optenir une liste de jetons.
    
    StatementInterface::Queue statements    = m_parser.Parse(tokens);       // Optenir une liste de déclarations.
    StatementInterface::Pointer pSatement   = nullptr;                      // Définie un pointeur de statement null.

    while (!statements.empty())                                             // Tant que une déclaration est présent.
    {
        pSatement = statements.front();                                      // Récupère la déclaration actuelle.
        statements.pop();

        pSatement->Interpret(m_context);                                    // Interpèter la déclaration actuelle.
    }
}

Token::List Client::Tokenize(TokenizerInterface& tokenizer)
{
    Token::List tokens;                         // Définit une liste de jetons.
    Token token;                                // Déclare un jeton vide.

    while (tokenizer.HasNext())                 // Tant que on jeton est présent.
    {
        token = tokenizer.GetNext();            // Assigne le jeton par la valeur du jeton actuel.
        tokens.push_back(token);                // Ajoute le jeton à la liste de jetons.
    }

    cout << "Tokens size (" << tokens.size() << ")" << endl;

    return tokens;                              // Retourne la liste des jetons.
}
