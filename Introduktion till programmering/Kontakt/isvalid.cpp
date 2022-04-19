#include <iostream>
using namespace std;
int isvalid(string email)
{

    if (!isalpha(email[0]))
    {
        return 0;
    }
    int snabela = -1,punkt = -1;

    for (int i = 0; i < email.length(); i++) //med loopen hittar jag positionen av '@' och '.'
    {
        if (email[i] == '@')
        {
            snabela = i;
        }
        else if (email[i] == '.')
        {
        punkt = i;
        }
    }
    //om gmail inte innehåller '@' eller '.' returneras 0
    if (snabela == -1 ||punkt == -1)
        return 0;
    
    return !(punkt >= (email.length() - 1));
}