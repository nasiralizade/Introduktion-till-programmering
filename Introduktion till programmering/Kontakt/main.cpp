/*
Namn: Nasir Alizade (naal2001)
Kurs: Introduktion till progarmmering
Handledare: Nayeb Maleki
Projekt: contacts
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Addkontakt.h"
#include "visa.h"
#include "tabort.h"
#include "sok.h"

using namespace std;
int main()
{
    bool KÖR = true;
    do
    {
        cout  << "---------------------KONTAKT--------------------" << endl;
        char option;
        cout<<endl;
        cout << "Välj en option: "<<endl;
        cout << "1. Add kontakt: " << endl;
        cout << "2. Visa kontakt: " << endl;
        cout << "3. Sök kontakt: " << endl;
        cout << "4. Ta bort kontakt: " << endl;
        cout << "5. Exite: " << endl;
        cout << "Option: ";
        cin >> option;
        switch (option)
        {
        case 49:
            Addkontakt();
            break;
        case 50:
            visa();
            break;
        case 51:
            sok();
            break;
        case 52:
            tabort();
            break;
        case 53:
         KÖR = false;
            break;
        default:
            cout << " Ange mellan 1 till 5: " << endl;
        }

    } while  (KÖR);
    cout << "Programmet avslutades" << endl;
}
