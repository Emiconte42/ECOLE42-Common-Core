# DOSSIER.md — [CPP04] [ex03]

## 1. Qualité du code
- Forme canonique pour chaque classe
- Destructeur virtuel dans les classes de base
- const partout où c'est possible
- Une classe = un .hpp + un .cpp
> Vérifie : ça compile sans aucun warning avec les 3 flags ?
> Ce que font les pros : une classe = une seule responsabilité.

## 2. Mémoire
- Qui fait new ? Qui fait delete ? : [tableau]
- Copie profonde ou superficielle ? Pourquoi ? : [...]
> Vérifie : si je copie un objet puis détruis l'original, la copie marche encore ?
> Ce que font les pros : RAII et règle des trois (C++98).

## 3. Tests (main.cpp)
- Le main du sujet : [OK / KO]
- Mes tests en plus : copie, affectation, auto-affectation, cas limites
- Fuites : valgrind --leak-check=full ./[programme] → [0 fuite]
> Vérifie : un test qui doit échouer échoue-t-il vraiment ?
> Ce que font les pros : tester les cas limites en premier.

## 4. Grille de correction
Recopie chaque point de la grille, puis coche.
- [ ] [Point 1 de la grille] → où dans mon code : [fichier]
- [ ] [Point 2 de la grille] → où dans mon code : [fichier]
- [ ] [...]
> Vérifie : je peux montrer chaque point à l'évaluateur en moins de 30 secondes ?