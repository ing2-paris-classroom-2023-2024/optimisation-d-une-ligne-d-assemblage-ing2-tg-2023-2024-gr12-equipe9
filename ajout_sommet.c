//
// Created by Admin on 02/12/2023.
//

#include <stdio.h>
#include <stdlib.h>

void ajout_sommet(t_station *Station, pSommet sommet, t_graphe *graphe)
{
    int num;
    num = ope_en_sommet(sommet->ope,graphe);
    if (Station == NULL || sommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Insertion de l élément à la bonne place */
    graphe->psommet[num]->station = Station->numero;
    Station->pSommet[Station->taille] = sommet;
    sommet->station = Station->numero;
    Station->duree += sommet->duree;
    Station->taille++;
}