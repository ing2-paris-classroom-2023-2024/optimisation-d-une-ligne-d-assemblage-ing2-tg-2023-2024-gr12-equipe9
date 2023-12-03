//
// Created by kylia on 16/11/2023.
//

#ifndef INIT_GRAPH_H
#define INIT_GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define INFINI 9999999

/* Structure d'un arc*/
struct Arc
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    struct Arc* arc_suivant;
};


/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int ope;
    float duree;
    int nb_pred;
    int* predecesseur;
    int station;
}t_sommet;

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
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
t_graphe* CreerGraphe(FILE *fichier);

/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
t_graphe * lire_graphe(char *nomFichier, char *nomFichier2, char *nomFichier3,char *nomFichier4,int choix);

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2);

/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num,t_graphe* graphe );

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(t_graphe* graphe);

int sommet_en_ope(int ope, t_graphe *graphe);

int ope_en_sommet(int ope, t_graphe *graphe);

t_station* num_station(int num, t_station* station_);

t_station* creer_ligne(t_graphe *graphe);

int est_fini(t_graphe *g);

void afficher_station(t_station *Station);

void ajout_sommet(t_station *Station, pSommet sommet,t_graphe *graphe);

void nouvelle_station(t_station *Station);

t_station *initialisation(void);

int exclus_present(int ope,t_station* station,t_graphe *g);

int pred_present(int ope,t_station* station,t_graphe *g);

void affichage_erreur_op (t_graphe* graphe);
void erreur_lecture (char *nomFichier);
void erreur_fichier(int operation, const char* nom_fichier);
int ope_existe(int sommet, t_graphe *graphe);
void affichage_contraite(int choix);
void affichage_menu_contrainte(void);
void affichage_menu_station_sommet(void);
void choix_operation(void);
void erreur_choix_operation(void);
void choix_station(void);
void erreur_choix_station(void);
void affichage_staion(void);
#endif //INIT_GRAPH_H
