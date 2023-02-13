/*
Kurs: Introduktion till progarmmering
Projekt: contacts
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "main.h"
using namespace std;
void visa()
{
    system("clear");
    string Fname2, Lname2, gatunamn2, gatunummer2, postnummer2, ort2, email2, telefonnummer2, födelsedag2, övrigt2;
    ifstream in("kontaktbok.txt");

    cout
        << "_____________________________________________________KONTAKT_LISTA___________________________________________________________ " << endl
        << endl;
    string kontakt;
    int counter;
    cout << left << setw(10) << "Lista#" << left << setw(13) << "Namn" << left << setw(36) << "Post-adress" << left << setw(27) << "E-post"
         << setw(22) << "Telefonnummer" << setw(24) << "Födelsedatum" << setw(15) << "Övrigt" << endl
         << endl;
    in >> counter >> Fname2 >> Lname2 >> gatunamn2 >> gatunummer2 >> postnummer2 >> ort2 >> email2 >> telefonnummer2 >> födelsedag2;
    in.ignore();
    getline(in, övrigt2);

    while (!in.eof())
    {
        string adress, name;
        name = Fname2 + " " + Lname2;
        adress = gatunamn2 + " " + gatunummer2 + " " + postnummer2 + " " + ort2;
        cout << setw(2) << counter << "  " << left << setw(16) << name << left << setw(3) << "||" << left << setw(33) << adress << left << setw(3) << "||" << left << setw(27) << email2
             << left << setw(3) << "||" << left << setw(20) << telefonnummer2 <<left<<setw(3)<<"||"<< left << setw(13) << födelsedag2 <<left<<setw(6)<<"||"<< övrigt2 << endl;

        in >> counter >> Fname2 >> Lname2 >> gatunamn2 >> gatunummer2 >> postnummer2 >> ort2 >> email2 >> telefonnummer2 >> födelsedag2;
        in.ignore();
        getline(in, övrigt2);
    }
    cout<<endl;
}
