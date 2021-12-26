# Interpréteur

[Documentation](https://themonsterdev.github.io/interpreter)

Ce programme montre comment créer un interpréteur pour un langage de programmation. Il utilise le modèle de conception Intepreter [Gang of Four](https://en.wikipedia.org/wiki/Interpreter_pattern) pour implémenter un langage simple. Il est écrit en C++ et se compile sous `Windows`, `Linux`, `MacOs`.

L'interpréteur peux interpréter:

- Déclaration de variable (`'var'`).
- Assignation de variable (`'var identfier = {ExpressionList}' | 'identfier = {ExpressionList}'`).
- Opérateurs arithmétiques (`'*' | '+' | '-' | '/' | '%'`).
- Opérateurs de comparaison (`'==' | '>' | '>=' | '<' | '<=' | '!='`).
- Imprimer le résultat (`'print'`).

## Diagram

### Interpréteur

![https://fr.wikipedia.org/wiki/Diagramme_syntaxique](doxygen/diagram/interpreter-diagram.png)

### AST (Arbre de la syntaxe abstraite)

![https://fr.wikipedia.org/wiki/Diagramme_syntaxique](doxygen/diagram/ast-diagram.png)

## Pré-requis

- [CMake (Compilation)](https://cmake.org) `13.22.1`.
- **[Optionnel]** [Doxygen (Documentation)](https://www.doxygen.nl/index.html) `1.9.2`.
- **[Optionnel]** [Graphviz (Diagram)](http://graphviz.org) `2.50.0`.

## Instructions

Faire un clone de ce dépôt:

```bash
$ git clone https://github.com/themonsterdev/interpreter.git
```

Naviguer vers le répertoire du référentiel cloné:

```bash
$ cd interpreter
```

Exécutez `CMake` pour configurer le projet et générer un système de construction natif:

```bash
$ cmake --preset=default
```

Ensuite, appelez ce système de construction pour compiler le projet:

```bash
$ cmake --build --preset=default
```

Enfin, essayez d'utiliser l'interpréteur nouvellement construit avec ces exemples de scripts:

```bash
$ ./build/default/interpreter.exe -h
$ ./build/default/interpreter.exe -f ./examples/comparison.lsp
$ ./build/default/interpreter.exe -f ./examples/identifier.lsp
$ ./build/default/interpreter.exe -f ./examples/operator.lsp
$ ./build/default/interpreter.exe -f ./examples/print.lsp
$ ./build/default/interpreter.exe -f ./examples/variable.lsp
```

## Exemple

exemple.lsp:

```js
print 1 + 1

var identifier = 1 + 1
print identifier

identifier = 2 - 1
print identifier

identifier = 2 * 3
print identifier

identifier = 6 / 3
print identifier

identifier = 6 % 2
print identifier

identifier = 1 + 1 - 1 * 2 / 2 % 2
print identifier
```

## Réréfences

- [Interpreter](https://fr.wikipedia.org/wiki/Interpr%C3%A8te_(informatique))
    - [Interpréteur (patron de conception)](https://en.wikipedia.org/wiki/Interpreter_pattern)
    - [Implémentation de l'interpréteur en C++](https://github.com/jamesdhutton/Interpreter)
- [Analyse lexicale](https://fr.wikipedia.org/wiki/Analyse_lexicale)
- [Analyse syntaxique](https://fr.wikipedia.org/wiki/Analyse_syntaxique)
- [Arbre de la syntaxe abstraite](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite)

## Resources

- [Railroad Diagram Generator](https://www.bottlecaps.de/rr/ui)

## Licence

Le code est open source sous licence [MIT](./LICENSE).
