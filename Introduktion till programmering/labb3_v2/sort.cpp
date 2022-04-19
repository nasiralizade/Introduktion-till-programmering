#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "sort.h"
using namespace std; 

int sort (string file)
{
    int a = 0, b = 0; 
    bool status ; 
    fstream minFil (file);
    minFil>>a;
    while (!minFil.eof())
    {
        minFil>>b; 
        if (a <= b)
        {
            a=b; 
            status = true; 
        }
        else 
        {
            status = false; 
            break; 
        }
    }
minFil.close();
return status; 
}
