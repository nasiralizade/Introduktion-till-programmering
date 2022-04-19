#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "sort.h"
using namespace std; 

void merge (string file1, string file2, string filut)
{
    ifstream filen(file1);
    ifstream filen2(file2);
    ofstream utFile(filut);
    int x , y; 
    filen>>x; 
    filen2>>y;
    while (!filen.eof()&&!filen2.eof())
    {
        if (x<y)
        {
            utFile<<x<<" ";
            filen>>x; 
        }
        else 
        {
            utFile<<y<<" ";
            filen2>>y;
        }
    }
    while(!filen.eof())
    {
        utFile<<x<<" ";
        filen>>x;
    }
    while(!filen2.eof())
    {
        utFile<<y<<" ";
        filen2>>y;
    }
}