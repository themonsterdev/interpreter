#ifndef CONTEXT_H
#define CONTEXT_H

#include "stdafx.h"

/**
 * Classe Context
 * 
 * Permet de définir une correspondance entre les variables et les valeurs.
 */
class Context
{
public:

    map<string, long> m_lVariables;
    stack<long> m_lValues;
};

#endif
