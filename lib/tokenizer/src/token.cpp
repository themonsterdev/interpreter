#include "Token.h"

string Token::getStringType(Token::Type type)
{
    string result;
    switch (type)
    {
    case Token::Type::Keyword:
        result = "Token::Keyword";
        break;
    case Token::Type::Identifier:
        result = "Token::Identifier";
        break;
    case Token::Type::Operator:
        result = "Token::Operator";
        break;
    case Token::Type::Number:
        result = "Token::Number";
        break;
    default:
        result = "Token::Unknown";
        break;
    }

    return result;
}

Token::Token()
    : m_type(Token::Type::Unknown )
{}

Token::Token( Token::Type type )
    : m_type( type )
{}

void Token::setType(Token::Type type)
{
    this->m_type = type;
}

Token::Type Token::getType()
{
    return this->m_type;
}

void Token::setData(string data)
{
    this->m_data = data;
}

void Token::setData(const char data)
{
    this->m_data += data;
}

string Token::getData()
{
    return this->m_data;
}
