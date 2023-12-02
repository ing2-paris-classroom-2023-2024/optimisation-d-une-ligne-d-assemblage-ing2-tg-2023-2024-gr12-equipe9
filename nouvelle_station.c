//
// Created by Admin on 02/12/2023.
//

#include <stdlib.h>
#include <stdio.h>

void nouvelle_station(t_station *Station)
{
    /* Création du nouvel élément */
    t_station *nouveau = malloc(sizeof(*nouveau));
    nouveau->pSommet = (pSommet*)malloc(50*sizeof(t_sommet));
    if (nouveau->pSommet == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Insertion de l'élément à la bonne place */
    nouveau->numero = Station->numero + 1;
    nouveau->station_initial = Station->station_initial;
    nouveau->station_suivant = Station->station_suivant;
    Station->station_suivant = nouveau;
}