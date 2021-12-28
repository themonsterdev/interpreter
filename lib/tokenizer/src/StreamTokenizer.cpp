#include "StreamTokenizer.h"

StreamTokenizer::StreamTokenizer(string filename)
    : m_delim(" ")
    , m_returnDelims(false)
    , m_tokenCount(0)
    , m_currentCharacter('\0')
    , m_numberToken(.0)
    , m_isStr(false)
    , m_isNumber(false)
{
    OpenFile(filename);
}

StreamTokenizer::StreamTokenizer(string filename, string delim)
    : m_delim(delim)
    , m_returnDelims(false)
    , m_tokenCount(0)
    , m_currentCharacter('\0')
    , m_numberToken(.0)
    , m_isStr(false)
    , m_isNumber(false)
{
    OpenFile(filename);
}

StreamTokenizer::StreamTokenizer(string filename, string delim, bool returnDelims)
    : m_delim(delim)
    , m_returnDelims(returnDelims)
    , m_tokenCount(0)
    , m_currentCharacter('\0')
    , m_numberToken(.0)
    , m_isStr(false)
    , m_isNumber(false)
{
    OpenFile(filename);
}

void StreamTokenizer::OpenFile(string filename)
{
    m_is.open(filename); // open file

    if (!m_is.is_open())
    {
        throw exception((string("Impossible d'ouvrir le fichier ") + filename).c_str());
    }
}

void StreamTokenizer::WordChars(char low, char high)
{
    vector<char> wc;
    wc.push_back(low);
    wc.push_back(high);
    m_vWordChars.push_back(wc);
}

int StreamTokenizer::CountTokens()
{
    return m_tokenCount;
}

bool StreamTokenizer::HasMoreTokens()
{
    if (m_is.eof())
    {
        m_is.close();
        return false;
    }

    m_is.get(m_currentCharacter);
    m_tokenCount++;

    return IsDelimToken() ? HasMoreTokens() : true;
}

int StreamTokenizer::GetNextToken()
{
    if (m_is.eof())
    {
        throw exception("Aucun token n'est disponible!");
    }

    m_strToken      = "";
    m_numberToken   = 0;

    m_isStr         = false;
    m_isNumber      = false;
    
    return GetStringLiteralToken();
}

int StreamTokenizer::GetStringLiteralToken()
{
    vector<char> wc;
    bool isStr = false;

    for (size_t i = 0; i < m_vWordChars.size(); i++)
    {
        wc = m_vWordChars[i];
        isStr = m_currentCharacter >= wc[0] && m_currentCharacter <= wc[1];
        if (!isStr) break;
    }

    m_isStr = isStr;

    m_isNumber = !m_isStr && m_currentCharacter >= '0' && m_currentCharacter <= '9';

    m_strToken += m_currentCharacter;

    if (!m_is.eof())
    {
        m_is.get(m_currentCharacter);
        m_tokenCount++;

        if (!IsDelimToken())
        {
            return GetStringLiteralToken();
        }
    }

    if (m_isStr && m_strToken.length() > 1)
    {
        return static_cast<int>(StreamTokenizer::TokenType::TT_WORD);
    }
    else if (m_isNumber && m_strToken.length() > 0)
    {
        return static_cast<int>(StreamTokenizer::TokenType::TT_NUMBER);
    }
    
    return static_cast<int>(m_currentCharacter);
}

bool StreamTokenizer::IsDelimToken()
{
    size_t delimLength = m_delim.length();

    for (
        size_t i = 0;
        i < delimLength;
        ++i
    ) {
        if (m_currentCharacter == m_delim[i])
        {
            return true;
        }
    }

    return false;
}

double StreamTokenizer::GetNumberToken()
{
    return m_numberToken;
}

string StreamTokenizer::GetStringToken()
{
    return m_strToken;
}
