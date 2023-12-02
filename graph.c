#include "Graphe.h"

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
/* créer le graphe */
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
Graphe * lire_graphe(char * nomFichier)
{
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    graphe=CreerGraphe(ordre); // créer le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);
    fscanf(ifs,"%d",&orientation);

    graphe->orientation=orientation;
    graphe->ordre=ordre;

    /* crée les arêtes du graphe */
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);
    }

    return graphe; // retourne le graphe cree
}
