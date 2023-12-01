Graphe * g;
    station* station_;

    char nom_fichier_temps,nom_fichier_exclusion,nom_fichier_precedences,nom_fichier_cycle;
    nom_fichier_temps = "texte/operations.txt";
    nom_fichier_exclusion = "texte/exclusions.txt";
    nom_fichier_precedences = "texte/precedences.txt";
    nom_fichier_cycle = "texte/temps_cycle.txt";

g = lire_graphe(nom_fichier_temps,nom_fichier_exclusion,nom_fichier_precedences,nom_fichier_cycle);

    /// afficher le graphe
    grapheafficher(g);

    station = creerligne(g);
    station = station_->station_initial;
