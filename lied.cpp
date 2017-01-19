

#include "lied.h"
#include <iostream>
#include <string>

using namespace std;

lied::lied() {}

lied::lied(std::string t, std::string i, int e, int l, enum lied::stil st) {
        titel = t;
        interpret = i;
        erscheinungsjahr = e;
        laenge = l;
        genre = st;
}


void lied::print () const {
        cout << "Titel: " << titel << endl;
        cout << "Interpret: " << interpret << endl;
        cout << "Erscheinungsjahr: " << erscheinungsjahr << endl;
        cout << "Länge: " << laenge << endl;
        cout << "Genre: " << genre << endl;
}

std::string lied::getTitle () {
    return titel;
}