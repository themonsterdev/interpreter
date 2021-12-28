#include "Operator/Logical/NegationExpression.h"

NegationExpression::NegationExpression(string value)
	: ::TerminalExpression(value)
{}

long NegationExpression::Evaluate(Context&)
{
	return !stoi(m_value);
}
