# EBNF

## Statement:

![diagram/Statement.png](diagram/Statement.png)

```ebnf
Statement
    ::= ( print | Identifier '=' ) ExpressionList
    | var Identifier ( '=' ExpressionList )
```

aucune référence

## ExpressionList:

![diagram/ExpressionList.png](diagram/ExpressionList.png)

```ebnf
ExpressionList
    ::= Identifier
    | ArithmeticOperatorExpression
    | ComparisonOperatorExpression
```

référencé par:

- Statement

## ArithmeticOperatorExpression:

![diagram/ArithmeticOperatorExpression.png](diagram/ArithmeticOperatorExpression.png)

```ebnf
ArithmeticOperatorExpression
    ::= ( Number | Identifier ) ( '*' | '+' | '-' | '/' | '=' | '%' ) ( Number | Identifier )
```

référencé par:

- ExpressionList

## ComparisonOperatorExpression:

![diagram/ComparisonOperatorExpression.png](diagram/ComparisonOperatorExpression.png)

```ebnf
ComparisonOperatorExpression
    ::= ( Number | Identifier ) ( '==' | '>' | '>=' | '<' | '<=' | '!=' ) ( Number | Identifier )
```

référencé par:

- ExpressionList

## Identifier:

![diagram/Identifier.png](diagram/Identifier.png)

```ebnf
Identifier
    ::= [a-zA-Z_] [a-zA-Z0-9_]+
```

référencé par:

- ArithmeticOperatorExpression
- ComparisonOperatorExpression
- ExpressionList
- Statement

## Number:

![diagram/Number.png](diagram/Number.png)

```ebnf
Number
    ::= [0-9]+
```

référencé par:

- ArithmeticOperatorExpression
- ComparisonOperatorExpression
