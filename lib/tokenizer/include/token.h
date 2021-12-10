#ifndef TOKEN_H
#define TOKEN_H

class Token {
public:

    enum Type {
        Keyword,
        Identifier,
        Operator,
        Number,
        Unknown
    };

    Token( Token::Type type );

    Token::Type getType();

private:

    Type m_type;
};

#endif
