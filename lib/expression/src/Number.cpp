#include "Number.h"

Number::Number(string value)
	: ::TerminalExpression(value)
{}

long Number::Evaluate(Context&)
{
	return stoi(this->m_value);
}
