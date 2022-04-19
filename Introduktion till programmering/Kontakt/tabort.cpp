/*
Namn: Nasir Alizade (naal2001)
Kurs: Introduktion till progarmmering
Handledare: Nayeb Maleki
Projekt: contacts
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "main.h"
#include "sok.h"

using namespace std;
void tabort()
{
    system("clear");
    cout<<"Sök efter den kontakten du vill radera! "<<endl;
    sok();
    string inmatning, räknare,listan, JellerN;
    ifstream edit("kontaktbok.txt");
    ofstream temp("temp.txt");
    cout << "Vänligen ange den numret som står till vänster av kontakten som du vill ta bort! " << endl;
    cin >> inmatning;

    cout << endl;
    // den här loopen överför alla kontakter till en ny textfile förutom den man vill ta bort,
    // och sedan byter namnet på nya textfilen till den gamla.
    while (edit >> räknare, getline(edit, listan))
    {
        if (räknare == inmatning)
        {
            cout << listan << endl
                 << endl;
            cout << "Är den här kontakten du vill ta bort? (j/n) ";
            cin >> JellerN;
            cout << endl;
        }
        if (JellerN == "n")
        {
            cout<<"Tack för din besök!"<<endl;
            main();
        }
        if (räknare < inmatning)
        {
            temp << räknare << " " << listan << endl;
        }
        if (räknare > inmatning)
        {
            int räknare2;
            istringstream(räknare) >> räknare2;
            temp << räknare2 - 1 << " " << listan << endl;
            cout<<"Kontakten raderades!"<<endl;
        }
    }
    
    

    edit.close();
    temp.close();
    if (remove("kontaktbok.txt") == 0)
    {
        cout << " lyckat förflyttning " << endl;
    }
    else
    {
        cout << "error flyttning" << endl;
    }
    if (rename("temp.txt", "kontaktbok.txt") == 0)
    {
        cout << "namn bytning lyckats" << endl;
        system("clear");
    }
    else
    {
        cout << "namn bytning misslyckades" << endl;
    }
    if (inmatning>räknare)
    {
        system("clear"); //no
        cout<<"Tack för din besök!"<<endl;
    }
}
