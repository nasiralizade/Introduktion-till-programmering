// Nasir ALizade (naal2001)
// Kurs: Datateknik(A)
// Handledare: Jan-Erik Jonsson

#include <iostream>
#include <fstream>
#include <map>
#include <string>  
using namespace std;
int main()
{	
	ifstream textfilen("hitchhikersguide.txt");
	map<string, int> freq;
     //en vanlig map innehåller en unik nyckel(key).
     // Multimap kan innehålla flera samma keys
    //string(key) && int (value)
	string orden;           
	while(textfilen>>orden) 
	{
		for(int i=0; i<orden.length(); i++) 
		{
           orden[i]=tolower(orden[i]); //omvandlar till småbokstäver 
           if(orden[i]<'a' || orden[i] >'z') // rensar lite skräp som förekommer
			{
				orden.erase(i,1); 
				i--; 

			}
		}
        if(orden.length()==0)
            {
                orden.erase();
            }
        else
            {
                freq[orden]++;
            }	
	}
    //nu vet man antal upprepningen på orden.
    
    multimap<int, string>antalet; 
    map<string, int>::iterator iter;
    for( iter=freq.begin(); iter!=freq.end();iter++)
    {
        antalet.insert(pair<int, string>(iter->second, iter->first));   
    }
    cout<<"-------------Top 50----------- "<<endl;
    int top=50;
   
    multimap<int , string> ::reverse_iterator itero;//dom med högst key värdet kommer ligga sist i listan 
    for ( itero=antalet.rbegin();itero!=antalet.rend() && top>0; itero++)
    {
        
        cout<<itero->first<<": "<<itero->second<<endl;
        top--;
    }
    
    return 0;
}