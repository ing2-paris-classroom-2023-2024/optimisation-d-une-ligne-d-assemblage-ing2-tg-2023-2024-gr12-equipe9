//
// Created by Paul on 26/11/2023.
//
/* affichage des successeurs du sommet num*/
#include "graph.h"
void afficher_successeurs(pSommet * sommet, int num,t_graphe* graphe)
{
    int bruh;// changer

    printf("\n\n sommet %d (operation %d avec une duree de %.2f s) dans la station %d :\n",num,sommet[num]->ope,sommet[num]->duree,sommet[num]->station);



    pArc arc=sommet[num]->arc;
    printf("liste des exclusions : \n");
    if(arc==NULL)
    {
        printf("       -> aucune exclusion \n");
    }
    while(arc!=NULL)
    {
        bruh=sommet_en_ope(arc->sommet,graphe);
        printf("       -> %d \n",bruh );
        arc=arc->arc_suivant;
    }
    printf("liste des predecesseurs : \n");
    if(sommet[num]->nb_pred==0)
    {
        printf("       -> aucune predecesseur \n");
    }
    for (int (j) = 0; (j) < sommet[num]->nb_pred; ++(j)) {
        printf("       -> %d\n",sommet[num]->predecesseur[j]);
    }

}

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(t_graphe* graphe)
{
    printf("graphe\n");

    printf("cycle = %d\n",graphe->cycle);

    printf("ordre = %d\n",graphe->ordre);

    printf("liste des exclusions : \n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i,graphe);
        printf("\n");
    }

}

/* affichage de la station selectionne*/
void afficher_station(t_station *Station)
{
    if (Station == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("Station %d :\n", Station->numero);
    for (int i = 0; i < Station->taille; i++)
    {
        printf("ope %d, duree %.2f s  ",Station->pSommet[i]->ope,Station->pSommet[i]->duree);
        printf("\n");
    }
    printf("duree de la station : %.2f s\n",Station->duree);
    printf("\n");
}

void affichage_erreur_op (t_graphe* g)
{
    int i;
    printf("erreur, il reste des operations non place\n");
    printf("les operations restantes sont : \n");
    for(i=0; i<g->ordre; i++){
        if(g->pSommet[i]->station==-1)
            printf("ope %d ",g->pSommet[i]->ope);
    }
    printf("\n\n");
}

void erreur_lecture (void)
{
    printf("Erreur de lecture fichier\n");
    exit(-1);
}

int ope_en_sommet(int ope, t_graphe *graphe){
    int i;
    for(i=0; i<graphe->ordre; i++){
        if(graphe->pSommet[i]->ope==ope)
            return i;
    }
    return -1;
}
void erreur_fichier(int operation, const char* nom_fichier)
{
    printf("erreur lecture de fichier l'operation %d n'existe pas \n",operation);
    printf("dans le fichier %s\n",nom_fichier);
    exit(1);
}

void affichage_contraite(int choix){
    printf("repartition des stations pour les contraintes : \n");
    switch (choix ) {
        case 0 :
            printf("exclusion\n\n");
            break;
        case 1 :
            printf("precedence + temps de cycle\n\n");
            break;
        case 2 :
            printf("exclusion + precedence\n\n");
            break;
        case 3 :
            printf("exclusion + temps de cycle\n\n");
            break;
        case 4:
        default:
            printf("exclusion + precedence + temps de cycle\n\n");
            break;
    }
}