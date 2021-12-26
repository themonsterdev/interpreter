# EBNF

## Statement:

![Statement.png](Statement.png)

```ebnf
Statement
    ::= ( print | Identifier '=' ) ExpressionList
    | var Identifier ( '=' ExpressionList )
```

aucune référence

## ExpressionList:

![ExpressionList.png](ExpressionList.png)

```ebnf
ExpressionList
    ::= Identifier
    | ArithmeticOperatorExpression
    | ComparisonOperatorExpression
```

référencé par:

- Statement

## ArithmeticOperatorExpression:

![ArithmeticOperatorExpression.png](ArithmeticOperatorExpression.png)

```ebnf
ArithmeticOperatorExpression
    ::= ( Number | Identifier ) ( '*' | '+' | '-' | '/' | '=' | '%' ) ( Number | Identifier )
```

référencé par:

- ExpressionList

## ComparisonOperatorExpression:

![ComparisonOperatorExpression.png](ComparisonOperatorExpression.png)

```ebnf
ComparisonOperatorExpression
    ::= ( Number | Identifier ) ( '==' | '>' | '>=' | '<' | '<=' | '!=' ) ( Number | Identifier )
```

référencé par:

- ExpressionList

## Identifier:

![Identifier.png](Identifier.png)

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

![Number.png](Number.png)

```ebnf
Number
    ::= [0-9]+
```

référencé par:

- ArithmeticOperatorExpression
- ComparisonOperatorExpression
