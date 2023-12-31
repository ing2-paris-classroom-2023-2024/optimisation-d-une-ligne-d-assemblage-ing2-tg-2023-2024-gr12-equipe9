//
// Created by kyliann on 16/11/2023.

#include "graph.h"
/* permet de parcourir les stations */
t_station* num_station(int num, t_station* poste){
    poste=poste->station_initial;
    while (poste!=NULL){
        if(poste->numero==num)
            return poste; // renvoie la station demande
        poste=poste->station_suivant;
    }
    return NULL; // renvoie rien si pas de station
}

/* initialisation des stations nouvellement creer */
t_station *initialisation(void)
{
    t_station *Station = malloc(sizeof(*Station));
    Station->pSommet = (pSommet*)malloc(50*sizeof(t_sommet));

    if (Station == NULL || Station->pSommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Station->numero = 0;
    Station->taille = 0;
    Station->station_initial = Station;
    Station->station_suivant = NULL;

    return Station; // renvoie la station initialise
}
/* création d'une nouvelle station */
void nouvelle_station(t_station *Station)
{
    /* Création du nouvel élément */
    t_station *nouveau = malloc(sizeof(*nouveau));
    nouveau->pSommet = (pSommet*)malloc(50*sizeof(t_sommet));
    if (nouveau->pSommet == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Insertion de la station à suite de la dernière (ajout d'un maillon) */
    nouveau->numero = Station->numero + 1;
    nouveau->station_initial = Station->station_initial;
    nouveau->station_suivant = Station->station_suivant;
    Station->station_suivant = nouveau;
}
/* ajoute un sommet à la station voulu */
void ajout_sommet(t_station *Station, pSommet sommet, t_graphe *graphe)
{
    int num;
    num=ope_en_sommet(sommet->ope,graphe);
    if (Station == NULL || sommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Insertion de l'élément à la bonne place */
    graphe->pSommet[num]->station = Station->numero;
    Station->pSommet[Station->taille] = sommet;
    sommet->station = Station->numero;
    Station->duree += sommet->duree;
    Station->taille++;
}

/* blindage verification du rangement des sommets */
int est_fini(t_graphe *g){
    int i;
    for( i=0; i<g->ordre; i++){
        if(g->pSommet[i]->station==-1)
            return 0; // 0 si pas fini
    }
    return 1; // 1 si fini
}


/* permet de creer l'ensemble des stations selon les contraintes */
t_station* creer_ligne(t_graphe *graphe){
    t_station* poste = initialisation();
    int modification;
    int i;
    int garde=0;
    while (est_fini(graphe)==0 && garde<2){
        modification=0;
        for(i=0; i<graphe->ordre; i++){
            if(graphe->pSommet[i]->station==-1){
                if(exclus_present(graphe->pSommet[i]->ope,poste,graphe)==0) {
                    if(pred_present(graphe->pSommet[i]->ope,poste,graphe)==1) {
                        if (poste->duree + graphe->pSommet[i]->duree <= graphe->cycle) {
                            ajout_sommet(poste, graphe->pSommet[i],graphe);
                            modification++;
                        }
                    }
                }
            }
        }
        if(modification==0){
            nouvelle_station(poste);
            poste=poste->station_suivant;
            garde++;
        }
        if(modification!=0)
            garde=0;
    }

    if(est_fini(graphe)==0){

        affichage_erreur_op(graphe); // operation non place = erreur grave
    }



    return poste; // retourne de la chaine creer
}
