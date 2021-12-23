#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <thread>
#include <list>

#include "context.h"
#include "token.h"

using namespace std;

/**
 * Classe Expression
 */
class Expression
{
public:

	typedef shared_ptr<Expression> ExprPtr;
	typedef list<ExprPtr> Exprs;
	typedef shared_ptr<Exprs> ExprsPtr;

	static ExprPtr parse(TokenIt& it);

	virtual ~Expression() {};

	virtual long evaluate(Context& context) = 0;
};

/**
 * Classe TerminalExpression
 */
class TerminalExpression : public Expression
{
public:

	TerminalExpression(string name);

	virtual long evaluate(Context& context);

private:

	string m_name;
};

/**
 * NonTerminalExpression
 */
class NonTerminalExpression : public Expression
{
public:

	NonTerminalExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context) = 0;

	Expression* getRight();
	void setRight(Expression* right);

protected:

	Expression *m_left, *m_right;
};

/**
 * NonTerminalExpression - AdditionExpression
 */
class AdditionExpression : public NonTerminalExpression
{
public:

	AdditionExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

/**
 * NonTerminalExpression - SubtractionExpression
 */
class SubtractionExpression : public NonTerminalExpression
{
public:

	SubtractionExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

/**
 * NonTerminalExpression - MultiplicationExpression
 */
class MultiplicationExpression : public NonTerminalExpression
{
public:

	MultiplicationExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

/**
 * NonTerminalExpression - DivisionExpression
 */
class DivisionExpression : public NonTerminalExpression
{
public:

	DivisionExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

/**
 * NonTerminalExpression - ModuloExpression
 */
class ModuloExpression : public NonTerminalExpression
{
public:

	ModuloExpression(Expression* left, Expression* right = nullptr);

	virtual long evaluate(Context& context);
};

class Number : public Expression
{
public:

	Number(long number);
	virtual long evaluate(Context& context);

private:

	long m_number;
};

class Identifier : public Expression
{
public:

	Identifier(string identifier);
	virtual long evaluate(Context& context);

private:

	string m_identifier;
};

#endif
