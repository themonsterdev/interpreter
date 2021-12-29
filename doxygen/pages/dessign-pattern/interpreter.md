@page interpreter Interpreter (patron de conception)

En [génie logiciel](https://fr.wikipedia.org/wiki/G%C3%A9nie_logiciel), le **patron de conception interpréteur**
est un [patron de conception](https://fr.wikipedia.org/wiki/Patron_de_conception) qui spécifie comment
évaluer des phrases dans un [langage](https://fr.wikipedia.org/wiki/Langage_de_programmation).

L'idée de base est d'avoir une [classe](https://fr.wikipedia.org/wiki/Classe_(informatique)) pour
chaque symbole ([terminal](https://fr.wikipedia.org/wiki/Symboles_terminaux_et_non_terminaux#Symboles_terminaux) ou
[non terminal](https://fr.wikipedia.org/wiki/Symboles_terminaux_et_non_terminaux#Symboles_non_terminaux) dans un
[langage dédié](https://fr.wikipedia.org/wiki/Langage_d%C3%A9di%C3%A9).

L'[arbre syntaxique](https://fr.wikipedia.org/wiki/Arbre_syntaxique) d'une phrase dans le langage est une instance du
[patron de conception Composite](https://fr.wikipedia.org/wiki/Composite_(patron_de_conception)) et est utilisé
pour **évaluer/interpréter** la phrase pour un client.

# Introduction

Le patron de conception **Interpreter** est l'un des vingt-trois [patron de conception du GoF](https://fr.wikipedia.org/wiki/Patron_de_conception#Patrons_de_conception_du_GoF)
bien connus qui décrivent comment résoudre des problèmes de conception récurrents pour concevoir des logiciels orientés objet flexibles et
réutilisables, c'est-à-dire des objets plus faciles à mettre en œuvre, à modifier, tester et réutiliser.

## Quels problèmes le design pattern Interpreter peut-il résoudre ?

- Analyser/[parser](https://fr.wikipedia.org/wiki/Analyse_syntaxique) une chaîne algébrique. C'est un cas assez évident où le logiciel doit exécuter
des opérations en fonction d'une équation (dessiner la courbe d'une fonction par exemple).
- lorsque le logiciel doit produire différents types de données comme résultat. Ce cas est moins évident, mais l'interpréteur y est très utile.
Prenez l'exemple d'un logiciel capable d'afficher des données dans n'importe quel ordre, en les triant ou pas, etc.

Une [grammaire](https://fr.wikipedia.org/wiki/Forme_de_Backus-Naur) pour le langage doit être définie
afin que les phrases de la langue puissent être interprétées.

Lorsqu'un problème survient très souvent, il peut être envisagé de le représenter sous la forme d'une phrase dans un 
[langage dédié](https://fr.wikipedia.org/wiki/Langage_d%C3%A9di%C3%A9) afin qu'un interpréteur puisse résoudre le
problème en interprétant la phrase.

Par exemple, lorsque de nombreuses expressions de recherche différentes ou complexes doivent être spécifiées. Leur implémentation
(câblage matériel) directement dans une classe est inflexible car elle engage la classe dans des expressions particulières et rend
impossible la spécification de nouvelles expressions ou la modification d'expressions existantes indépendamment (sans avoir à modifier) ​
la classe.

## Quelle solution le modèle de conception Interpreter décrit-il ?

- Définir une grammaire pour un langage en définissant une Expression hiérarchie de classes et en implémentant une opération interpret().
- Représenter une phrase dans le langage par un [arbre de syntaxe abstraite (AST)](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite)
composé instances d'Expression.
- Interpréter une phrase en faisant appel à `interpret()` de l'AST.

Les objets d'expression sont composés de manière récursive dans une structure composite/arborescente appelée
[arbre de syntaxe abstraite](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite)
(voir le [patron de conception Composite](https://fr.wikipedia.org/wiki/Composite_(patron_de_conception))).

Le patron de conception **Interpreter** ne décrit pas comment construire un
[arbre de syntaxe abstraite](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite). Cela peut être fait manuellement par un client ou
automatiquement par un [analyseur](https://en.wikipedia.org/wiki/Parsing#Parser).

## Diagramme

### Patron de conception Interpreter

@startuml
!theme custom from themes
skinparam linetype polyline
left to right direction
scale 800*800

class Context {
    -m_variables: map<string, long>
    +void SetVariable(string name, long value)
    +long GetVariable(string name)
}

class Client {
    -m_context: Context
}

interface Expression {
    +void Interpret(Context context)
}

class TerminalExpression extends Expression {
    +void Interpret(Context context)
}

abstract class NonTerminalExpression extends Expression {
    #m_leftExpression: Expression
    #m_rightExpression: Expression
    +void Interpret(Context context)
    +Expression* GetLeftExpression()
    +Expression* GetRightExpression()
}

Client *--> Context
Client --> Expression

NonTerminalExpression *--> Expression
@enduml

Dans le [diagramme de classes UML](https://fr.wikipedia.org/wiki/Diagramme_de_classes) ci-dessus:

- La classe Client fait référence à l'interface commune Expression pour interpréter une expression.
- La classe TerminalExpression n'a pas d'enfants et interprète directement une expression.
- La classe NonTerminalExpression maintient un conteneur d'expressions enfants et transmet les requêtes d' interprétation à ces derniers expressions.  

### Arbre de syntaxe abstraite

@startuml
!theme custom from themes
scale 600*400

object Client

object AdditionExpression #446e9b/deedff {
    start: 1 + 2 * 3
}

object NumberExpression1 {
   left: 1
}

object MultiplicationExpression #446e9b/ffffff {
    final: 1 + 2 = 3
}

object NumberExpression2 {
   right: 2
}

object NumberExpression3 {
    left: 3
}

object NumberExpression4 {
    final: 3 * 3 = 9
}

object NumberExpression5 {
    right: 3
}

Client -right-> AdditionExpression

AdditionExpression --|> NumberExpression1
AdditionExpression --|> MultiplicationExpression
AdditionExpression --|> NumberExpression2

MultiplicationExpression --|> NumberExpression3
MultiplicationExpression --|> NumberExpression4
MultiplicationExpression --|> NumberExpression5
@enduml
 
Dans le [Diagramme de collaboration d'objet UML](https://fr.wikipedia.org/wiki/Diagramme_d%27objets) ci-dessus:

Les objets montre les interactions d'exécution :

- L'objet Client envoie une demande d'interprétation à l'[arbre de syntaxe abstraite](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite).
- La requête est transmise à tous les objets en bas de l'arborescence.  
- Les objets NonTerminalExpression (AdditionExpression, MultiplicationExpression) transmettent la requête à leurs expressions enfants.  
- Les objets TerminalExpression (NumberExpression1, NumberExpression2, ...) effectuent directement l'interprétation.

# Exemple

## BNF 

L'exemple de formulaire Backus-Naur suivant illustre le modèle d'interprétation.

La grammaire:

```bnf
expression ::= plus | moins | variable | nombre 
plus ::= expression expression '+' 
moins ::= expression expression '-' 
variable ::= 'a' | 'b' | 'c' | ... | 
chiffre 'z' = '0' | '1' | ... | '9' 
nombre ::= chiffre | nombre Digital
```

définit une langue qui contient des expressions de notation polonaise inversée telles que :

```
ab + 
abc + - 
ab + ca - -
```

En suivant le modèle de l'interpréteur, nous devons implémenter l'interface Expression pour chaque règle de grammaire.

## Java

L'exemple Java suivant montre comment interpréter un langage spécialisé, tel que les expressions en notation polonaise inversée. Dans ce langage, on donne les opérandes avant l'opérateur.

```java
import java.util.*;

interface Expression
{
    public void interpret(Stack<Integer> s);
}

class TerminalExpression_Number implements Expression
{
    private int number;

    public TerminalExpression_Number(int number)
    { this.number = number; }

    public void interpret(Stack<Integer> s)
    { s.push(number); }
}

class NonTerminalExpression_Plus implements Expression
{
    public void interpret(Stack<Integer> s)
    { s.push( s.pop() + s.pop() ); }
}

class NonTerminalExpression_Minus implements Expression
{
    public void interpret(Stack<Integer> s)
    { s.push( - s.pop() + s.pop() ); }
}

class Parser
{
    private ArrayList<Expression> parseTree =
        new ArrayList<Expression>(); // only one NonTerminal Expression here

 	public Parser(String s) {
		
		Expression plus = new NonTerminalExpression_Plus();
		Expression minus = new NonTerminalExpression_Minus();
		
		for (String token : s.split(" ")) {
			if (token.equals("+"))
				parseTree.add(plus);
			else if (token.equals("-"))
				parseTree.add(minus);
            // ...
			else
				parseTree.add(new TerminalExpression_Number(Integer.parseInt(token)));
		}
	}

    public int evaluate()
    {
        Stack<Integer> context = new Stack<Integer>();
        for (Expression e : parseTree) e.interpret(context);
        return context.pop();
    }
}

public class Interpreter
{
    public static void main(String[] args)
    {
        String expression = args[0];
        Parser p = new Parser(expression);
        System.out.println("'" + expression +"' equals " + p.evaluate());
    }
}
```

Ce programme affiche :

```
'42 4 2 - +' equals 44
```

# Références

- [patron de conception Interpréteur](https://fr.wikipedia.org/wiki/Interpr%C3%A9teur_(patron_de_conception))
