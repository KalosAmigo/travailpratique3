// TravailPratique3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Communiqueur.h"

int main()
{
    Communiqueur cm;

    cout << "Chargement du fichier." << endl;
    cm.lireFichier("Facturator.csv");

    cout << "Traitement." << endl;

    cout << "Conversion du fichier." << endl;
    cm.ecrireFichier("DaCount.ods");

    cout << "You win." << endl;
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu