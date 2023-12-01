/* fonction permettant de vérifie la contrainte d'exclusion entre deux sommets*/
int exclus_present(int ope,t_station* station,t_graphe *g){
    pArc temparc;
    int temp_ope,i;
    ope= ope_en_sommet(ope,g);
    temparc=g->pSommet[ope]->arc;
    while(temparc!=NULL){
        temp_ope=sommet_en_ope(temparc->sommet,g);
        for(i=0; i<station->taille; i++){
            if(temp_ope==station->pSommet[i]->ope)
                return 1;   //return 1 si exclusion entre les deux sommets
        }
        temparc=temparc->arc_suivant;
    }
    return 0;  // retourne 0 si pas d'exclusion entre deux sommets
}

/* fonction permettant de vérifie la contrainte de precedence entre deux sommets*/
int pred_present(int ope,t_station* station,t_graphe *g){
    int compteur=0;
    int i,j;
    ope= ope_en_sommet(ope,g);
    station=station->station_initial;
    if(g->pSommet[ope]->nb_pred==0) {
        return 1;
    }
    /* parcours du graphe pour trouver les operations de precedence */
    while (station!=NULL) {
        if(g->pSommet[ope]->nb_pred!=0) {
            for (i = 0; i < station->taille; i++) {
                for (j = 0; j < g->pSommet[ope]->nb_pred ; ++j) {
                    if (station->pSommet[i]->ope == g->pSommet[ope]->predecesseur[j])
                        compteur++;
                }
            }
        }
        station=station->station_suivant;
    }
     /* retourne le resultat */
    if(compteur==g->pSommet[ope]->nb_pred) {
        return 1; // return 1 si pas de precedences
    }
    else {
        return 0; // return 0 si precedences
    }
}
