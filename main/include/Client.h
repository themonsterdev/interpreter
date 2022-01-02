#ifndef CLIENT_H
#define CLIENT_H

#include "stdafx.h"
#include "Tokenizer/Interface/TokenizerInterface.h"
#include "Parser/Parser.h"
#include "Context.h"

class Client
{
private:

    Context m_context;
    Parser m_parser;

public:

    void Interpret(TokenizerInterface& tokenizer);

private:

    static Token::List Tokenize(TokenizerInterface& tokenizer);
};

#endif
