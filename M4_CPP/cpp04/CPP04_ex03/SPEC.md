# SPEC.md — [CPP04] [ex03] : Interface & recap

## 1. Objectif, avec mes mots
Créer un système de Materias (Ice et Cure) que des personnages peuvent apprendre, créer, équiper et utiliser.

Comprendre comment utiliser :

- Les classes abstraites.
- Les interfaces en C++ (classes abstraites pures).
- Le polymorphisme.
- Le clonage d'objets.
- La copie profonde et la gestion de la mémoire.

## 2. Notions à apprendre

- Interfaces : classes contenant des méthodes virtuelles pures.
- Classes abstraites : empêcher l'instanciation d'une classe.
- Héritage et polymorphisme.
- `virtual` et `= 0`.
- `clone()` : créer une copie d'un objet sans connaître son type réel.
- Copie profonde : dupliquer les objets pointés.
- Destructeurs virtuels.
- Gestion des pointeurs et de la mémoire dynamique.
- Composition : une classe qui possède des objets d'une autre classe.

## 3. Fichiers à rendre

- Makefile
- main.cpp
- AMateria.hpp / AMateria.cpp
- Ice.hpp / Ice.cpp
- Cure.hpp / Cure.cpp
- ICharacter.hpp
- Character.hpp / Character.cpp
- IMateriaSource.hpp
- MateriaSource.hpp / MateriaSource.cpp

## 4. Classes demandées

| Classe         | Rôle                                  | Hérite de      | Méthodes clés                        |
| -------------- | ------------------------------------- | -------------- | ------------------------------------ |
| AMateria       | Classe abstraite de base des Materias | —              | getType(), clone(), use()            |
| Ice            | Materia de type ice                   | AMateria       | clone(), use()                       |
| Cure           | Materia de type cure                  | AMateria       | clone(), use()                       |
| ICharacter     | Interface d'un personnage             | —              | getName(), equip(), unequip(), use() |
| Character      | Personnage avec un inventaire         | ICharacter     | getName(), equip(), unequip(), use() |
| IMateriaSource | Interface d'une source de Materias    | —              | learnMateria(), createMateria()      |
| MateriaSource  | Apprendre et créer des Materias       | IMateriaSource | learnMateria(), createMateria()      |

## 5. Comportements exigés par le sujet

### AMateria

- Possède un attribut `type`.
- Fournit `getType()`.
- Possède une méthode virtuelle pure `clone()`.
- Possède une méthode virtuelle `use()`.

### Ice et Cure

- Ice possède le type `"ice"`.
- Cure possède le type `"cure"`.
- `clone()` retourne une nouvelle instance du même type.
- `Ice::use()` affiche : `* shoots an ice bolt at NAME *`
- `Cure::use()` affiche : `* heals NAME's wounds *`

### Character

- Possède un nom.
- Possède un inventaire de 4 Materias maximum.
- L'inventaire est vide à la construction.
- Équipe les Materias dans le premier emplacement libre (de 0 à 3).
- Ne fait rien si l'inventaire est plein.
- `unequip()` retire une Materia sans la supprimer.
- `use()` utilise la Materia présente dans le slot demandé.
- Ne fait rien si le slot est invalide ou vide.
- La copie d'un Character doit être profonde.
- Supprime ses Materias à la destruction.

### MateriaSource

- Peut apprendre 4 Materias maximum.
- Copie les Materias reçues avec `learnMateria()`.
- Peut créer une nouvelle Materia avec `createMateria(type)`.
- Retourne une copie de la Materia apprise correspondant au type demandé.
- Retourne `0` si le type est inconnu.

## 6. Contraintes spécifiques à cet exercice

- Respecter le standard C++98.
- Respecter la forme canonique orthodoxe pour les classes concernées.
- `ICharacter` et `IMateriaSource` sont des interfaces.
- `AMateria` est une classe abstraite.
- Utiliser des destructeurs virtuels lorsque nécessaire.
- Les inventaires sont limités à 4 emplacements.
- Les copies de Character doivent être profondes.
- Ne jamais supprimer une Materia dans `unequip()`.
- Éviter les fuites mémoire et les doubles suppressions.
- Le système doit pouvoir gérer n'importe quel type de `AMateria`.

## 7. Ce que je NE fais PAS

- Rien de plus que le sujet.
- Pas de fonctionnalités supplémentaires.
- Pas de classes inutiles.
- Pas de fonctionnalités C++11 ou supérieures.
- Pas de gestion complexe des Materias laissées au sol : choisir une solution simple qui évite les fuites mémoire.

## 8. Ordre de travail

1. Créer tous les fichiers `.hpp` avec les déclarations uniquement.
2. Définir les relations entre les classes et les interfaces.
3. Implémenter `AMateria`.
4. Implémenter `Ice` et `Cure`.
5. Implémenter et tester `Character`.
6. Implémenter et tester `MateriaSource`.
7. Tester les copies profondes.
8. Tester les cas limites (inventaire plein, slot vide, type inconnu).
9. Vérifier les fuites mémoire avec Valgrind.
10. Vérifier la compilation et la Norminette applicable.
