#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define INFINI 9999999

/* Structure d'un arc/
struct Arc
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc arc_suivant;
};

/* Alias de pointeur sur un Arc /
typedef struct Arc pArc;

/* Structure d'un sommet/
struct Sommet
{
    struct Arc* arc;
    int ope;
    float duree;
    int nb_pred;
    int* predecesseur;
    int station;
}t_sommet;

/* Alias de pointeur sur un Sommet /
typedef struct Sommet pSommet;

/* Alias d'un Graphe /
typedef struct Graphe
{
    //int couleur_max;
    int ordre;
    int cycle;
    pSommet* pSommet;
} t_graphe;

typedef struct station
{
    int numero;
    int taille;
    float duree;
    pSommet* pSommet;
    struct station* station_initial;
    struct station* station_suivant;
}t_station;

// créer le graphe
Graphe* CreerGraphe(int ordre);

/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs /
Graphe lire_graphe(char * nomFichier);

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2);

/* affichage des successeurs du sommet num/
void afficher_successeurs(pSommet sommet, int num);

/affichage du graphe avec les successeurs de chaque sommet/
void graphe_afficher(Graphe* graphe);

#endif // GRAPHE_H_INCLUDED
