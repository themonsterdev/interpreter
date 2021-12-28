# Interpréteur

[Documentation](https://themonsterdev.github.io/interpreter)

Ce programme montre comment créer un interpréteur pour un langage de programmation. Il utilise le modèle de conception Intepreter [Gang of Four](https://en.wikipedia.org/wiki/Interpreter_pattern) pour implémenter un langage simple. Il est écrit en C++ et se compile sous `Windows`, `Linux`, `MacOs`.

L'interpréteur peux interpréter:

- Déclaration (`'print {ExpressionList}'`).
- Définition de variable (`'var identfier'`).
- Assignation de variable (`'var identfier = {ExpressionList}' | 'identfier = {ExpressionList}'`).
- Opérateurs
    - Arithmétiques (`'*' | '+' | '-' | '/' | '%'`).
    - Comparaison (`'==' | '>' | '>=' | '<' | '<=' | '!='`).

## Pré-requis

|                                          |               |
| ---------------------------------------- | ------------- |
| [CMake (Compilation)](https://cmake.org) | `13.22.1`     |

## Instructions

Faire un clone de ce dépôt:

```bash
$ git clone https://github.com/themonsterdev/interpreter.git
```

Ensuite, accédez au répertoire de `build` et exécutez `CMake` pour configurer le projet et générer un système de build natif :

```bash
$ cd interpreter/build
$ cmake --preset=default
```

Ensuite, appelez ce système de construction pour compiler le projet :

```bash
$ cmake --build --preset=default
```

Enfin, essayez d'utiliser l'interpréteur nouvellement construit avec ces exemples de scripts:

```bash
$ ./default/Interpreter/Debug/Interpreter.exe -h
$ ./default/Interpreter/Debug/Interpreter.exe -f ../examples/comparison.lsp
$ ./default/Interpreter/Debug/Interpreter.exe -f ../examples/identifier.lsp
$ ./default/Interpreter/Debug/Interpreter.exe -f ../examples/operator.lsp
$ ./default/Interpreter/Debug/Interpreter.exe -f ../examples/print.lsp
$ ./default/Interpreter/Debug/Interpreter.exe -f ../examples/variable.lsp
```

## Doxygen

[Doxygen Documentation](https://www.doxygen.nl/manual/index.html)

- [Mscgen](http://www.mcternan.me.uk/mscgen)
- [Dia](http://dia-installer.de)
- [Graphviz](https://graphviz.org)
- [Plantuml](https://plantuml.com/fr)
- [Emoji](https://gist.github.com/rxaviers/7360908)

## Wikipedia

- [Interpreter](https://fr.wikipedia.org/wiki/Interpr%C3%A8te_(informatique))
    - [Interpréteur (patron de conception)](https://en.wikipedia.org/wiki/Interpreter_pattern)
- [Analyse lexicale](https://fr.wikipedia.org/wiki/Analyse_lexicale)
- [Analyse syntaxique](https://fr.wikipedia.org/wiki/Analyse_syntaxique)
- [Arbre de la syntaxe abstraite](https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite)

## Resources

- [Implémentation de l'interpréteur en C++](https://github.com/jamesdhutton/Interpreter)

## Liens utiles

- [Railroad Diagram Generator](https://www.bottlecaps.de/rr/ui)

## Licence

Le code est open source sous licence [MIT](LICENSE).
