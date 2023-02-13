/*
Kurs: Introduktion till progarmmering
Projekt: contacts
*/
#include <iostream>
#include <string>
#include <fstream>
#include "main.h"

using namespace std;
void sok()
{
    ifstream kontakt("kontaktbok.txt");
    string inmatning, lista;
    int nummer = 0;
    cout << "Vad vill du söka? ";
    cin >> inmatning;
    //med loopen omvanlar jag inmatningen till småbokstäver.
    for (int i = 0; i < inmatning.length(); i++)
    {
       inmatning[i]=tolower(inmatning[i]);

    }
    cout << endl;
    cout << "-------------------------Hittades---------------------------" << endl;
    getline(kontakt, lista);
    while (!kontakt.eof())
    {
    for (int i = 0; i < lista.length(); i++)
        {
             lista[i]=tolower(lista[i]);

        }
        
        // den här sökning algoritm kallas för Naive Algorithm.
        
        int ord = inmatning.length();
        int boken = lista.length();
        for (int i = 0; i <= boken - ord; i++)
        {
            int j;
            for (j = 0; j < ord; j++)//om den loopas lika mycket som längden av inmatningen, så betyder det en matchning
            {

                if (lista[i + j] != inmatning[j])
                    break;
            }

            if (j == ord) // om inmatningen matchar med kontakten.
            {
                nummer++;
                cout << lista << endl;
                break;
            }
        }
        getline(kontakt,lista);
    }
    if (nummer == 0)
    {   
        cout << "Din sökning matchade 0 gånger." << endl;
        main();
    }
    else cout<<endl<<"Din sökning matchade "<<nummer<<" gånger."<<endl;
}
