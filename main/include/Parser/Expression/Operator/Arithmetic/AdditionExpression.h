#ifndef ADDITION_EXPRESSION_H
#define ADDITION_EXPRESSION_H

#include "Parser/Expression/Operator/OperatorExpression.h"

class AdditionExpression : public OperatorExpression
{
public:

    AdditionExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);

    // OperatorExpression
    virtual void DoInterpret(Context& context, long left, long right);
};

#endif
