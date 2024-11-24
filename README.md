# Cub3D

![Statut du projet](https://img.shields.io/badge/statut-compl%C3%A9t%C3%A9-4caf50)
![Notion](https://img.shields.io/badge/notion-ray--casting-blue)
![Outil](https://img.shields.io/badge/outil-MiniLibX-orange)

## Description

Ce projet est inspiré du jeu **Wolfenstein 3D**, mondialement connu et souvent considéré comme le premier FPS (First Person Shooter) de l'histoire du jeu vidéo. Cub3D est un projet de l'école 42 qui consiste à créer une vue dynamique à la première personne au sein d'un labyrinthe en utilisant la technique du **ray-casting**, tout en utilisant la bibliothèque **MiniLibX**. Votre objectif est de créer une représentation graphique "réalistique" qui s'adapte en fonction des mouvements du joueur.

## Compilation et Lancement

Deux versions du programme sont disponibles : la partie obligatoire et la partie bonus.

Pour compiler la version obligatoire :

```sh
make
```

Pour compiler la version bonus (ajout de la minimap, rotation via la souris, collisions) :

```sh
make bonus
```

Note : Utilisez `make fclean` avant de compiler une autre version.

Pour lancer le programme :

```sh
./cub3d <path/to/map.cub>
```

Le programme prend un fichier de description de scène (`.cub`) en argument. Des exemples de maps sont disponibles dans le dossier `maps`.

## Commandes

Voici les commandes pour contrôler la caméra dans le jeu :

- **W** : Avancer
- **S** : Reculer
- **A** : Gauche
- **D** : Droite
- **Flèches gauche/droite** : Tourner la caméra à gauche/droite
- **Échap** : Quitter le programme

## Fonctionnalités et Objectifs

### Partie Obligatoire

- Utilisation de la **MiniLibX** pour le rendu graphique.
- Utilisation des textures différentes selon les murs (nord, sud, est, ouest).
- Couleurs distinctes pour le sol et le plafond.
- Gestion des fenêtres (minimisation, fermeture propre).
- Prise en charge des fichiers de description de scène avec l'extension `.cub`.

Exemple de description minimale de scène (`map.cub`) :

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

### Partie Bonus

- Collisions avec les murs.
- Mini-carte.



## Ressources Utiles

- [MiniLibX Hooks Documentation](https://harm-smits.github.io/42docs/libs/minilibx/events.html)

## Débogage et Mémoire

- Utilisation de **valgrind** et **fsanitize** pour vérifier les fuites de mémoire et les erreurs.
- Toute mémoire allouée doit être libérée pour éviter les **leaks**.
