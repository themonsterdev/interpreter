#include "Operator/Comparison/ThreeWayExpression.h"

ThreeWayExpression::ThreeWayExpression(Expression::Pointer left, Expression::Pointer right)
	: ::NonTerminalExpression(left, right)
{}

long ThreeWayExpression::Evaluate(Context& context)
{
	long left = m_left->Evaluate(context);
	long right = m_right->Evaluate(context);
	
	if (left < right)
	{
		return -1;
	}
	else if (left > right)
	{
		return 1;
	}

	return 0;
}
