#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(string str)
    : m_str(str)
    , m_delim(" ")
    , m_returnDelims(false)
    , m_tokenCount(0)
{
    m_itBegin = m_str.begin();
    m_itEnd = m_str.end();
}

StringTokenizer::StringTokenizer(string str, string delim)
    : m_str(str)
    , m_delim(delim)
    , m_returnDelims(false)
    , m_tokenCount(0)
{
    m_itBegin = m_str.begin();
    m_itEnd = m_str.end();
}

StringTokenizer::StringTokenizer(string str, string delim, bool returnDelims)
    : m_str(str)
    , m_delim(delim)
    , m_returnDelims(returnDelims)
    , m_tokenCount(0)
{
    m_itBegin = m_str.begin();
    m_itEnd = m_str.end();
}

int StringTokenizer::CountTokens()
{
    return m_tokenCount;
}

bool StringTokenizer::HasMoreTokens()
{
    if (m_itBegin == m_itEnd)
    {
        return false;
    }

    if (IsIgnoredToken())
    {
        m_tokenCount++;
        m_itBegin++;

        return HasMoreTokens();
    }

    return true;
}

string StringTokenizer::GetNextToken() noexcept(false)
{
    if (m_itBegin == m_itEnd)
    {
        throw exception("Aucun token n'est disponible!");
    }

    string characters;
    return GetStringLiteralToken(characters);
}

string StringTokenizer::GetStringLiteralToken(string& characters)
{
    characters += *m_itBegin;

    if (m_itBegin != m_itEnd)
    {
        m_tokenCount++;
        m_itBegin++;

        if (IsIgnoredToken())
        {
            return characters;
        }

        return GetStringLiteralToken(characters);
    }

    return characters;
}

bool StringTokenizer::IsIgnoredToken()
{
    string::iterator delimItEnd = m_delim.end();

    for (
        string::iterator it = m_delim.begin();
        it != delimItEnd;
        ++it
    ) {
        if (*m_itBegin == *it)
        {
            return true;
        }
    }

    return false;
}
