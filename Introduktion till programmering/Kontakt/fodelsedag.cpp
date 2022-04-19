/*
Namn: Nasir Alizade (naal2001)
Kurs: Introduktion till progarmmering
Handledare: Nayeb Maleki
Projekt: contacts
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int fodelsedag(string födelsedag)
{
    string år, månad, dag;
    int år1, månad1, dag1;

    for (int i = 0; i < födelsedag.length(); i++)
    {
        if (!isdigit(födelsedag[i]) || födelsedag.length() != 8)
        {
            return 0;
        }
        år = födelsedag.substr(0, 4);
        månad = födelsedag.substr(4, 2);
        dag = födelsedag.substr(6, 2);
    }
    istringstream(år) >> år1;
    istringstream(månad) >> månad1;
    istringstream(dag) >> dag1;
    if (år1 < 1800 || år1 > 2022 || månad1 > 12 || månad1 < 0 || dag1 > 32 || dag1 < 0)
    {
        return 0;
    }
    else return 1;
}