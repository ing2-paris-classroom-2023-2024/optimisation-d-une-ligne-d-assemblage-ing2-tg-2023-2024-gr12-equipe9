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
