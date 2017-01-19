


#include <iostream>
#include <string>
#include <vector>
#include "lied.h"
#include "DynArray.h"
#include "BubbleSort.h"


using namespace std;




void fill (DynArray& data) {
    for (int i = 0; i < 10; i++) {
        data.push_back(lied());
        data.at(i).erscheinungsjahr = i;
    }
    cout << data.size() << endl;
    cout << data.capacity() << endl;
    data.at(0).titel = "Was";
    data.at(1).titel = "ist";
    data.at(2).titel = "die";
    data.at(3).titel = "alphabetische";
    data.at(4).titel = "ordnung";
    data.at(5).titel = "für";
    data.at(6).titel = "diese";
    data.at(7).titel = "wörter";
    data.at(8).titel = "krautsalat";
    data.at(9).titel = "geht";
}


lied eintragneu() {

    string t, i;
    int e, l, h;
    enum lied::stil st;

    cout << "Titel: " << endl;
    cin.ignore();
    getline(cin, t);
    cout << "Interpret: " << endl;
    getline(cin, i);
    cout << "Erscheinungsjahr: " << endl;
    cin >> e;
    cout << "Länge: " << endl;
    cin >> l;
    cout << "Bitte die zur Genre entsprechende Zahl eingeben(1. Pop, 2. Rock, 3. Klassik, 4. HardRock oder 5. Metal): " << endl;
    cin >> h;
    st = static_cast<lied::stil> (h);
    return lied(t, i, e, l, st);
}

void eintragdetails(const DynArray& v, int eintragnr) {
    v.at(eintragnr).print();
}

void eintragloeschen(DynArray& v) {
    int a;
    cout << "Einen Eintrag löschen" << endl;
    cout << "Bitte eine Zahl zwischen 0 und " << v.size() - 1 << " eingeben um den Eintrag zu löschen." << endl;
    cin >> a;
    v.erase(a);
}

void eintragbearbeiten(DynArray& v) {
    int a;
    int b;
    int c;
    string d;
    enum lied::stil st;

    cout << "Einen Eintrag bearbeiten." << endl;
    cout << "Bitte die Nummer des zu bearbeitenden Eintrags eingeben. (zwischen 0 und " << v.size() - 1 << ")." << endl;
    cin >> a;
    eintragdetails(v, a);
    cout << "Bitte eine Zahl zwischen 1 und 5 eingeben um die entsprechende Information zu bearbeiten." << endl;
    cin >> b;
    cout << endl << "Bitte neue Information eingeben" << endl;
    if (b < 3) cin >> d;
    else cin >> c;
    if (b == 5) st = static_cast<lied::stil> (c);
    switch (b) {
        case 1: v.at(a).titel = d;
            break;
        case 2: v.at(a).interpret = d;
            break;
        case 3: v.at(a).erscheinungsjahr = c;
            break;
        case 4: v.at(a).laenge = c;
            break;
        case 5: v.at(a).genre = st;
            break;
    }
}

int eintragsuchen(const DynArray& v) {
    string eingabe;
    string sk;
    cout << "Einen Eintrag suchen." << endl;
    cout << "Bitte geben sie den Namen des zu suchenden Lieds ein" << endl;
    cin >> eingabe;
    sk = lowerCase(eingabe);
    int start = 0;
    int mitte = (v.size()/2);
    int ende = v.size();
    while (ende != start) {
        if (lowerCase(v.at(mitte).getTitle()) == sk) {
            v.at(mitte).print();
            return 0;
        } 
        else if (sk < lowerCase(v.at(mitte).getTitle())) {
            ende = mitte;
            mitte = (ende-start)/2 + start;
        }
        else {
            start = mitte + 1;
            mitte = (ende-start)/2 + start;
        }      
    }
    cout << "Es wurde kein Lied mit diesem Titel gefunden" << endl;
    return 0;
}

void eintraganzeigen(const DynArray& v) {
    v.print();
}

int menu() {
    char auswahlmenu;
    DynArray daten;
    int auswahl = 0;
    while (true) {
        bubblesort(daten);
        cout << "*********** Musikbibliothek Version 0.3**********" << endl;
        cout << "Hauptmenue:" << endl;
        cout << "1. (N)euen Eintrag anlegen" << endl;
        cout << "2. (D)etails eines Eintrages anzeigen" << endl;
        cout << "3. Einen Eintrag (l)oeschen" << endl;
        cout << "4. Einen Eintrag (b)earbeiten" << endl;
        cout << "5. Einen Eintrag (s)uchen" << endl;
        cout << "6. (A)lle Eintraege anzeigen" << endl;
        cout << "0. Programm beenden" << endl;
        cin >> auswahlmenu;
        switch (auswahlmenu) {
            case '1':
            case 'n':
            case 'N': cout << "Neuen Eintrag anlegen." << endl;
                daten.push_back(eintragneu());
                bubblesort(daten);
                break;
            case '2':
            case 'd':
            case 'D': cout << "Bitte geben sie an welcher Eintrag angezeigt werden soll: " << endl;
                cin >> auswahl;
                eintragdetails(daten, auswahl);
                break;
            case '3':
            case 'L':
            case 'l': eintragloeschen(daten);
                break;
            case '4':
            case 'B':
            case 'b': eintragbearbeiten(daten);
                break;
            case '5':
            case 'S':
            case 's': eintragsuchen(daten);
                break;
            case '6':
            case 'a':
            case 'A': cout << "Alle Einträge: " << endl;
                eintraganzeigen(daten);
                break;
            case '0': return 0;
                break;
            case '9': fill (daten);
                break;
            default: cout << "Ungültige Eingabe." << endl;
        }
    }
    return 0;
}



int main() {
    menu();
    return 0;
}

