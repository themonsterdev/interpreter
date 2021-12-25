#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <list>

using namespace std;

/**
 * Classe Token
 * 
 * Cette classe représente un jeton trouvé dans une chaîne de caractères spécifiée.
 * 
 * Un jeton est une suite de caractères dans un programme source qui correspond au motif
 * d'un symbole lexical et qui est analysé par le Tokenizer comme une instance de ce jeton lexical.
 * 
 * @see https://fr.wikipedia.org/wiki/Analyse_lexicale
 */
class Token
{
public:

    /**
     * Type d'énumération de jeton.
     */
    enum class Type
    {
        Keyword,    /**< enum value 0 */
        Identifier, /**< enum value 1 */
        Operator,   /**< enum value 2 */
        Number,     /**< enum value 3 */
        Unknown     /**< enum value 4 */
    };

    /**
     * Optenir le type de jeton de type chaine de caractères.
     * 
     * @return string
     */
    static string GetStringType(Token::Type type);

    /**
     * Constructeur vide
     */
    Token();

    /**
     * Constructeur avec paramètre
     * 
     * @param type Le type du jeton
     */
    Token( Token::Type type );

    /**
     * Définit le type du jeton
     * 
     * @return void
     */
    void SetType(Token::Type type );

    /**
     * obtenir le type du jeton
     * 
     * @return Token
     */
    Token::Type GetType();

    /**
     * Définit les données du jeton
     *
     * @param data Les donnée de type string
     * @return void
     */
    void SetData(string data);

    /**
     * Définit les données du jeton
     *
     * @param data Les donnée de type char
     * @return void
     */
    void SetData(const char data);

    /**
     * Obtenir les données du jeton
     *
     * @return Token
     */
    string GetData();

    void SetNumberAtCharacter(const int numberLine);
    int GetNumberAtCharacter();

    /**
     * Définit le numéro de ligne sur lequel le jeton à était trouvé
     *
     * @param numberLine le numéro de ligne.
     * @return void
     */
    void SetNumberLine(const int numberLine);

    /**
     * Obtenir le numéro de ligne sur lequel le jeton à était trouvé.
     *
     * @return int
     */
    int GetNumberLine();

private:

    Type m_type;
    string m_data;

    int m_numberAtCharacter;
    int m_numberLine;
};

typedef list<Token> TokenList;
typedef TokenList::iterator TokenIt;

#endif
