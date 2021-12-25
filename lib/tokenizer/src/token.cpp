#include "Token.h"

string Token::GetStringType(Token::Type type)
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
    : m_type( Token::Type::Unknown )    // Définit le type de jeton inconue.
    , m_numberAtCharacter(1)            // Définit le numéro au caractère.
    , m_numberLine(1)                   // Définit le numéro de ligne.
{}

Token::Token( Token::Type type )
    : m_type( type )            // Définit le type de jeton inconue.
    , m_numberAtCharacter(1)    // Définit le numéro au caractère.
    , m_numberLine(1)           // Définit le numéro de ligne.
{}

void Token::SetType(Token::Type type)
{
    this->m_type = type;
}

Token::Type Token::GetType()
{
    return this->m_type;
}

void Token::SetData(string data)
{
    this->m_data = data;
}

void Token::SetData(const char data)
{
    this->m_data += data;
}

string Token::GetData()
{
    return this->m_data;
}

void Token::SetNumberLine(const int numberLine)
{
    this->m_numberLine = numberLine;
}

int Token::GetNumberLine()
{
    return this->m_numberLine;
}

void Token::SetNumberAtCharacter(const int numberAtCharacter)
{
    this->m_numberAtCharacter = numberAtCharacter;
}

int Token::GetNumberAtCharacter()
{
    return this->m_numberAtCharacter;
}
