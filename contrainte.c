*/* fonction permettant de vérifie la contrainte d'exclusion entre deux sommets*/
int exclus_present(int ope,t_station* station,t_graphe *g){
    pArc temparc;
    int temp_ope,i;
    ope= ope_en_sommet(ope,g);
    temparc=g->pSommet[ope]->arc;
    while(temparc!=NULL){
        temp_ope=sommet_en_ope(temparc->sommet,g);
        for(i=0; i<station->taille; i++){
            if(temp_ope==station->pSommet[i]->ope)
                return 1;//return 1 si exclusion entre les deux sommets
        }
        temparc=temparc->arc_suivant;
    }
    return 0;// retourne 0 si pas d'exclusion entre deux sommets
}
