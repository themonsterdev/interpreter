#ifndef ABSTRACT_EXPRESSION_H
#define ABSTRACT_EXPRESSION_H

#include "Parser/Expression/Interface/ExpressionInterface.h"
#include "Tokenizer/Token.h"

/**
 * Classe AbstractExpression
 */
class AbstractExpression : public ExpressionInterface
{
public:

	AbstractExpression();

	// ExpressionInterface
	virtual void SetType(int type);
	virtual int GetType();

	virtual string GetIdentifier();
	virtual bool GetBoolean();
	virtual long GetNumber();

protected:

	int m_iType;

	string m_wsIdentifier;
	bool m_bBoolean;
	long m_lNumber;
};

#endif
