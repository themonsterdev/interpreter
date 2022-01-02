#ifndef MODULO_EXPRESSION_H
#define MODULO_EXPRESSION_H

#include "Parser/Expression/Operator/OperatorExpression.h"

class ModuloExpression : public OperatorExpression
{
public:

    ModuloExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end);

    // OperatorExpression
    virtual void DoInterpret(Context& context, long left, long right);
};

#endif
