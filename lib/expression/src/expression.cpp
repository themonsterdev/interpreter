#include "expression.h"

#include <iostream>

Expression::ExprPtr Expression::parse(TokenIt& it)
{
	Token::Type tokenType = it->getType();
	string tokenData = it->getData();

	Expression* pExpression = nullptr;

	switch (tokenType)
	{
	case Token::Type::Number:
		{
			pExpression = new Number(stoi(tokenData));

			it++;

			if (it->getType() == Token::Type::Operator)
			{
				string tokenDataOperator = it->getData();

				if (tokenDataOperator == "+")
				{
					pExpression = new AdditionExpression(pExpression);
				}
				else if (tokenDataOperator == "-")
				{
					pExpression = new SubtractionExpression(pExpression);
				}
				else if (tokenDataOperator == "*")
				{
					pExpression = new MultiplicationExpression(pExpression);
				}
				else if (tokenDataOperator == "/")
				{
					pExpression = new DivisionExpression(pExpression);
				}
				else if (tokenDataOperator == "%")
				{
					pExpression = new ModuloExpression(pExpression);
				}
				else
				{
					throw exception(
						(string("Unexpected: ") + tokenDataOperator).c_str()
					);
				}

				it++;

				if (it->getType() != Token::Type::Number)
				{
					throw exception(
						(string("Unexpected: ") + tokenData).c_str()
					);
				}

				reinterpret_cast<NonTerminalExpression*>(pExpression)
					->setRight(
						new Number( stoi(it->getData() ) )
					);
			}
			else
			{
				it--;
			}
		}
		break;

	case Token::Type::Identifier:
		pExpression = new Identifier(tokenData);
		// it++;
		break;

	default:
		throw exception(
			(string("Unexpected : ") + tokenData).c_str()
		);
	}

	return ExprPtr(pExpression);
}

// TerminalExpression

TerminalExpression::TerminalExpression(string name)
	: m_name(name)
{}

long TerminalExpression::evaluate(Context& context)
{
	return context.getValue(m_name);
}

// NonTerminalExpression

NonTerminalExpression::NonTerminalExpression(Expression* left, Expression* right)
	: m_left(left)
	, m_right(right)
{}


Expression* NonTerminalExpression::getRight()
{
	return m_right;
}

void NonTerminalExpression::setRight(Expression* right)
{
	m_right = right;
}

// AdditionExpression

AdditionExpression::AdditionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long AdditionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) + m_right->evaluate(context);
}

// SubtractionExpression

SubtractionExpression::SubtractionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long SubtractionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) - m_right->evaluate(context);
}

// MultiplicationExpression

MultiplicationExpression::MultiplicationExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long MultiplicationExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) * m_right->evaluate(context);
}

// DivisionExpression

DivisionExpression::DivisionExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long DivisionExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) / m_right->evaluate(context);
}

// ModuloExpression

ModuloExpression::ModuloExpression(Expression* left, Expression* right)
	: ::NonTerminalExpression(left, right)
{}

long ModuloExpression::evaluate(Context& context)
{
	return m_left->evaluate(context) % m_right->evaluate(context);
}

// Number

Number::Number(long number)
	: m_number(number)
{}

long Number::evaluate(Context& context)
{
	return m_number;
}

// Identifier

Identifier::Identifier(string identifier)
	: m_identifier(identifier)
{}

long Identifier::evaluate(Context& context)
{
	return context.getValue(m_identifier);
}
