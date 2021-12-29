#ifndef CLIENT_H
#define CLIENT_H

#include "Preprocessor.h"

#include "StreamTokenizer.h"
#include "StringTokenizer.h"
#include "Token.h"

#include "Context.h"
#include "Parser.h"

#include <memory>
#include <cassert>  // assert
#include <iostream> // std::cout
#include <list>     // std::list

using namespace std;

class Client
{
public:

    /**
     * Pointeur Client.
     *
     * @return Client*
     */
    static Client* Get();

    /**
     * Constructeur Client.
     */
    Client();

    /**
     * Déstructeur Client.
     */
    ~Client();

    void Interpret(TokenizerInterface& tokenizer);

private:

    /**
     * Pointeur intelligent Context.
     */
    shared_ptr<Context> m_pContext;

    unique_ptr<Parser> m_pParser;

    Token::List Tokenize(TokenizerInterface& tokenizer);

    Context* GetContext();
    Parser* GetParser();
};

#endif
