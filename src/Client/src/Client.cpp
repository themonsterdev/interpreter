#include "Client.h"

#include <iostream> // std::cout+

Client* Client::Get()
{
    static unique_ptr<Client> m_pClient = nullptr;

    if (m_pClient == nullptr)
    {
        m_pClient = make_unique<Client>();
        assert(m_pClient != nullptr);
    }

    Client* pClient = m_pClient.get();
    assert(pClient != nullptr);
    return pClient;
}

Client::Client()
    : m_pContext(nullptr)
    , m_pParser(nullptr)
{}

Client::~Client()
{}

void Client::Interpret(TokenizerInterface& tokenizer)
{
    Token::List tokens = Tokenize(tokenizer);

    Parser::StatementList statements    = GetParser()->Parse(tokens);
    StatementInterface* pSatement       = nullptr;

    while (!statements.empty())
    {
        pSatement = statements.top().get();
        pSatement->Interpret(GetContext());
        statements.pop();
    }
}

list<Token> Client::Tokenize(TokenizerInterface& tokenizer)
{
    Token::List tokens;

    while (tokenizer.HasNext())
    {
        tokens.push_back(tokenizer.GetNext());
    }

    return tokens;
}

Context* Client::GetContext()
{
    if (m_pContext == nullptr)
    {
        m_pContext = make_shared<Context>();
        assert(m_pContext != nullptr);
    }

    Context* pContext = m_pContext.get();
    assert(pContext != nullptr);
    return pContext;
}

Parser* Client::GetParser()
{
    if (m_pParser == nullptr)
    {
        m_pParser = make_unique<Parser>();
        assert(m_pParser != nullptr);
    }

    Parser* pParser = m_pParser.get();
    assert(pParser != nullptr);
    return pParser;
}
