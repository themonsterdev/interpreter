#ifndef SUBSTRACTION_EXPRESSION_H
#define SUBSTRACTION_EXPRESSION_H

#include "Parser/Expression/Operator/OperatorExpression.h"

class SubtractionExpression : public OperatorExpression
{
public:

    SubtractionExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);

    // OperatorExpression
    virtual void DoInterpret(Context& context, long left, long right);
};

#endif
