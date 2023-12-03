//
// Created by William on 28/11/2023.
//
#include "graph.h"

/* Ajouter l'arête entre les sommets s1 et s2 du graphe */
pSommet* CreerArete(pSommet* sommet,int s1,int s2)
{
    if(sommet[s1]->arc==NULL)
    {
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }


    else
    {
        pArc temp=sommet[s1]->arc;
        while( temp->arc_suivant!=NULL)
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

/* creer le graphe */
t_graphe* CreerGraphe(FILE *fichier)
{
    t_graphe * Newgraphe;
    int i,som1;
    float temps;
    Newgraphe=(t_graphe*)malloc(sizeof(t_graphe));
    Newgraphe->pSommet=(pSommet*)malloc(50*sizeof(t_sommet));
    Newgraphe->ordre=0;
    i=0;
    som1=0;
    while (feof(fichier)==0){
        fscanf(fichier,"%d %f", &som1, &temps);
        Newgraphe->ordre++;
        Newgraphe->pSommet[i] = (pSommet) malloc(sizeof(t_sommet));
        Newgraphe->pSommet[i]->ope = som1;
        Newgraphe->pSommet[i]->duree = temps;
        Newgraphe->pSommet[i]->station = -1;
        Newgraphe->pSommet[i]->nb_pred = 0;
        Newgraphe->pSommet[i]->arc = NULL;
        Newgraphe->pSommet[i]->predecesseur = (int*) malloc(5*sizeof(int));
        i++;
    }
    Newgraphe->ordre--;
    return Newgraphe;
}



/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
t_graphe * lire_graphe(char *nomFichier,char *nomFichier2,char *nomFichier3,char *nomFichier4,int choix)
{
    t_graphe* graphe;

    FILE *ifs = fopen(nomFichier,"r");    ///1 = temps des operations
    FILE *ifs2 = fopen(nomFichier2,"r");  ///2= fichier des exclusions
    FILE *ifs3 = fopen(nomFichier3,"r");  ///3 = fichier des precedences
    FILE *ifs4 = fopen(nomFichier4,"r");  ///4 = fichier du cycle

    int s1, s2,pred, cycle;
    s1=0;

    if (!ifs)
    {
        erreur_lecture (nomFichier);
    }
    if (!ifs2)
    {
        erreur_lecture (nomFichier2);
    }
    if (!ifs3)
    {
        erreur_lecture (nomFichier3);
    }
    if (!ifs4)
    {
        erreur_lecture (nomFichier4);
    }
    //on initialise des opérations et la duree de chacun
    graphe=CreerGraphe(ifs); // créer le graphe d'ordre sommets



    /* on commence par donner le cycle du graphe */
    if (choix==1 || choix>=3 || choix<0)
    {
        fscanf(ifs4,"%d",&cycle);
        graphe->cycle=cycle;
    }
    else {
        graphe->cycle = INFINI;
    }

    /* ici on fait la precedence */
    if (choix==1 || choix>=4 || choix<0||choix==2) {
        while (feof(ifs3) == 0) {
            fscanf(ifs3, "%d %d", &pred, &s1);
            if(ope_existe(pred,graphe)==0){
                erreur_fichier(pred,nomFichier3);
            }
            if(ope_existe(s1,graphe)==0){
                erreur_fichier(s1,nomFichier3);
            }
            s1 = ope_en_sommet(s1, graphe);
            graphe->pSommet[s1]->predecesseur[graphe->pSommet[s1]->nb_pred] = pred;
            graphe->pSommet[s1]->nb_pred++;
        }
    }

    /* créer les arêtes du graphe */
    if (choix!=1) {
        while (feof(ifs2) == 0) {
            fscanf(ifs2, "%d %d", &s1, &s2);
            if(ope_existe(s1,graphe)==0){
                erreur_fichier(s1,nomFichier2);
            }
            if(ope_existe(s2,graphe)==0){
                erreur_fichier(s2,nomFichier2);
            }
            s1 = ope_en_sommet(s1, graphe);
            s2 = ope_en_sommet(s2, graphe);
            graphe->pSommet = CreerArete(graphe->pSommet, s1, s2);
            graphe->pSommet = CreerArete(graphe->pSommet, s2, s1);
        }
    }
    return graphe;
}

/* verification si existance du sommet */
int ope_existe(int ope, t_graphe *graphe)
{
    int i;
    for (i = 0; i < graphe->ordre; i++)
    {
        if (graphe->pSommet[i]->ope == ope)
        {
            return 1; // retourne 1 si vrai
        }
    }
    return 0; // 0 sinon
}
