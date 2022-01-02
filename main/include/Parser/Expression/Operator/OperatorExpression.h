#ifndef OPERATOR_EXPRESSION_H
#define OPERATOR_EXPRESSION_H

#include "Parser/Expression/AbstractExpression.h"

class OperatorExpression : public AbstractExpression
{
public:

    OperatorExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);
    virtual ~OperatorExpression() = default;

    // ExpressionInterface
    virtual void Interpret(Context& context);

    virtual void DoInterpret(Context& context, long left, long right) = 0;

protected:

    ExpressionInterface::Pointer m_leftExpression;
    ExpressionInterface::Pointer m_rightExpression;
};

#endif
