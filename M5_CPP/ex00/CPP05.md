CPP05 · ex00 → ex03 · Répétition et Exceptions · environ 12 h

# Le livre CPP05

**📌 À ne pas oublier**

Ta méthode est enregistrée dans la compétence `livre-apprentissage-42`. **Garde-la activée.**

**Où la trouver :** dans Claude, **Customize → Skills** → `livre-apprentissage-42` (interrupteur activé).

[Aide : les compétences ↗](https://support.claude.com/en/articles/12512180-use-skills-in-claude)

Objectif

Des bureaucrates qui signent et exécutent des formulaires, et qui lancent une alarme (exception) quand quelque chose est interdit.

Où tu en es

Intro.

Prochaine action

Page 3 : l'histoire de l'administration.

**4 exercices**ex00 ≈ 4 h · ex01 ≈ 2 h · ex02 ≈ 4 h · ex03 ≈ 2 h

0 / 0

Sommaire

## Toutes les pages du livre

Clique sur une page pour y aller. ✓ = page cochée « faite et comprise ».

Méthode · compétence livre-apprentissage-42

## La méthode du livre d'apprentissage 42

**🚀 Pour démarrer un nouveau projet**

Écris à Claude :

```
Utilise ma compétence livre-apprentissage-42 pour me faire
le livre du [MODULE exNN]. Voici le sujet, la grille et le modèle.
```

Joins : le sujet (PDF), la grille de correction, ce modèle, et tes CLAUDE.md / SPEC.md / NOTES.md si tu en as.

**1. Règles de fond**

- Jamais le code de l'exercice. Code complet seulement si j'écris « donne-moi le code ».
- Phrases courtes. Une phrase = une idée. Mots simples.
- Toujours une **histoire** et des images concrètes (sac à poches, livre de recettes, photocopieuse, boîte et étiquette).
- Claude se relit comme une débutante : chaque mot technique est expliqué, avec un exemple.
- Claude conteste mes choix quand c'est faux et signale ce qui serait refusé en évaluation.
- Fin de chaque réponse : **Objectif / Étape actuelle / Prochaine action**.
- Si je pose une question : réponse, puis on reprend au même endroit.
- Aucun identifiant personnel dans les fichiers.

**2. Avant de construire**

1. Lire le sujet, la grille et mes fichiers de projet. Le sujet et la grille ont le dernier mot.
2. Trouver l'histoire du sujet et son vrai but caché.
3. Me proposer le plan (la liste des pages). On construit seulement après mon « go ».

**3. Structure du livre (une page = une fonction)**

1. **Intro** : l'histoire, le rôle de chaque classe, la carte, le main du sujet en blocs.
2. **Squelette** : .hpp / .cpp, `#include` ou `class X;`, chaque .hpp, compiler (avec `(void)nom;` et des `return` provisoires).
3. **Un chapitre par .cpp**, dans l'ordre de codage. Les pages suivent **l'ordre du .hpp**.
4. **Tests** : le main du sujet + un main simple, tout dans `main`, vérifié avec valgrind.
5. **Récap des messages d'erreur** : un tableau Fichier / Fonction / Quand / ligne `std::cerr`.
6. **Annexe** : grille, fiche de soutenance, erreurs fréquentes, main annoté.

Les notions arrivent **dans la page qui en a besoin**. Pas d'allers-retours.

**4. Format d'une page**

🎮 histoire · 📖 mots nouveaux · ✅ étapes · 🎒 exemple · ⚠️ piège · 💡 astuce · 💬 message d'erreur · ✍️ à toi · 🔒 pseudo-code verrouillé · ❓ question · ☐ case à cocher.

Plus : une table 🌍 traductions anglais → français, une ligne 🗣️ « Se lit » pour chaque déclaration nouvelle, un rappel 📏 convention quand on nomme quelque chose, et des schémas mémoire pour les pointeurs et les copies.

**5. Technique**

- Une page visible à la fois, sommaire cliquable avec ✓, menu ← →, progression gardée dans le navigateur.
- Après chaque changement : republier la page et me renvoyer `ROADMAP.html` pour mon dossier.
- Dans mon CLAUDE.md : « ne jamais montrer les blocs Déverrouiller avant que j'aie montré mon pseudo-code ».

**6. Pendant que je code**

- Claude lit mon code, trouve le problème principal, explique, donne un indice. Pas la correction.
- Erreur de compilation : traduite en français simple, avec où regarder.
- Comportement bizarre : lldb (`-g`, b, r, n, s, p, up, bt).
- Une page floue ou fausse : Claude le reconnaît et la corrige.
- À la fin : grille, simulation de défense (5 questions), tests qui cassent le code.

Méthode · à garder sous la main

## Conventions et lecture du code

**🎮 L'idée**

Une **convention**, c'est une habitude que tout le monde suit. Le compilateur s'en moque, mais le correcteur la remarque.

Suivre les conventions, c'est rendre ton code facile à lire pour les autres.

**📏 Les noms**

| Quoi | Convention | Exemple |
| --- | --- | --- |
| Classe | Majuscule à chaque mot | `Character`, `MateriaSource` |
| Classe abstraite | préfixe `A` | `AMateria` |
| Interface | préfixe `I` | `ICharacter` |
| Attribut `private` / `protected` | `_` devant, puis minuscule | `_name`, `_recipePages` |
| Fonction, variable, paramètre | minuscule, puis Majuscule à chaque mot | `getName`, `createMateria` |
| Getter / setter | `get` + nom / `set` + nom | `getType()`, `setName()` |
| Garde d'inclusion | MAJUSCULES + `_HPP` | `ICE_HPP` |
| Fichiers | le nom de la classe | `Ice.hpp` + `Ice.cpp` |
| Paramètre d'une copie | `other` (ou `src`, `copy`) | `Character(Character const & other)` |

**📖 Pourquoi le `_` devant les attributs ?**

- Ce n'est **pas obligatoire** : c'est une convention, très utilisée à 42.
- Ça permet de voir tout de suite : `_name` = l'attribut de l'objet, `name` = le paramètre reçu.
- Exemple : `_name = name;` → « je range le nom reçu dans mon attribut ».

**⚠️ Piège**

Jamais deux `__`, ni `_` suivi d'une majuscule (`_Name`). Ces noms sont réservés au C++.

**🗣️ Lire une déclaration à voix haute**

**La règle :** on lit **de droite à gauche**, en partant du nom.

- `*` se lit « **pointeur vers** »
- `&` se lit « **référence vers** »
- `const` se lit « **constant** » (on ne peut pas le modifier)

| Ce que tu écris | Ça se lit |
| --- | --- |
| `int x` | x est un int |
| `int* p` | p est un pointeur vers un int (p contient une adresse) |
| `int& r` | r est une référence vers un int (un 2ᵉ nom pour la même variable) |
| `const int& v` | v est une référence vers un int constant |
| `int const & v` | pareil : v est une référence vers un int constant |
| `const int* p` | p est un pointeur vers un int constant (on ne peut pas changer la valeur) |
| `int* const p` | p est un pointeur constant vers un int (on ne peut pas changer l'adresse) |
| `AMateria* _inventory[4]` | \_inventory est un tableau de 4 pointeurs vers AMateria |

**⚠️ Le piège du `&` : deux sens différents**

- **Dans une déclaration** (avec un type devant) : `int& r` → « référence vers ».
- **Dans une expression** (devant une variable) : `&x` → « l'**adresse** de x ». Par exemple : `if (this == &other)`.

**💡 Pourquoi `const int&` partout dans les paramètres ?**

- `&` : on ne **copie** pas l'objet, on le prête. C'est plus rapide.
- `const` : la fonction promet de **ne pas le modifier**. C'est plus sûr.
- Donc : « je te prête mon objet, en lecture seule ».

**🗣️ Les fonctions classiques, lues à voix haute**

| Ce que tu écris | Ça se lit |
| --- | --- |
| `std::string const & getName() const;` | getName renvoie une référence vers une string constante. Le `const` de la fin : elle ne modifie pas l'objet. |
| `Character(Character const & other);` | constructeur de copie : il reçoit une référence vers un Character constant |
| `Character & operator=(Character const & other);` | l'opérateur = reçoit une référence vers un Character constant, et renvoie une référence vers moi-même |
| `virtual AMateria* clone() const = 0;` | clone est une fonction virtuelle pure, constante, qui renvoie un pointeur vers AMateria |
| `void use(ICharacter& target);` | use reçoit une référence vers un ICharacter (modifiable), et ne renvoie rien |

❓ Question : comment se lit `MateriaSource const & other` ?

other est une référence vers un MateriaSource constant.

- [ ] Page lue et comprise

Intro · 5 min

## L'histoire de l'administration

**🎮 L'histoire**

Imagine une immense administration. Des bureaux, des couloirs, des files d'attente.

Chaque employé est un **bureaucrate**. Il a un nom et une **note** (grade).

La note 1, c'est le grand chef. La note 150, c'est tout en bas.

Les bureaucrates **signent** et **exécutent** des formulaires. Mais seulement s'ils ont la note suffisante.

Si quelqu'un essaie une chose interdite, une **alarme** sonne. En C++, cette alarme s'appelle une **exception**.

| Exercice | Ce que tu ajoutes | La nouvelle idée |
| --- | --- | --- |
| ex00 | `Bureaucrat` | lancer et attraper une exception |
| ex01 | `Form` | deux classes qui se connaissent |
| ex02 | `AForm` + 3 formulaires | classe abstraite : le parent vérifie, l'enfant agit |
| ex03 | `Intern` | tableau de pointeurs sur fonctions membres |

**⚠️ Piège**

La note marche à l'envers. **Monter** en grade = le nombre **baisse**. Une note 3 qui monte devient 2.

❓ Question : Un bureaucrate de note 40 veut signer un formulaire qui demande 50. Il peut ?

Oui. 40 est plus haut que 50 (plus petit = plus fort).

- [ ] Page faite et comprise

Intro · 5 min

## La carte des classes

**🎮 L'histoire**

Chaque classe a un seul rôle.

`Bureaucrat` : la personne. `AForm` : le modèle de formulaire. Les 3 formulaires : les vrais papiers. `Intern` : le stagiaire qui remplit les papiers.

**📖 Mots nouveaux**

- **classe concrète** : on peut créer un objet avec (`Bureaucrat bob("Bob", 2);`).
- **classe abstraite** : un modèle incomplet. On ne peut pas créer d'objet avec. Seulement ses enfants.
- **exception** : un objet « alarme » qu'on lance quand une règle est cassée.

classe concrèteclasse abstraite

Les nombres : note pour signer / note pour exécuter.

**💡 Astuce / tu connais déjà**

Tu connais déjà l'héritage et les classes abstraites grâce au CPP04. Ici, c'est la même idée avec `AForm`.

❓ Question : Qui crée les formulaires dans l'ex03 ?

Le stagiaire (`Intern`), avec `makeForm()`.

- [ ] Page faite et comprise

Intro · 5 min

## Les règles du module

**🎮 L'histoire**

Avant de coder, voici les règles qui font perdre des points si on les oublie.

**📖 Mots nouveaux**

- **forme canonique orthodoxe** (OCF) : les 4 fonctions de base qu'une classe doit toujours avoir.

**✅ Étapes**

1. Compiler avec `c++ -Wall -Wextra -Werror -std=c++98`.
2. Chaque classe (sauf les exceptions) en **forme canonique** : constructeur par défaut, copie, `operator=`, destructeur.
3. Aucun code dans les `.hpp`. Gardes d'inclusion partout.
4. Interdits : `printf`, `malloc`, `free`, `using namespace`, `friend`, la STL (`vector`, `map`…).
5. Un `main` avec assez de tests, sinon l'exercice n'est pas noté.

**⚠️ Piège**

Pas de `friend` pour `operator<<`. Il doit utiliser les getters.

**💡 Astuce / tu connais déjà**

Chaque exercice part du précédent. Quand l'ex00 marche : `cp -r ex00 ex01`, puis on ajoute.

- [ ] Page faite et comprise

Chapitre 1 · ex00 · 15 min

## Les fichiers et le Makefile

**🎮 L'histoire**

Le bureau est vide. On pose d'abord les meubles : les fichiers.

**📏 Convention**

Fichiers = nom de la classe : `Bureaucrat.hpp` + `Bureaucrat.cpp`.

**✅ Étapes**

1. Crée le dossier `ex00/`.
2. Crée 4 fichiers : `Makefile`, `main.cpp`, `Bureaucrat.hpp`, `Bureaucrat.cpp`.
3. Dans le Makefile : `CXX = c++` et `CXXFLAGS = -Wall -Wextra -Werror -std=c++98`.
4. Règles : `all`, `clean`, `fclean`, `re`. Nom du programme : celui que tu veux (ex. `bureaucrat`).

**⚠️ Piège**

Un Makefile qui compile avec `g++` ou sans les flags : l'exercice n'est pas noté.

**💡 Astuce / tu connais déjà**

C'est le même Makefile que dans tes modules CPP précédents. Copie-le et change les noms.

- [ ] Page faite et comprise

Chapitre 1 · ex00 · Bureaucrat.hpp · 30 min

## Bureaucrat.hpp : la classe

**🎮 L'histoire**

On écrit la « fiche de poste » du bureaucrate : ce qu'il a, et ce qu'il sait faire.

**📖 Mots nouveaux**

- `std::string const _name;` → 🗣️ **Se lit :** « \_name est une string constante ». Elle ne changera jamais.
- `int _grade;` → la note, de 1 à 150.
- `Bureaucrat(std::string const & name, int grade);` → 🗣️ **Se lit :** « constructeur qui reçoit une référence vers une string constante, et un int ».
- `int getGrade() const;` → 🗣️ **Se lit :** « getGrade renvoie un int. Le `const` de la fin : elle ne modifie pas l'objet ».

**📏 Convention**

Attributs : `_name`, `_grade`. Fonctions : `getName`, `getGrade`, `incrementGrade`, `decrementGrade`.

**🌍 Traductions (anglais → français)**

| Dans le code | En français |
| --- | --- |
| `Bureaucrat` | le bureaucrate |
| `name` | le nom |
| `grade` | la note, le rang |
| `increment` / `decrement` | augmenter / diminuer |
| `GradeTooHigh` / `GradeTooLow` | note trop haute / trop basse |

**✅ Étapes**

1. Garde d'inclusion : `BUREAUCRAT_HPP`.
2. `#include <string>` et `#include <iostream>` (pour `std::ostream`). Plus tard : `<exception>`.
3. En `private` : `_name` (constant) et `_grade`.
4. En `public` : les 4 fonctions de la forme canonique, le constructeur (nom, note), les 2 getters, `incrementGrade()`, `decrementGrade()`.
5. **Après** la classe (en dehors) : la déclaration de `operator<<`.

**⚠️ Piège**

`operator<<` n'est **pas** dans la classe. Il est déclaré juste après, dans le même `.hpp`.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
classe Bureaucrat
  privé :
    nom constant (string)
    note (int)
  public :
    constructeur par défaut
    constructeur (nom, note)
    constructeur de copie (référence vers Bureaucrat constant)
    opérateur = (référence vers Bureaucrat constant) -> renvoie moi-même
    destructeur
    getName  -> renvoie référence vers string constante, const
    getGrade -> renvoie int, const
    incrementGrade()   (rien en retour)
    decrementGrade()
    [les 2 classes d'exception : page suivante]
fin de classe

en dehors : operator<< (flux de sortie, Bureaucrat constant) -> renvoie le flux
```

❓ Question : Pourquoi le nom est `const` ?

Le sujet le demande : un bureaucrate ne change jamais de nom.

- [ ] Page faite et comprise

Chapitre 1 · ex00 · Bureaucrat.hpp · 30 min

## Les classes d'exception dans le .hpp

**🎮 L'histoire**

Une exception, c'est une **alarme**. Chaque alarme a sa propre sonnerie.

Ici, deux alarmes : « note trop haute » et « note trop basse ». On les range **dans** la classe Bureaucrat, comme deux boutons rouges sur son bureau.

**🎬 Vidéo**

[Piscine C++ D05 00 : les classes imbriquées ↗](https://www.youtube.com/watch?v=HVjB-tNKZZo) 0:42

Regarde-la avant cette page.

**📖 Mots nouveaux**

- `std::exception` : la classe parent de toutes les alarmes standard (dans `<exception>`).
- **classe imbriquée** : une classe écrite à l'intérieur d'une autre. Nom complet : `Bureaucrat::GradeTooHighException`.
- `what()` : la fonction qui renvoie le texte de l'alarme.
- `virtual const char* what() const throw();` → 🗣️ **Se lit :** « what est virtuelle, constante, promet de ne lancer aucune exception (`throw()`), et renvoie un pointeur vers des char constants ».

**✅ Étapes**

1. Ajoute `#include <exception>`.
2. Dans la partie `public` de Bureaucrat, écris la classe `GradeTooHighException`, qui hérite publiquement de `std::exception`.
3. Dedans, en public : seulement la déclaration de `what()` (signature ci-dessus).
4. Fais pareil pour `GradeTooLowException`.

**⚠️ Piège**

Oublier `throw()` à la fin de `what()` → erreur « looser throw specifier ». En C++98, l'enfant doit promettre au moins autant que `std::exception`.

**⚠️ Piège**

Pas de `noexcept` ni `override` : c'est du C++11, interdit.

**💡 Astuce / tu connais déjà**

Le sujet le dit : les classes d'exception **n'ont pas besoin** de la forme canonique.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
dans la partie public de Bureaucrat :
  classe GradeTooHighException, enfant public de std::exception
    public : what() virtuelle, const, throw(), renvoie const char*
  fin
  classe GradeTooLowException, pareil
  fin
```

❓ Question : Pourquoi hériter de `std::exception` ?

Pour pouvoir attraper l'alarme avec `catch (std::exception & e)`. La grille le vérifie.

- [ ] Page faite et comprise

Chapitre 1 · ex00 · Bureaucrat.cpp · 20 min

## Compiler le squelette

**🎮 L'histoire**

Les meubles sont posés. On vérifie que la porte s'ouvre : ça compile ?

**📖 Mots nouveaux**

- **liste d'initialisation** : le `: _name(name), _grade(grade)` écrit entre la `)` et le `{` du constructeur. C'est le seul endroit où on peut remplir un attribut `const`.

**✅ Étapes**

1. Dans `Bureaucrat.cpp` : `#include "Bureaucrat.hpp"`.
2. Écris toutes les fonctions avec un corps vide `{ }`.
3. Paramètre pas encore utilisé → `(void)nom;` (sinon `unused parameter` avec -Wextra -Werror).
4. Fonction qui renvoie quelque chose → `return` provisoire (ex. `return _grade;`, `return *this;`).
5. Le constructeur doit quand même initialiser `_name` (il est `const`) : liste d'initialisation obligatoire.
6. `main.cpp` avec un `main` vide qui renvoie 0. Puis `make`.

```
🎒 Bureaucrat::getGrade      -> return _grade;
Bureaucrat::operator=     -> return *this;
GradeTooHighException::what -> return "";
```

**⚠️ Piège**

Les noms complets ! Dans le .cpp : `Bureaucrat::getGrade`, et pour what : `Bureaucrat::GradeTooHighException::what`.

❓ Question : Pourquoi on ne peut pas écrire `_name = name;` dans les `{ }` ?

Parce que `_name` est constant : il est déjà « fabriqué » quand on entre dans `{ }`. On ne peut plus le changer.

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 10 min

## Constructeur par défaut

**🎮 L'histoire**

Un bureaucrate sans nom ni note arrive. On lui donne des valeurs de départ sûres.

**✅ Étapes**

1. Liste d'initialisation : nom `"Default"`, note `150` (la plus basse).
2. Optionnel : un `std::cout` « Bureaucrat default constructor called ».

```
🎒 Bureaucrat b;
-> [ nom: "Default" | note: 150 ]
```

**💡 Astuce / tu connais déjà**

150 est toujours valide. Pas besoin de vérifier.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
constructeur par défaut :
  nom <- "Default"   (dans la liste d'initialisation)
  note <- 150
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 30 min

## Constructeur (nom, note) : lancer l'alarme

**🎮 L'histoire**

Un nouveau bureaucrate arrive avec une note. Le gardien vérifie.

Note 0 ou 151 ? Le gardien **lance l'alarme**. Le bureaucrate n'est jamais créé.

**🎬 Vidéo**

[Piscine C++ D05 01 : les exceptions ↗](https://www.youtube.com/watch?v=BIs4BRM7s-s) 8:42

Regarde-la avant cette page.

**📖 Mots nouveaux**

- `throw` : lancer l'alarme. Exemple : `throw GradeTooHighException();` → on crée un objet alarme et on le lance.
- Quand on `throw`, la fonction s'arrête **tout de suite**. Le code d'après n'est pas exécuté.
- Un constructeur qui lance → l'objet n'existe pas. Son destructeur ne sera pas appelé.

**✅ Étapes**

1. Liste d'initialisation : `_name` reçoit `name`, `_grade` reçoit `grade`.
2. Dans `{ }` : si la note est plus petite que 1 → lancer `GradeTooHighException`.
3. Si la note est plus grande que 150 → lancer `GradeTooLowException`.

Le reste du bloc `try` est sauté. Le programme reprend dans le `catch`.

```
🎒 Bureaucrat("Bob", 0)   -> throw TooHigh   (0 est « au-dessus » de 1)
Bureaucrat("Bob", 151) -> throw TooLow
Bureaucrat("Bob", 42)  -> [ Bob | 42 ] créé
```

**⚠️ Piège**

Note **trop petite** (0) = trop **haute**. Ne mélange pas les deux alarmes.

**💡 Astuce / tu connais déjà**

Pour éviter les nombres magiques, tu peux écrire 1 et 150 une seule fois (constantes `static const int` dans la classe, ou `#define`). Au choix.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
constructeur (nom, note) :
  liste d'initialisation : nom <- nom, note <- note
  si note < 1   : lancer GradeTooHighException
  si note > 150 : lancer GradeTooLowException
```

❓ Question : Pourquoi on lance un objet `GradeTooHighException()` avec des parenthèses ?

On crée l'objet alarme sur place, puis on le lance. On lance **par valeur**, on attrape **par référence**.

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 10 min

## Constructeur de copie

**🎮 L'histoire**

La photocopieuse : on fabrique un nouveau bureaucrate identique à un autre.

**📖 Mots nouveaux**

- `Bureaucrat(Bureaucrat const & other);` → 🗣️ **Se lit :** « constructeur de copie : il reçoit une référence vers un Bureaucrat constant ».

**📏 Convention**

Le paramètre s'appelle `other`.

**✅ Étapes**

1. Liste d'initialisation : `_name` reçoit le nom de `other`, `_grade` reçoit sa note.
2. Pas besoin de vérifier la note : `other` est déjà valide.

```
🎒 Bureaucrat a("Ana", 10);
Bureaucrat b(a);
-> a: [ Ana | 10 ]   b: [ Ana | 10 ]
```

**💡 Astuce / tu connais déjà**

Ici, c'est un **constructeur** : on peut remplir le nom `const` dans la liste d'initialisation. Ce ne sera pas le cas dans `operator=`.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
copie (other) :
  liste d'initialisation : nom <- nom de other, note <- note de other
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 20 min

## operator= : le piège du nom constant

**🎮 L'histoire**

`a = b;` : `a` existe déjà. Il prend les infos de `b`.

Mais le nom de `a` est gravé dans la pierre. On ne peut copier **que la note**.

**📖 Mots nouveaux**

- `Bureaucrat & operator=(Bureaucrat const & other);` → 🗣️ **Se lit :** « l'opérateur = reçoit une référence vers un Bureaucrat constant, et renvoie une référence vers moi-même ».
- `this` : l'adresse de l'objet sur lequel on travaille. `*this` : l'objet lui-même.
- `&other` : l'adresse de other (ici `&` est dans une expression).

**✅ Étapes**

1. Si `this` est différent de `&other` (pas « moi = moi ») : copier la note de `other`.
2. Ne pas toucher au nom.
3. Renvoyer `*this`.

```
🎒 a: [ Ana | 10 ]   b: [ Bob | 3 ]
a = b;
a: [ Ana | 3 ]   (le nom reste Ana)
```

**⚠️ Piège**

Écrire `_name = other._name;` → erreur de compilation (le nom est `const`). C'est **normal**. En soutenance, explique ce choix.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
operator= (other) :
  si moi n'est pas other :
    note <- note de other
    (le nom est constant : on ne le copie pas)
  renvoyer moi-même
```

❓ Question : Un évaluateur demande : « pourquoi ton = ne copie pas le nom ? »

Parce que `_name` est `const` (exigé par le sujet). On ne peut le remplir qu'à la construction.

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 5 min

## Destructeur

**🎮 L'histoire**

Le bureaucrate quitte le bâtiment. Il n'a rien emprunté : rien à rendre.

**✅ Étapes**

1. Corps vide (ou un message `std::cout` si tu veux suivre les appels).

**💡 Astuce / tu connais déjà**

Pas de `new` dans Bureaucrat, donc pas de `delete`.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
destructeur :
  rien à libérer
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 10 min

## getName et getGrade

**🎮 L'histoire**

Les guichets d'information : on demande le nom ou la note, sans rien changer.

**📖 Mots nouveaux**

- `std::string const & getName() const;` → 🗣️ **Se lit :** « getName renvoie une référence vers une string constante, et ne modifie pas l'objet ».

**📏 Convention**

Getter = `get` + nom de l'attribut sans `_`. Toujours `const` à la fin.

**✅ Étapes**

1. `getName` renvoie `_name`.
2. `getGrade` renvoie `_grade`.

**⚠️ Piège**

Oublier le `const` de la fin → tu ne pourras pas appeler le getter sur un `Bureaucrat const &` (ex. dans `operator<<`).

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
getName  : renvoyer le nom
getGrade : renvoyer la note
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 20 min

## incrementGrade et decrementGrade

**🎮 L'histoire**

Promotion : le bureaucrate monte d'un rang. Sa note **baisse** de 1.

Rétrogradation : il descend d'un rang. Sa note **monte** de 1.

Le chef (note 1) ne peut pas monter plus haut. Alarme !

**✅ Étapes**

1. `incrementGrade` : si la note est déjà 1 → lancer `GradeTooHighException`. Sinon, note moins 1.
2. `decrementGrade` : si la note est déjà 150 → lancer `GradeTooLowException`. Sinon, note plus 1.
3. Vérifier **avant** de changer la note.

```
🎒 [ Bob | 3 ]   incrementGrade()  -> [ Bob | 2 ]
[ Bob | 1 ]   incrementGrade()  -> throw TooHigh, la note reste 1
[ Bob | 150 ] decrementGrade()  -> throw TooLow
```

**⚠️ Piège**

Changer la note puis vérifier → la note devient 0 avant l'alarme. Si on attrape l'alarme, l'objet est cassé.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
incrementGrade :
  si note - 1 < 1 : lancer GradeTooHighException
  note <- note - 1

decrementGrade :
  si note + 1 > 150 : lancer GradeTooLowException
  note <- note + 1
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 10 min

## Le texte des alarmes : what()

**🎮 L'histoire**

Chaque alarme affiche un petit panneau qui dit ce qui s'est passé.

**📖 Mots nouveaux**

- `const char* Bureaucrat::GradeTooHighException::what() const throw()` → 🗣️ **Se lit :** « la fonction what de l'alarme GradeTooHigh rangée dans Bureaucrat ».

**✅ Étapes**

1. `what` de TooHigh renvoie un texte comme `"Bureaucrat: grade too high"`.
2. `what` de TooLow renvoie `"Bureaucrat: grade too low"`.

**⚠️ Piège**

Ne renvoie pas `std::string(...).c_str()` : la string meurt à la fin de la fonction, le pointeur devient invalide. Un texte entre guillemets direct, c'est sûr.

**💬 Message d'erreur**

```
TooHigh : "Bureaucrat: grade too high"
TooLow  : "Bureaucrat: grade too low"
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
what (TooHigh) : renvoyer le texte "Bureaucrat: grade too high"
what (TooLow)  : renvoyer le texte "Bureaucrat: grade too low"
```

- [ ] Page faite et comprise

Chapitre 2 · ex00 · Bureaucrat.cpp · 15 min

## operator\<\< : afficher un bureaucrate

**🎮 L'histoire**

On veut écrire `std::cout << bob;` et voir sa carte de visite.

**📖 Mots nouveaux**

- `std::ostream & operator<<(std::ostream & out, Bureaucrat const & b);` → 🗣️ **Se lit :** « operator\<\< reçoit une référence vers un flux de sortie, et une référence vers un Bureaucrat constant. Il renvoie le flux ».
- **flux** (`std::ostream`) : un tuyau où on verse du texte. `std::cout` en est un.

**✅ Étapes**

1. C'est une fonction **libre** : pas de `Bureaucrat::` devant.
2. Verser dans `out` : le nom, `", bureaucrat grade "`, la note, `"."`.
3. Utiliser les getters (pas `friend`).
4. Renvoyer `out` (pour pouvoir enchaîner : `std::cout << a << b`).

```
🎒 Bureaucrat bob("Bob", 42);
std::cout << bob << std::endl;
-> Bob, bureaucrat grade 42.
```

**⚠️ Piège**

Ne mets pas `std::endl` dans l'opérateur. C'est à celui qui affiche de choisir.

**💡 Astuce / tu connais déjà**

Tu l'as déjà fait au CPP02 avec `Fixed`.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
operator<< (out, b) :
  verser dans out : nom de b, ", bureaucrat grade ", note de b, "."
  renvoyer out
```

- [ ] Page faite et comprise

Chapitre 3 · ex00 · main.cpp · 30 min

## Tester ex00 avec try / catch

**🎮 L'histoire**

On joue au gardien méchant : on essaie toutes les bêtises pour voir si l'alarme sonne.

**📖 Mots nouveaux**

- `try { ... }` : « essaie ce code ». Si une alarme sonne dedans, on saute au `catch`.
- `catch (std::exception & e)` → 🗣️ **Se lit :** « attrape toute alarme qui est une std::exception, par référence, et appelle-la e ».
- `e.what()` : lire le panneau de l'alarme.

**✅ Étapes**

1. Un bureaucrate normal : affiche-le avec `<<`.
2. Créer avec note 0, puis avec 151 : chacun dans son propre `try`.
3. Note 2 → `incrementGrade` deux fois : la 2ᵉ doit lancer.
4. Note 149 → `decrementGrade` deux fois : la 2ᵉ doit lancer.
5. Une copie et un `=` : affiche-les.

```
🎒 === Note 0 ===
Bureaucrat: grade too high
=== Increment ===
Bob, bureaucrat grade 1.
Bureaucrat: grade too high
```

**⚠️ Piège**

Un seul gros `try` pour tout → au 1er `throw`, tous les tests suivants sont sautés. Un `try` par test.

**💡 Astuce / tu connais déjà**

Pourquoi par référence `&` ? Pour garder le vrai type de l'alarme (et son vrai `what()`), et ne pas copier l'objet.

**✍️ À toi**

Écris la liste de tes tests dans ton cahier, avec la sortie attendue. Puis code ton main.

🔒 Déverrouiller mon pseudo-code

```
main :
  essayer : créer Bob note 42, l'afficher
  attraper : afficher what
  essayer : créer note 0          -> doit afficher "too high"
  essayer : créer note 151        -> doit afficher "too low"
  essayer : note 2, increment x2  -> afficher après chaque, 2e = alarme
  essayer : note 149, decrement x2
  essayer : copie + =, afficher les deux
```

❓ Question : Après une alarme dans un `try`, la ligne suivante du `try` est exécutée ?

Non. On saute directement au `catch`, puis on continue après le `catch`.

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.hpp · 30 min

## Form.hpp et la boucle d'inclusion

**🎮 L'histoire**

Le bureaucrate reçoit enfin du travail : des formulaires.

Le formulaire doit connaître le bureaucrate (pour vérifier sa note). Le bureaucrate doit connaître le formulaire (pour le signer).

**📖 Mots nouveaux**

- **boucle d'inclusion** : A inclut B, B inclut A → le compilateur tourne en rond.
- `class Bureaucrat;` : **déclaration anticipée**. C'est l'étiquette sans la boîte : « une classe Bureaucrat existe, je te la montrerai plus tard ».
- Ça suffit tant qu'on utilise seulement une **référence** ou un **pointeur** vers Bureaucrat.
- `void beSigned(Bureaucrat const & b);` → 🗣️ **Se lit :** « beSigned reçoit une référence vers un Bureaucrat constant, et ne renvoie rien ».

**📏 Convention**

Attributs : `_name`, `_signed`, `_gradeToSign`, `_gradeToExecute`. Garde : `FORM_HPP`.

**🌍 Traductions (anglais → français)**

| Dans le code | En français |
| --- | --- |
| `Form` | le formulaire |
| `signed` | signé |
| `gradeToSign` | note pour signer |
| `gradeToExecute` | note pour exécuter |
| `beSigned` | être signé |
| `signForm` | signer le formulaire |

**✅ Étapes**

1. `cp -r ex00 ex01`, puis crée `Form.hpp` et `Form.cpp`. Ajoute `Form.cpp` au Makefile.
2. Dans `Form.hpp` : `class Bureaucrat;` en haut (pas d'include).
3. En `private` : nom constant, booléen signé, deux notes **constantes** (int).
4. En `public` : forme canonique, constructeur (nom, note signer, note exécuter), 4 getters, `beSigned`, les 2 exceptions.
5. Après la classe : `operator<<`.
6. Dans `Bureaucrat.hpp` : `class Form;` et la déclaration de `signForm(Form & form)`.
7. Dans les deux `.cpp` : inclure **les deux** `.hpp`.

**⚠️ Piège**

Les attributs doivent être `private`, pas `protected`. La grille le vérifie.

**⚠️ Piège**

`signForm(Form & form)` : **pas** `const`, car signer modifie le formulaire.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
Form.hpp :
  garde FORM_HPP, include string, iostream, exception
  déclaration anticipée : classe Bureaucrat
  classe Form
    privé : nom const, signé (bool), noteSigner const int, noteExecuter const int
    public : défaut, (nom, noteSigner, noteExecuter), copie, =, destructeur
             getName, getSigned (ou isSigned), getGradeToSign, getGradeToExecute (tous const)
             beSigned(Bureaucrat constant &)
             GradeTooHighException, GradeTooLowException (comme ex00)
  operator<< (flux, Form constant)

Bureaucrat.hpp : + déclaration anticipée classe Form
                 + signForm(Form &)
```

❓ Question : Pourquoi `class Bureaucrat;` suffit dans Form.hpp ?

Form.hpp ne parle que d'une **référence** vers Bureaucrat. Le compilateur n'a pas besoin de connaître son contenu pour ça. Le .cpp, lui, inclut le vrai Bureaucrat.hpp.

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.cpp · 20 min

## Constructeurs de Form

**🎮 L'histoire**

Un formulaire vierge sort de l'imprimante. Il n'est jamais signé au départ. Et ses notes doivent être entre 1 et 150.

**✅ Étapes**

1. Défaut : nom `"Default"`, non signé, notes 150 et 150.
2. Avec paramètres : tout remplir dans la liste d'initialisation, `_signed` à `false`.
3. Puis vérifier **les deux** notes : plus petite que 1 → TooHigh, plus grande que 150 → TooLow.

```
🎒 Form("A38", 50, 25)  -> [ A38 | non signé | 50 | 25 ]
Form("A38", 0, 25)   -> throw Form::GradeTooHighException
Form("A38", 50, 151) -> throw Form::GradeTooLowException
```

**💡 Astuce / tu connais déjà**

C'est la même vérification que dans le constructeur de Bureaucrat, mais deux fois.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
défaut : nom "Default", signé faux, notes 150 / 150

constructeur (nom, noteS, noteE) :
  liste d'init : nom, signé <- faux, noteS, noteE
  si noteS < 1 ou noteE < 1     : lancer GradeTooHighException
  si noteS > 150 ou noteE > 150 : lancer GradeTooLowException
```

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.cpp · 15 min

## Copie et operator= de Form

**🎮 L'histoire**

Trois cases sont gravées (nom, deux notes). Seule la case « signé » peut être recopiée.

**✅ Étapes**

1. Copie : liste d'initialisation avec les 4 valeurs de `other`.
2. `operator=` : si ce n'est pas moi-même, copier seulement `_signed`. Renvoyer `*this`.

```
🎒 a: [ A | non signé | 50 | 25 ]   b: [ B | signé | 10 | 5 ]
a = b;
a: [ A | signé | 50 | 25 ]
```

**💡 Astuce / tu connais déjà**

Même logique que `Bureaucrat::operator=` : on ne peut pas copier ce qui est `const`.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
copie (other) : liste d'init avec nom, signé, noteS, noteE de other

operator= (other) :
  si moi n'est pas other : signé <- signé de other
  renvoyer moi-même
```

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.cpp · 10 min

## Destructeur et getters de Form

**🎮 L'histoire**

Les guichets d'information du formulaire.

**📏 Convention**

Pour un booléen, on peut écrire `getSigned()` ou `isSigned()`. Choisis un nom et garde-le.

**✅ Étapes**

1. Destructeur vide.
2. 4 getters `const` : nom, signé, note pour signer, note pour exécuter.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
destructeur : rien
getName, getSigned, getGradeToSign, getGradeToExecute : renvoyer l'attribut
```

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.cpp · 20 min

## beSigned : le formulaire vérifie

**🎮 L'histoire**

Le bureaucrate tend son stylo. Le formulaire regarde sa note.

Note assez haute ? Il devient signé. Sinon : alarme « note trop basse ».

**✅ Étapes**

1. Lire la note du bureaucrate avec `getGrade()`.
2. Si elle est **plus grande** que `_gradeToSign` → lancer `GradeTooLowException`.
3. Sinon : `_signed` passe à `true`.

```
🎒 Form A38 demande 50
Bob (42) -> 42 <= 50 -> signé ✓
Tim (80) -> 80 > 50  -> throw GradeTooLow
```

**⚠️ Piège**

« Assez élevé » = nombre **plus petit ou égal**. Une note égale (50 pour 50) suffit.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
beSigned (b) :
  si note de b > noteSigner : lancer GradeTooLowException
  signé <- vrai
```

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Form.cpp · 15 min

## what() et operator\<\< de Form

**🎮 L'histoire**

Le formulaire a ses propres panneaux d'alarme et sa propre carte de visite.

**✅ Étapes**

1. Deux `what()` avec un texte qui commence par `Form:` (pour savoir qui a sonné).
2. `operator<<` affiche tout : nom, signé ou non, note pour signer, note pour exécuter.

```
🎒 Form A38, signed: no, grade to sign: 50, grade to execute: 25
```

**💡 Astuce / tu connais déjà**

Pour afficher un booléen en mots : `(f.getSigned() ? "yes" : "no")`.

**💬 Message d'erreur**

```
TooHigh : "Form: grade too high"
TooLow  : "Form: grade too low"
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
what (TooHigh) : "Form: grade too high"
what (TooLow)  : "Form: grade too low"

operator<< (out, f) :
  verser : "Form ", nom, ", signed: ", oui/non, ", grade to sign: ", noteS, ", grade to execute: ", noteE
  renvoyer out
```

- [ ] Page faite et comprise

Chapitre 4 · ex01 · Bureaucrat.cpp · 20 min

## Bureaucrat::signForm

**🎮 L'histoire**

Le bureaucrate essaie de signer. S'il réussit, il le dit.

Si ça rate, il attrape l'alarme lui-même et explique pourquoi. Le programme continue.

**📖 Mots nouveaux**

- Ici, `try / catch` est **dans** la fonction. L'alarme ne remonte pas jusqu'au main.
- `*this` : moi, le bureaucrate. On le passe à `beSigned`.

**✅ Étapes**

1. Dans un `try` : appeler `form.beSigned(*this)`.
2. Juste après (toujours dans le `try`) : afficher `<bureaucrat> signed <form>`.
3. Dans le `catch (std::exception & e)` : afficher `<bureaucrat> couldn't sign <form> because <e.what()>.`

```
🎒 Bob signed A38
Tim couldn't sign A38 because Form: grade too low.
```

**⚠️ Piège**

Afficher « signed » **après** l'appel, dans le `try`. Sinon, on l'affiche même quand ça rate.

**💬 Message d'erreur**

```
std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
signForm (form) :
  essayer :
    form.beSigned(moi)
    afficher "<mon nom> signed <nom du form>"
  attraper (exception e) :
    afficher "<mon nom> couldn't sign <nom du form> because <e.what>."
```

- [ ] Page faite et comprise

Chapitre 5 · ex01 · main.cpp · 30 min

## Tester ex01

**🎮 L'histoire**

On imprime des formulaires bizarres et on donne le stylo à des bureaucrates de tous niveaux.

**✅ Étapes**

1. Form valide : l'afficher avec `<<`.
2. Form avec note 0, puis 151 (chacun dans son `try`).
3. Bureaucrat assez fort → `signForm` → « signed ».
4. Bureaucrat trop faible → `signForm` → « couldn't sign… because… ».
5. Afficher le Form après signature : `signed: yes`.

**💡 Astuce / tu connais déjà**

`signForm` attrape déjà l'alarme. Pas besoin de `try` autour de ces appels-là.

**✍️ À toi**

Écris la liste de tes tests et la sortie attendue.

🔒 Déverrouiller mon pseudo-code

```
main :
  essayer : Form valide, afficher
  essayer : Form note 0   -> "Form: grade too high"
  essayer : Form note 151 -> "Form: grade too low"
  boss note 1, stagiaire note 150, form demande 50
  stagiaire.signForm(form)  -> couldn't sign
  boss.signForm(form)       -> signed
  afficher form             -> signed: yes
```

- [ ] Page faite et comprise

Chapitre 6 · ex02 · AForm.hpp · 30 min

## De Form à AForm : classe abstraite

**🎮 L'histoire**

« Formulaire » tout court, ça n'existe pas. On remplit toujours **un** formulaire précis.

Donc `Form` devient un **modèle** : `AForm`. On ne peut plus créer un AForm tout seul.

**📖 Mots nouveaux**

- **fonction virtuelle pure** : `= 0` à la fin. « Chaque enfant DOIT l'écrire. » Une classe qui en a une est abstraite.
- `virtual void executeAction() const = 0;` → 🗣️ **Se lit :** « executeAction est virtuelle pure, constante, et ne renvoie rien ».
- **destructeur virtuel** : `virtual ~AForm();`. Indispensable : on fera `delete` d'un `AForm*` qui pointe vers un enfant (ex03).

**📏 Convention**

Classe abstraite → préfixe `A` : `AForm`.

**✅ Étapes**

1. `cp -r ex01 ex02`. Renomme `Form.hpp/.cpp` en `AForm.hpp/.cpp`. Remplace `Form` par `AForm` partout (garde : `AFORM_HPP`).
2. Les 4 attributs restent `private` dans AForm.
3. Rends le destructeur `virtual`.
4. Ajoute en `public` : `void execute(Bureaucrat const & executor) const;`.
5. Ajoute une fonction virtuelle pure pour l'action (ex. `executeAction() const = 0`). En `protected` ou `private`.
6. Dans Bureaucrat : `signForm(AForm & form)`.

**⚠️ Piège**

La grille écrit `Form::execute`. En ex02 c'est bien `AForm::execute` : le sujet demande de renommer.

**⚠️ Piège**

Pas de corps pour une fonction `= 0` dans le squelette.

**💡 Astuce / tu connais déjà**

Comme `AMateria` au CPP04 : une classe de base abstraite, des enfants concrets.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
AForm.hpp :
  tout Form, renommé AForm
  destructeur virtuel
  public : execute(Bureaucrat constant & executor) const
  protégé : executeAction() const = 0   (virtuelle pure)
  + exception FormNotSignedException (page suivante)
```

❓ Question : Pourquoi `AForm f;` ne compile plus ?

AForm a une fonction virtuelle pure. On ne peut pas créer d'objet d'une classe abstraite.

- [ ] Page faite et comprise

Chapitre 6 · ex02 · AForm.cpp · 30 min

## execute : vérifier, puis déléguer

**🎮 L'histoire**

Le guichet vérifie deux choses : le formulaire est signé ? La personne a la note pour exécuter ?

Si tout est bon, il passe le dossier au bon service (l'enfant).

**📖 Mots nouveaux**

- `FormNotSignedException` : une 3ᵉ alarme, « le formulaire n'est pas signé ». Même forme que les autres.
- **déléguer** : confier le vrai travail à quelqu'un d'autre.

**✅ Étapes**

1. Ajoute la classe `FormNotSignedException` dans AForm (hpp) et son `what()` (cpp).
2. Dans `execute` : si pas signé → lancer `FormNotSignedException`.
3. Si la note de `executor` est plus grande que `_gradeToExecute` → lancer `GradeTooLowException`.
4. Sinon : appeler `executeAction()`.

Le parent vérifie. La fonction virtuelle choisit le bon enfant au moment de l'exécution.

**⚠️ Piège**

Le sujet dit : une des deux méthodes est « plus élégante ». C'est celle-ci : les vérifications sont écrites **une seule fois** dans le parent.

**💬 Message d'erreur**

```
FormNotSigned : "AForm: form is not signed"
TooLow        : "AForm: grade too low"
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
execute (executor) :
  si pas signé : lancer FormNotSignedException
  si note de executor > noteExecuter : lancer GradeTooLowException
  executeAction()   -> la version de l'enfant est appelée
```

❓ Question : Pourquoi `execute` peut être `const` ?

Exécuter ne change pas le formulaire (ni nom, ni signé, ni notes).

- [ ] Page faite et comprise

Chapitre 7 · ex02 · 3 × .hpp · 30 min

## Le squelette des 3 formulaires

**🎮 L'histoire**

Trois vrais formulaires. Chacun a une **cible** (target) : la personne ou le lieu concerné.

**📖 Mots nouveaux**

- `ShrubberyCreationForm(std::string const & target);` → 🗣️ **Se lit :** « constructeur qui reçoit une référence vers une string constante : la cible ».

**🌍 Traductions (anglais → français)**

| Dans le code | En français |
| --- | --- |
| `Shrubbery` | arbustes, buissons |
| `Creation` | création |
| `Robotomy` | robotomie |
| `Request` | demande |
| `Presidential Pardon` | grâce présidentielle |
| `target` | la cible |

**✅ Étapes**

1. Pour chaque classe : `X.hpp` + `X.cpp`, hérite publiquement de `AForm`.
2. Attribut `private` : `_target` (string).
3. Forme canonique + constructeur (target) : **un seul** paramètre.
4. Redéclarer `executeAction() const` (sans `= 0`).
5. Ajouter les 3 `.cpp` au Makefile.

| Classe | Nom passé à AForm | Signer | Exécuter |
| --- | --- | --- | --- |
| `ShrubberyCreationForm` | `ShrubberyCreationForm` | 145 | 137 |
| `RobotomyRequestForm` | `RobotomyRequestForm` | 72 | 45 |
| `PresidentialPardonForm` | `PresidentialPardonForm` | 25 | 5 |

**⚠️ Piège**

Le constructeur prend **seulement** la cible. Les notes sont fixées dans la classe, pas passées par le main.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
pour chaque formulaire X :
  classe X, enfant public de AForm
    privé : cible (string)
    public : défaut, (cible), copie, =, destructeur
  protégé : executeAction() const
```

- [ ] Page faite et comprise

Chapitre 7 · ex02 · ShrubberyCreationForm.cpp · 20 min

## ShrubberyCreationForm : constructeurs

**🎮 L'histoire**

Le formulaire naît avec ses notes déjà imprimées dessus.

**📖 Mots nouveaux**

- **appeler le constructeur du parent** : dans la liste d'initialisation, `AForm("Nom", 145, 137)`. C'est le parent qui remplit ses attributs `private`.

**✅ Étapes**

1. Défaut : appeler `AForm` avec nom et notes, `_target` = `"default"`.
2. (target) : pareil, `_target` = target.
3. Copie : appeler la copie du parent `AForm(other)`, puis copier `_target`.
4. `operator=` : appeler `AForm::operator=(other)`, copier `_target`, renvoyer `*this`.

```
🎒 ShrubberyCreationForm s("home");
-> [ ShrubberyCreationForm | non signé | 145 | 137 ] cible: home
```

**⚠️ Piège**

Un enfant ne peut pas toucher aux attributs `private` du parent. Passe toujours par le constructeur ou l'`operator=` du parent.

**💡 Astuce / tu connais déjà**

Les 2 autres formulaires se font **exactement** pareil. Seuls le nom et les notes changent.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
défaut  : parent("ShrubberyCreationForm", 145, 137), cible <- "default"
(cible) : parent(pareil), cible <- cible
copie   : parent(other), cible <- cible de other
=       : si pas moi : parent = other, cible <- cible de other ; renvoyer moi
```

- [ ] Page faite et comprise

Chapitre 7 · ex02 · ShrubberyCreationForm.cpp · 30 min

## Shrubbery : planter des arbres dans un fichier

**🎮 L'histoire**

Le jardinier crée un fichier `<target>_shrubbery` et y dessine des arbres en ASCII.

**📖 Mots nouveaux**

- `std::ofstream` (dans `<fstream>`) : un tuyau vers un fichier. On y verse du texte comme dans `std::cout`.
- `.c_str()` : transforme une `std::string` en texte C. En C++98, `ofstream` veut ce format.
- `is_open()` : le fichier a bien été ouvert ?

**✅ Étapes**

1. Construire le nom : cible + `"_shrubbery"`.
2. Ouvrir un `std::ofstream` avec ce nom (`.c_str()`).
3. Pas ouvert → lancer une exception (ou un message d'erreur).
4. Verser quelques arbres ASCII dedans.
5. Le fichier se ferme seul à la fin de la fonction (ou `.close()`).

```
🎒 target "home" -> fichier ./home_shrubbery
       /\
      /**\
     /****\
       ||
```

**⚠️ Piège**

`std::ofstream f(nom);` avec une `std::string` → erreur en C++98. Il faut `nom.c_str()`.

**💡 Astuce / tu connais déjà**

Au CPP01 (ex04, « sed is for losers »), tu as déjà écrit dans un fichier.

**💬 Message d'erreur**

```
std::cerr << "Shrubbery: cannot open " << fileName << std::endl;
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
executeAction :
  nomFichier <- cible + "_shrubbery"
  ouvrir le fichier nomFichier en écriture
  si pas ouvert : lancer une exception (ou afficher une erreur)
  écrire des arbres ASCII dans le fichier
```

- [ ] Page faite et comprise

Chapitre 7 · ex02 · RobotomyRequestForm.cpp · 30 min

## RobotomyRequestForm

**🎮 L'histoire**

Un docteur fou. « Bzzzz… vrrrr… » Puis : réussi, ou raté.

Une chance sur deux, comme pile ou face.

**📖 Mots nouveaux**

- `std::rand()` (dans `<cstdlib>`) : un nombre au hasard.
- `std::rand() % 2` : le reste de la division par 2 → 0 ou 1. Pile ou face.
- `std::srand(std::time(NULL))` (`<ctime>`) : mélange le paquet de cartes. À faire **une seule fois**, au début du `main`.

**✅ Étapes**

1. Constructeurs : comme Shrubbery, avec `"RobotomyRequestForm"`, 72, 45.
2. Action : afficher des bruits de perceuse.
3. Tirer 0 ou 1 : si 0 → `<target> has been robotomized successfully`, sinon → `the robotomy failed`.

```
🎒 Bzzzzz... VRRRRR... bzzz...
Bender has been robotomized successfully
```

**⚠️ Piège**

Appeler `srand` dans `executeAction` → si on exécute 2 fois dans la même seconde, on a le même résultat. Une fois dans le main, c'est tout.

**💬 Message d'erreur**

```
std::cout << "Robotomy on " << _target << " failed" << std::endl;
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
executeAction :
  afficher "* drilling noises *"
  si rand % 2 vaut 0 : afficher "<cible> has been robotomized successfully"
  sinon              : afficher "Robotomy on <cible> failed"
```

- [ ] Page faite et comprise

Chapitre 7 · ex02 · PresidentialPardonForm.cpp · 15 min

## PresidentialPardonForm

**🎮 L'histoire**

Le président de la galaxie, Zaphod Beeblebrox, pardonne quelqu'un. Il faut une note de 5 pour exécuter !

**✅ Étapes**

1. Constructeurs : `"PresidentialPardonForm"`, 25, 5.
2. Action : afficher `<target> has been pardoned by Zaphod Beeblebrox.`

**💡 Astuce / tu connais déjà**

C'est le plus simple des trois. Bonne nouvelle.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
executeAction :
  afficher "<cible> has been pardoned by Zaphod Beeblebrox."
```

- [ ] Page faite et comprise

Chapitre 7 · ex02 · Bureaucrat.cpp · 20 min

## Bureaucrat::executeForm

**🎮 L'histoire**

Le bureaucrate essaie d'exécuter. Comme pour signer : il annonce le succès, ou il explique l'échec.

**📖 Mots nouveaux**

- `void executeForm(AForm const & form) const;` → 🗣️ **Se lit :** « executeForm reçoit une référence vers un AForm constant, ne renvoie rien, et ne modifie pas le bureaucrate ».

**✅ Étapes**

1. Dans `Bureaucrat.hpp` : `class AForm;` et la déclaration.
2. Dans un `try` : `form.execute(*this)`, puis afficher `<bureaucrat> executed <form>`.
3. Dans le `catch` : un message d'erreur clair avec `e.what()`.

```
🎒 Boss executed PresidentialPardonForm
Tim couldn't execute RobotomyRequestForm because AForm: form is not signed
```

**💡 Astuce / tu connais déjà**

C'est le jumeau de `signForm`.

**💬 Message d'erreur**

```
std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
executeForm (form) :
  essayer :
    form.execute(moi)
    afficher "<mon nom> executed <nom du form>"
  attraper (exception e) :
    afficher "<mon nom> couldn't execute <nom du form> because <e.what>"
```

- [ ] Page faite et comprise

Chapitre 8 · ex02 · main.cpp · 40 min

## Tester ex02

**🎮 L'histoire**

On fait passer chaque formulaire par toutes les étapes, avec un chef et un débutant.

**✅ Étapes**

1. `std::srand(std::time(NULL));` en première ligne.
2. Pour chaque formulaire : exécuter **sans** signer → « not signed ».
3. Signer avec un débutant → refus. Signer avec le chef → OK.
4. Exécuter avec le débutant → « grade too low ». Avec le chef → l'action.
5. Vérifier que le fichier `home_shrubbery` existe (`cat home_shrubbery`). Robotomy plusieurs fois : on doit voir les deux résultats.

**⚠️ Piège**

Note 137 pour exécuter Shrubbery : un bureaucrate de note 140 peut signer (145) mais **pas** exécuter. Bon test !

**✍️ À toi**

Écris ta liste de tests et la sortie attendue.

🔒 Déverrouiller mon pseudo-code

```
main :
  srand(time)
  boss note 1, moyen note 140
  pour Shrubbery("home"), Robotomy("Bender"), Pardon("Arthur") :
    boss.executeForm(f)     -> not signed
    moyen.signForm(f)       -> OK pour Shrubbery, refus pour les autres
    boss.signForm(f)
    moyen.executeForm(f)    -> grade too low
    boss.executeForm(f)     -> action + executed
```

- [ ] Page faite et comprise

Chapitre 9 · ex03 · Intern.hpp · 20 min

## Intern.hpp : le stagiaire

**🎮 L'histoire**

Le stagiaire n'a ni nom, ni note. Il sait faire une seule chose : remplir le bon formulaire quand on lui donne son nom.

**📖 Mots nouveaux**

- `AForm* makeForm(std::string const & formName, std::string const & target);` → 🗣️ **Se lit :** « makeForm reçoit deux références vers des strings constantes, et renvoie un pointeur vers AForm ».

**📏 Convention**

Classe sans attribut : rien à copier dans la copie et `operator=`. Ils existent quand même.

**🌍 Traductions (anglais → français)**

| Dans le code | En français |
| --- | --- |
| `Intern` | le stagiaire |
| `makeForm` | fabriquer un formulaire |
| `formName` | nom du formulaire |

**✅ Étapes**

1. `cp -r ex02 ex03`, crée `Intern.hpp` / `Intern.cpp`, ajoute au Makefile.
2. Forme canonique complète (même vide : la grille la demande).
3. En `public` : `makeForm`.
4. En `private` : 3 petites fonctions de création (page 3 du chapitre).

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
Intern.hpp :
  garde INTERN_HPP, include string, AForm.hpp
  classe Intern
    public : défaut, copie, =, destructeur
             makeForm(nom, cible) -> pointeur vers AForm
    privé : createShrubbery(cible), createRobotomy(cible), createPardon(cible)
            -> chacune renvoie un pointeur vers AForm
```

- [ ] Page faite et comprise

Chapitre 9 · ex03 · notion · 30 min

## Notion : le pointeur sur fonction membre

**🎮 L'histoire**

Imagine un tableau de boutons d'ascenseur. Chaque bouton mène à un étage.

Au lieu d'écrire « si étage 1 alors…, sinon si étage 2 alors… », on appuie sur le bouton numéro i.

Un **pointeur sur fonction membre**, c'est un bouton qui mène à une fonction de la classe.

**📖 Mots nouveaux**

- La grille l'exige : « un tableau de pointeurs sur fonctions membres ». Un if/else if = faux.
- Exemple avec une autre classe, `Chef`, qui a `void cuire();` et `void couper();` :
- `void (Chef::*action)();` → 🗣️ **Se lit :** « action est un pointeur vers une fonction membre de Chef, sans paramètre, qui ne renvoie rien ».
- `action = &Chef::cuire;` → on range l'adresse de la fonction (le `&` est obligatoire).
- `(this->*action)();` → on appuie sur le bouton : on appelle la fonction sur moi-même. Les parenthèses autour de `this->*action` sont obligatoires.
- Tableau de 2 boutons : `void (Chef::*actions[2])() = { &Chef::cuire, &Chef::couper };`

```
🎒 actions :  [ 0 ] -> Chef::cuire
           [ 1 ] -> Chef::couper
(this->*actions[1])();   -> appelle couper()
```

**⚠️ Piège**

Lire la déclaration de **l'intérieur vers l'extérieur** : d'abord le nom (`actions`), puis `[2]` (tableau de 2), puis `Chef::*` (pointeurs sur membre de Chef), puis `()` (fonction sans paramètre), puis `void` (renvoie rien).

**💡 Astuce / tu connais déjà**

Si la syntaxe fait peur : un `typedef` aide. `typedef void (Chef::*Action)();` → ensuite `Action actions[2];`.

❓ Question : Comment se lit `AForm* (Intern::*f)(std::string const &) const` ?

f est un pointeur vers une fonction membre constante de Intern, qui reçoit une référence vers une string constante et renvoie un pointeur vers AForm.

- [ ] Page faite et comprise

Chapitre 9 · ex03 · Intern.cpp · 15 min

## Les 3 fonctions de création

**🎮 L'histoire**

Trois petits tampons. Chacun fabrique un seul type de formulaire.

**📖 Mots nouveaux**

- `new` : créer un objet sur le **tas**. Il survit après la fonction. Quelqu'un devra faire `delete`.

**✅ Étapes**

1. Forme canonique : corps vides, `operator=` renvoie `*this`.
2. `createShrubbery(target)` : renvoie un `new ShrubberyCreationForm(target)`.
3. Pareil pour Robotomy et Pardon.
4. Inclure les 3 `.hpp` des formulaires dans `Intern.cpp`.

**⚠️ Piège**

Les 3 fonctions doivent avoir **exactement** la même signature (même paramètre, même retour, même `const`). Sinon, elles ne rentrent pas dans le même tableau.

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
createShrubbery (cible) : renvoyer new ShrubberyCreationForm(cible)
createRobotomy  (cible) : renvoyer new RobotomyRequestForm(cible)
createPardon    (cible) : renvoyer new PresidentialPardonForm(cible)
```

- [ ] Page faite et comprise

Chapitre 9 · ex03 · Intern.cpp · 40 min

## makeForm : le tableau de boutons

**🎮 L'histoire**

On donne au stagiaire « robotomy request ». Il cherche ce nom dans sa liste.

Il trouve la case 1 ? Il appuie sur le bouton 1 : un RobotomyRequestForm sort.

**✅ Étapes**

1. Un tableau de 3 strings : les noms acceptés.
2. Un tableau de 3 pointeurs sur fonctions membres, **dans le même ordre**.
3. Une boucle de 0 à 2 : si le nom donné est égal à `noms[i]` → afficher `Intern creates <form>` et renvoyer le résultat du bouton i.
4. Après la boucle (rien trouvé) : message d'erreur, renvoyer `NULL`.

```
🎒 noms :    [ "shrubbery creation" | "robotomy request" | "presidential pardon" ]
boutons : [ createShrubbery     | createRobotomy     | createPardon          ]
makeForm("robotomy request", "Bender") -> i = 1 -> new RobotomyRequestForm("Bender")
```

**⚠️ Piège**

Pas de `if / else if / else if` sur les noms : la grille compte faux.

**⚠️ Piège**

`NULL`, pas `nullptr` (C++11).

**💬 Message d'erreur**

```
std::cerr << "Intern: form \"" << formName << "\" does not exist" << std::endl;
```

**✍️ À toi**

Écris ton pseudo-code dans ton cahier. Ensuite seulement, ouvre le bloc en dessous.

🔒 Déverrouiller mon pseudo-code

```
makeForm (nom, cible) :
  noms    <- { "shrubbery creation", "robotomy request", "presidential pardon" }
  boutons <- { createShrubbery, createRobotomy, createPardon }
  pour i de 0 à 2 :
    si nom == noms[i] :
      afficher "Intern creates <nom>"
      renvoyer (moi ->* boutons[i])(cible)
  afficher l'erreur "form does not exist"
  renvoyer NULL
```

❓ Question : Qui doit faire le `delete` du formulaire ?

Celui qui reçoit le pointeur : le `main`. Le stagiaire fabrique, le main jette.

- [ ] Page faite et comprise

Chapitre 10 · ex03 · main.cpp · 30 min

## Tester ex03 et valgrind

**🎮 L'histoire**

On demande au stagiaire les 3 formulaires, plus un qui n'existe pas. Puis on vérifie que rien ne traîne en mémoire.

**✅ Étapes**

1. L'exemple du sujet : `makeForm("robotomy request", "Bender")`.
2. Les 2 autres noms.
3. Un nom faux (ex. `"coffee"`) → message d'erreur, pointeur `NULL`.
4. Signer et exécuter un formulaire créé par le stagiaire.
5. `delete` chaque pointeur. `delete NULL` ne fait rien : c'est sans danger.
6. `valgrind --leak-check=full ./intern` → « All heap blocks were freed ».

**⚠️ Piège**

Avant d'utiliser le pointeur : vérifier qu'il n'est pas `NULL`. Sinon, crash.

**💡 Astuce / tu connais déjà**

Grâce au destructeur **virtuel** d'AForm, `delete` sur un `AForm*` appelle bien le destructeur de l'enfant.

**✍️ À toi**

Écris ta liste de tests et la sortie attendue.

🔒 Déverrouiller mon pseudo-code

```
main :
  srand(time)
  stagiaire, boss note 1
  f <- stagiaire.makeForm("robotomy request", "Bender")
  si f pas NULL : boss.signForm(*f), boss.executeForm(*f)
  g <- makeForm("shrubbery creation", "home")
  h <- makeForm("presidential pardon", "Arthur")
  x <- makeForm("coffee", "x")   -> erreur, NULL
  delete f, g, h, x
```

- [ ] Page faite et comprise

Récap · à copier

## Tous les messages d'erreur

**🎮 L'histoire**

Toutes les alarmes et tous les messages d'échec, au même endroit.

| Fichier | Fonction | Quand | Ligne |
| --- | --- | --- | --- |
| Bureaucrat.cpp | GradeTooHighException::what | note \< 1 | `return "Bureaucrat: grade too high";` |
| Bureaucrat.cpp | GradeTooLowException::what | note > 150 | `return "Bureaucrat: grade too low";` |
| Form.cpp / AForm.cpp | GradeTooHighException::what | note du form \< 1 | `return "Form: grade too high";` |
| Form.cpp / AForm.cpp | GradeTooLowException::what | note hors limites, ou bureaucrate trop faible | `return "Form: grade too low";` |
| AForm.cpp | FormNotSignedException::what | execute sans signature | `return "AForm: form is not signed";` |
| Bureaucrat.cpp | signForm | beSigned a lancé | `std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;` |
| Bureaucrat.cpp | executeForm | execute a lancé | `std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;` |
| ShrubberyCreationForm.cpp | executeAction | fichier pas ouvert | `std::cerr << "Shrubbery: cannot open " << fileName << std::endl;` |
| RobotomyRequestForm.cpp | executeAction | 1 fois sur 2 | `std::cout << "Robotomy on " << _target << " failed" << std::endl;` |
| Intern.cpp | makeForm | nom inconnu | `std::cerr << "Intern: form \"" << formName << "\" does not exist" << std::endl;` |

**💡 Astuce / tu connais déjà**

En ex02, tu peux renommer les textes « Form: » en « AForm: ». Garde le même style partout.

Annexe

## Règles du jeu et grille de correction

**Contradictions sujet / grille**

1\. ex03 : le sujet dit « pas de gros if/else ». La grille exige précisément **un tableau de pointeurs sur fonctions membres**. On suit la grille.

2\. ex02 : la grille écrit `Form::execute` et `executeForm(Form const &)`. Le sujet fait renommer en `AForm`. C'est bien AForm.

3\. ex02 : les deux méthodes sont valides pour la grille. Le sujet préfère la plus « élégante » : vérifier dans le parent.

| Point de la grille | Où dans le code | Comment le montrer en 30 s |
| --- | --- | --- |
| Compile avec c++ -Wall -Wextra -Werror (C++98) | Makefile de chaque exo | `make re` devant l'évaluateur |
| Forme canonique (sauf exceptions) | chaque `.hpp` | montrer les 4 fonctions |
| Nom constant, note 1 à 150 | Bureaucrat.hpp | `std::string const _name;` |
| Exceptions à la création | constructeur Bureaucrat | test note 0 et 151 |
| increment / decrement + exceptions | Bureaucrat.cpp | test note 1 → increment |
| Exceptions héritent de std::exception | Bureaucrat.hpp | `catch (std::exception & e)` dans le main |
| operator\<\< | fin de Bureaucrat.cpp | `std::cout << bob` |
| Form : attributs private, nom et notes const | Form.hpp | montrer `private:` |
| beSigned / signForm | Form.cpp, Bureaucrat.cpp | test bureaucrate faible et fort |
| 3 formulaires : notes, noms, actions | 3 × .cpp | tableau 145/137, 72/45, 25/5 |
| Constructeur avec target seulement | 3 × .hpp | un seul paramètre |
| execute : vérifs puis action de l'enfant | AForm.cpp | expliquer le schéma du chapitre 6 |
| executeForm | Bureaucrat.cpp | test non signé + note trop basse |
| makeForm | Intern.cpp | exemple « robotomy request » + nom faux |
| Tableau de pointeurs sur fonctions membres | Intern.cpp | montrer les 2 tableaux et la boucle |
| Pas de fuite | main ex03 | `valgrind --leak-check=full` |

**⚠️ Piège**

Une petite modification peut t'être demandée en soutenance (ex. ajouter un 4ᵉ formulaire au stagiaire, changer un message). Avec le tableau, c'est 2 lignes à ajouter.

Annexe

## Fiche de soutenance

**🎮 L'histoire**

Les questions qu'un évaluateur pose souvent. Essaie de répondre avant d'ouvrir.

❓ Question : Qu'est-ce qu'une exception ?

Une alarme. On la lance avec `throw` quand une règle est cassée. Elle remonte les fonctions jusqu'au premier `catch` qui correspond.

❓ Question : Pourquoi attraper par référence ?

Pour ne pas copier l'objet et garder son vrai type (le bon `what()`).

❓ Question : Pourquoi `throw()` après `what()` ?

En C++98, `std::exception::what` promet de ne rien lancer. L'enfant doit faire la même promesse.

❓ Question : Que se passe-t-il si un constructeur lance ?

L'objet n'est pas créé. Son destructeur n'est pas appelé.

❓ Question : Pourquoi ton `operator=` ne copie pas le nom ?

Le nom est `const`. On ne peut le remplir que dans la liste d'initialisation d'un constructeur.

❓ Question : Pourquoi `class Bureaucrat;` dans Form.hpp ?

Pour casser la boucle d'inclusion. Une référence n'a pas besoin de la classe complète.

❓ Question : Pourquoi AForm est abstraite ?

Elle a une fonction virtuelle pure. On ne peut pas créer un « formulaire en général ».

❓ Question : Pourquoi le destructeur d'AForm est virtuel ?

Pour que `delete` sur un `AForm*` appelle aussi le destructeur de l'enfant.

❓ Question : Pourquoi vérifier dans `execute` et pas dans chaque enfant ?

Le code des vérifications est écrit une seule fois. Moins de copier-coller, moins d'erreurs.

❓ Question : Comment marche ton tableau dans makeForm ?

Un tableau de noms, un tableau de pointeurs sur fonctions membres dans le même ordre. On trouve l'indice du nom, on appelle la fonction au même indice.

❓ Question : Qui libère le formulaire créé par le stagiaire ?

Celui qui reçoit le pointeur (le main), avec `delete`.

Annexe

## Erreurs de compilation fréquentes

| Message (extrait) | En français simple | Où regarder |
| --- | --- | --- |
| looser throw specifier for virtual const char\* what() const | ton `what()` ne promet pas `throw()` | la déclaration ET la définition de what |
| assignment of read-only member \_name | tu modifies un attribut `const` | `operator=` : ne copie pas le nom |
| uninitialized const member | un attribut `const` pas rempli | la liste d'initialisation de chaque constructeur |
| invalid use of incomplete type class Bureaucrat | la classe est seulement « annoncée » | il manque `#include "Bureaucrat.hpp"` dans le .cpp |
| cannot declare variable to be of abstract type AForm | tu crées un AForm direct | crée un enfant à la place |
| no matching function for call to std::basic_ofstream ... (std::string&) | C++98 veut un texte C | ajoute `.c_str()` |
| passing const X as this argument discards qualifiers | appel d'une fonction non `const` sur un objet `const` | ajoute `const` à la fin du getter |
| unused parameter | paramètre pas utilisé (squelette) | `(void)nom;` |
| must use .\* or ->\* to call pointer-to-member function | mauvais appel du pointeur sur membre | `(this->*tab[i])(target)` avec les parenthèses |

Annexe

## Les exemples du sujet, annotés façon cahier

Surligneurs :abstraiteconcrètefonctionexceptiondelete

```
try
{
  Bureaucrat bob("Bob", 0);
}
```

- « essaie » ce bloc.
- Note 0 → le constructeur lance l'alarme. bob n'existe jamais.

```
catch (std::exception & e)
{
  std::cout << e.what() << std::endl;
}
```

- Attrape toute alarme enfant de std::exception, par référence.
- what() lit le panneau : « Bureaucrat: grade too high ».

```
Intern   someRandomIntern;
AForm*   rrf;
```

- Un stagiaire, sur la pile.
- rrf : pointeur vers AForm. AForm est abstraite, mais un pointeur vers elle, c'est permis.

```
rrf = someRandomIntern.makeForm(
        "robotomy request", "Bender");
```

- Le stagiaire cherche « robotomy request » dans son tableau.
- Il renvoie un new RobotomyRequestForm("Bender"), sur le tas.
- Affiche « Intern creates robotomy request ».

```
delete rrf;
```

- Absent du sujet, mais obligatoire pour valgrind.
- Destructeur virtuel → celui de RobotomyRequestForm est appelé, puis celui d'AForm.