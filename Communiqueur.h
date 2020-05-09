#pragma once
#include <fstream>
#include <iostream>
#include <vector>


#include "Donnees.h"; 


class Communiqueur {
private:
	vector<Donnees> tableau;
public:
	Communiqueur() {};
	void ajoutDonnees(Donnees _d) { this->tableau.push_back(_d); };

	void lireFichier(string _chemin);
	void ecrireFichier(string _chemin);
};
