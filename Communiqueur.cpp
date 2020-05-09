#include "Communiqueur.h"
#include <regex>

void Communiqueur::lireFichier(string _chemin) {
    ifstream factorator;
    factorator.open(_chemin);

    //Après avoir été bloqué pendant un moment. "\d" necessite deux "\" en C++
    regex regex_id("^[0-9]{4}:[0-9]{4}:[0-9]{4}:[0-9]{4}$"); 
    //  regex regex_texte(""); //No necessaire
    regex regex_prix("^[0-9]+$");

    if (factorator.is_open()) {
        Donnees donnees;

        while (!factorator.eof()) {

            string ligne_lue;
            getline(factorator, ligne_lue);

            if (regex_match(ligne_lue, regex_id)) {
                donnees.setId(ligne_lue);
                cout << "ID lu." << endl;
            }
            else if (regex_match(ligne_lue, regex_prix)) {
                donnees.setPrix((stod(ligne_lue) / 100)); //stod pour le transformer en double et /100 pour les cents
                cout << "Prix lu." << endl;
            }
            else { //Valeur non utilisé
                donnees.setDesc(ligne_lue);
                cout << "Description lue." << endl;
            }

            //Ajout des donnees dans l'objet
            if (donnees.getId() != "" && donnees.getPrix() != 0) {
                ajoutDonnees(donnees);
                donnees = Donnees();
            }
        }
        factorator.close();
    }
}

void Communiqueur::ecrireFichier(string _chemin) {
    ofstream da_count(_chemin);

    for (int i=0; i < tableau.size(); i++) {

        string id = tableau[i].getId();
 //     id = remove(id.begin(), id.end(), ':');  //Enleve les ":"
        id.erase(remove(id.begin(), id.end(), ':'), id.end());
        int prix = (int)((tableau[i].getPrix() * 100) + 0.5); //0.5 vient d'une question stackoverflow

        da_count << id << " " << prix << std::endl; //Un espace comme dans l'exemple
    }
    da_count.close();
}