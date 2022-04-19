#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "merge.h"
#include "sort.h"
using namespace std; 

void sort2(string file, string file2, string file3, string fileOut )
{
    bool a, b, c; 
    a = sort(file);
    b = sort(file2); 
    c = sort(file3); 

    if (a == true && b == true)
    {
        merge(file, file2, fileOut );
        cout<<file <<" och "<<file2<< " är sorterat"<<endl; 
    }
    if (a == true && c == true)
    {
        merge(file, file3, fileOut );
        cout<<file <<" och "<<file3<< " är sorterat"<<endl; 
    }
    if (b == true && c == true)
    {
        merge(file2, file3, fileOut );
        cout<<file2 <<" och "<<file3<< " är sorterat"<<endl; 
    }
    