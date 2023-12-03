#include "graph.h"

int main() {
    t_graphe ** g;
    t_station** poste;
    t_station** ancre;
    g = (t_graphe**)malloc(4*sizeof(t_graphe*));
    poste = (t_station**)malloc(5*sizeof(t_station*));
    ancre = (t_station**)malloc(5*sizeof(t_station*));
    char temp,buffer;
    int choix, choix1,i,choix_utilisateur;

    const char *nom_fichier_temps,*nom_fichier_exclusion,*nom_fichier_precedences,*nom_fichier_cycle;
    nom_fichier_temps = "texte/operations.txt";
    nom_fichier_exclusion = "texte/exclusions.txt";
    nom_fichier_precedences = "texte/precedences.txt";
    nom_fichier_cycle = "texte/temps_cycle.txt";


    for (i = 0; i < 5 ; i++) {


        g[i] = lire_graphe(nom_fichier_temps,nom_fichier_exclusion,nom_fichier_precedences,nom_fichier_cycle,i);


        poste[i] = creer_ligne(g[i]);
        poste[i] = poste[i]->station_initial;
        ancre[i] = poste[i]->station_initial;

        affichage_contraite(i);

        affichage_staion();
        while (poste[i] != NULL)
        {
            afficher_station(poste[i]);
            poste[i] = poste[i]->station_suivant;
        }
    }


    affichage_menu_contrainte();
    scanf("%c",&temp);
    scanf("%c",&buffer); // lecture à vide
    choix1=temp-48;
    switch (choix1 ) {
        case 0 :
            choix_utilisateur=0;
            affichage_contraite(choix_utilisateur);
            graphe_afficher(g[choix_utilisateur]);
            break;
        case 1 :
            choix_utilisateur=1;
            affichage_contraite(choix_utilisateur);
            graphe_afficher(g[choix_utilisateur]);
            break;
        case 2 :
            choix_utilisateur=2;
            affichage_contraite(choix_utilisateur);
            graphe_afficher(g[choix_utilisateur]);
            break;
        case 3 :
            choix_utilisateur=3;
            affichage_contraite(choix_utilisateur);
            graphe_afficher(g[choix_utilisateur]);
            break;
        case 4:
        default:
            choix_utilisateur=4;
            affichage_contraite(choix_utilisateur);
            graphe_afficher(g[choix_utilisateur]);
            break;
    }


    affichage_menu_station_sommet();
    scanf("%c",&temp);
    scanf("%c",&buffer); // lecture à vide
    choix=temp-48;
    if (choix<0)
    {
        choix=0;
    }
    if (choix>2)
    {
        choix=2;
    }
    while (choix != 2) {

        /*while (choix != 2 && choix != 1 && choix != 0) {*/
        if (choix==-1){
            affichage_menu_station_sommet();
            scanf("%c",&buffer); // lecture à vide
            scanf("%c",&temp);
            choix=temp-48;
            if (choix<0)
            {
                choix=0;
            }
            if (choix>2)
            {
                choix=2;
            }
        }
        if (choix == 0) {
            int sommet;
            choix_operation();
            scanf("%d", &sommet);
            sommet = ope_en_sommet(sommet, g[choix_utilisateur]);
            while (sommet == -1){
                erreur_choix_operation();
                scanf("%d", &sommet);
                sommet = ope_en_sommet(sommet, g[choix_utilisateur]);
            }
            afficher_successeurs(g[choix_utilisateur]->pSommet, sommet, g[choix_utilisateur]);
            choix = -1;
        }
        if (choix == 1) {
            int station;
            choix_station();
            scanf("%d", &station);
            poste[choix_utilisateur] = ancre[choix_utilisateur];
            poste[choix_utilisateur] = num_station(station, poste[choix_utilisateur]);
            while (poste[choix_utilisateur] == NULL){
                poste[choix_utilisateur] = ancre[choix_utilisateur];
                erreur_choix_station();
                scanf("%d", &station);
                poste[choix_utilisateur] = num_station(station, poste[choix_utilisateur]);
            }
            afficher_station(poste[choix_utilisateur]);
            choix = -1;

        }
    }

    return 0;
}
