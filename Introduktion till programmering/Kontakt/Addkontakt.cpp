/*

Kurs: Introduktion till progarmmering
Projekt: contacts
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "main.h"
#include "isvalid.h"
#include "fodelsedag.h"
using namespace std;
void Addkontakt()
{
    system("clear");

    string Fname, Lname, gatunamn, gatunummer, postnummer, ort, email, telefonnummer, födelsedag, övrigt,
        Fname2, Lname2, gatunamn2, gatunummer2, postnummer2, ort2, email2, telefonnummer2, födelsedag2, övrigt2;
    cout << "Använd inte 'mellanslag' om namnet består av flera namn, skriv på det här sättet istället: (AntonErik) " << endl;
    cout << "Förenamn: ";
    cin >> Fname;
    cout << "Efternamn: ";
    cin >> Lname;
    while (!isalpha(Fname[0]) || !isalpha(Lname[0]))
    {
        cout << "Namn får inte börja med ett tal! ";
        cout << "Förenamn: ";
        cin >> Fname;
        cout << "Efternamn: ";
        cin >> Lname;
    }
    cout << "------------Post adress------------" << endl;
    cout << "Ange gatunamn (utan gatunummer): " << endl;
    cout << "gatunamn: ";
    cin >> gatunamn;
    while (!isalpha(gatunamn[0]))
    {
        cout << "Gatunamn får inte börja med ett tal! ";
        cout << "Gatunamn: ";
        cin >> gatunamn;
    }
    cout << "Gatunummer: ",
        cin >> gatunummer;
    cout << "Använd inte mellanslag när du anger postnummer! ";
    cout << "Postnummer: ";
    cin >> postnummer;
    for (int i = 0; i < postnummer.length(); i++)
    {
        if (!isdigit(postnummer[i]) || postnummer.length() != 5)
        {
            cout << "Ogiltigt postnummer, försök igen! ";
            cin >> postnummer;
        }
    }
    cout << "Stad/ort: ";
    cin >> ort;
    cout << " Ange E-post adress: ";
    cin >> email;
    bool svar = isvalid(email);
    while (svar != 1)
    {
        cout << " Vänligen skriv rätt E-post! ";
        cin >> email;
        bool svar = isvalid(email);
        if (svar)
        {
            cout << email << ": Giltigt" << endl;
            break;
        }
        else
            cout << "Ogiltigt E-post, försök igen:  " << endl;
    }

    cout << "Ange telefonnummer: ";
    cin >> telefonnummer;
    for (int i = 0; i < telefonnummer.length(); i++)
    {
        if (!isdigit(telefonnummer[i]) || telefonnummer.length() != 10)
        {
            cout << "Ogiltigt telefonnummer, försök igen! ";
            cout << "Telefonnummer: ";
            cin >> telefonnummer;
        }
    }

    string år, månad, dag;
    cout << "Ange  födelsedag (ÅÅÅÅMMDD) " << endl;
    cout << "Födelsedag: ";
    cin >> födelsedag;
    bool svar1 = fodelsedag(födelsedag);
    while (svar1 != 1)
    {
        cout << "Ogiltigt födelsedag, försök igen! ";
        cin >> födelsedag;
        bool svar1 = fodelsedag(födelsedag);
        if (svar1)
        {
            cout << födelsedag << ": Giltigt" << endl;
            break;
        }
        else
            cout << "Ogiltigt, Försök igen:  " << endl;
    }
    cout << "Övrigt: ";
    cin.ignore();
    getline(cin, övrigt);
    int nummer = 0, räknare = 0;
    ifstream in("kontaktbok.txt");
    // Läser kontakter som finns i textfilen.
    while (in >> räknare >> Fname2 >> Lname2 >> gatunamn2 >> gatunummer2 >> postnummer2 >> ort2 >> email2 >> telefonnummer2 >> födelsedag2 >> övrigt2)
    {
        if (räknare == 100)
        {
            cout << "Kontakt boken är fullt, kan ej läggas mer kontakter." << endl;
            main();
        }
        else
        {
            nummer = räknare;
        }
    }
    ofstream ut("kontaktbok.txt", ios::app);
    nummer = nummer + 1; // Använder siffror franför kontakter, att ge dem ett unik id.
    ut << nummer << " " << Fname << " " << Lname << " " << gatunamn << " " << gatunummer << " " << postnummer << " "
       << ort << " " << email << " " << telefonnummer << " " << födelsedag << " " << övrigt << endl;
    
}
