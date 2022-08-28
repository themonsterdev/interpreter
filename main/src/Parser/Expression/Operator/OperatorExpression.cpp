#include "Parser/Expression/Operator/OperatorExpression.h"
#include "Parser/Expression/NumberExpression.h"
#include "Parser/Expression/IdentifierExpression.h"

OperatorExpression::OperatorExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end)
    : ::AbstractExpression()
{
    assert(begin != end);                                                                       // Vérifie qu'un jeton est bien présent.
    begin++;                                                                                    // Next le symbole opération

    assert(expression != nullptr);
    assert(
        expression->GetType() == (int)ExpressionInterface::Type::NUMBER ||
        expression->GetType() == (int)ExpressionInterface::Type::IDENTIFIER
    );
    m_leftExpression = expression;

    assert(begin != end);																	    // Vérifie qu'un jeton est bien présent.
    assert(
        begin->HasType((int)Token::Type::NUMBER) ||
        begin->HasType((int)Token::Type::IDENTIFIER)
    );                                                                                          // Vérifie que le jeton est bien un nombre.
    ExpressionInterface::Pointer pExpression = Parser::GetLiteralExpression(begin, end);     // Définie un pointeur d'expression.
    // ExpressionInterface::Pointer pExpression = make_shared<NumberExpression>(begin, end);       // Définie un pointeur d'expression.
    assert(pExpression != nullptr);		
    m_rightExpression = pExpression;

    SetType((int)Type::NUMBER);
}

void OperatorExpression::Interpret(Context& context)
{
    m_leftExpression->Interpret(context);
    long lLeftValue = context.m_lValues.top();
    context.m_lValues.pop();

    m_rightExpression->Interpret(context);
    long lRightValue = context.m_lValues.top();
    context.m_lValues.pop();

    DoInterpret(context, lLeftValue, lRightValue);
}
