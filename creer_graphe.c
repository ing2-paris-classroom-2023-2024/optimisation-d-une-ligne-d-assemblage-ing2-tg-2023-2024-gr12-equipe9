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
    if (!ifs2)
    {
        printf("Erreur de lecture fichier 2\n");
        exit(-1);
    }
    if (!ifs3)
    {
        printf("Erreur de lecture fichier 3\n");
        exit(-1);
    }
    if (!ifs4)
    {
        printf("Erreur de lecture fichier 4\n");
        exit(-1);
    }

    fscanf(ifs4,"%d",&cycle);
    graphe->cycle=cycle;

      while (feof(ifs3)==0)
    {
        fscanf(ifs3,"%d %d",&pred,&s1);
        s1=ope_en_sommet(s1,graphe);
        graphe->pSommet[s1]->predecesseur[graphe->pSommet[s1]->nb_pred]=pred;
        graphe->pSommet[s1]->nb_pred++;
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
