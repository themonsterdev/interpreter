#ifndef EXPRESSION_INTERFACE_H
#define EXPRESSION_INTERFACE_H

#include "Context.h"

/**
 * Interface ExpressionInterface
 * 
 * @see https://fr.wikipedia.org/wiki/Expression_(informatique)
 */
class ExpressionInterface
{
public:

	typedef shared_ptr<ExpressionInterface> Pointer;
	typedef list<Pointer> List;

	enum class Type : int
	{
		NONE,
		IDENTIFIER,
		BOOLEAN,
		NUMBER
	};

	virtual ~ExpressionInterface() = default;

	virtual void Interpret(Context& context) = 0;

	virtual void SetType(int type) = 0;
	virtual int GetType() = 0;

	virtual string GetIdentifier() = 0;
	virtual bool GetBoolean() = 0;
	virtual long GetNumber() = 0;
};

#endif
