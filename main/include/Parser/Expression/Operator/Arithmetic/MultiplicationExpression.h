#ifndef MULTIPLICATION_EXPRESSION_H
#define MULTIPLICATION_EXPRESSION_H

#include "Parser/Expression/Operator/OperatorExpression.h"

class MultiplicationExpression : public OperatorExpression
{
public:

    MultiplicationExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);

    // OperatorExpression
    virtual void DoInterpret(Context& context, long left, long right);
};

#endif
