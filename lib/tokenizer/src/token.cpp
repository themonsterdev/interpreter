#include "token.h"

Token::Token( Token::Type type )
    : m_type( type )
{}

Token::Type Token::getType() {
    return m_type;
}
