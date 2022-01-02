#ifndef DIVISION_EXPRESSION_H
#define DIVISION_EXPRESSION_H

#include "Parser/Expression/Operator/OperatorExpression.h"

class DivisionExpression : public OperatorExpression
{
public:

    DivisionExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);

    // OperatorExpression
    virtual void DoInterpret(Context& context, long left, long right);
};

#endif
