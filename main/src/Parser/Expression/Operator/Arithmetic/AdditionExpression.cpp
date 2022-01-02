#include "Parser/Expression/Operator/Arithmetic/AdditionExpression.h"
#include "Parser/Expression/NumberExpression.h"

AdditionExpression::AdditionExpression(ExpressionInterface::Pointer expression, Token::Iterator& begin, Token::Iterator& end)
    : ::OperatorExpression(expression, begin, end)
{}

void AdditionExpression::DoInterpret(Context& context, long left, long right)
{
    m_lNumber = left + right;

    cout << "\x1B[33m" << left      << "\033[0m" << " + ";
    cout << "\x1B[33m" << right     << "\033[0m" << " = ";
    cout << "\x1B[33m" << m_lNumber << "\033[0m" << endl;

    context.m_lValues.push(m_lNumber);
}
