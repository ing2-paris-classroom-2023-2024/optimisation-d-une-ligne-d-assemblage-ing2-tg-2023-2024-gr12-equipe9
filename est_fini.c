//
// Created by Admin on 02/12/2023.
//

#include <stdio.h>

int est_fini(t_graphe *g){
    for(int i=0; i<g->ordre; i++){
        if(g->pSommet[i]->station==-1)
            return 0;
    }
    return 1;
}