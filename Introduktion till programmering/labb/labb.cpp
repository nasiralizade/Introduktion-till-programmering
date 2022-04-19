
// Skrivet av: Nasir Alizade
// Skapat datum: 2021-11-25
// Senast ändrat: 2021-11-29
// Kurs: datateknik (A)
// Handledare: Jan-Erik Jonsson

#include <iostream>
#include <sstream>
#include<string>
using namespace std;
int main (){
int tal,max,min,sum=0,antal=0;
double medel;
string tal1;
cout<<"Ange talen för att räkna max,min och medelvärdet!"<<endl;
while (cin>>tal1)
{
    stringstream conv(tal1); //här omvandlar jag från text till tal.
    conv>>tal;
    if(conv.fail()){
        cout<<"fel inmatning!!"<<endl; //om nånting går fel så skrivs det ut fel inmatning.
        return 0;

    }
     antal++;
     sum=sum+tal;
    if(antal==1){ //om man skriver bara ett tal så max och min den värdet.antal är noll från början.
        max=tal;
        min=tal;
    }
    
     
  

    if(max<tal){
        max=tal;
    }
    if(min>tal){
        min=tal;
    }

}
medel=(double)sum/(double)(antal);
cout<<"------------"<<endl;
cout<<"Max: "<<max<<'\n'<<"Min: "<<min<<'\n'<<"medelvärdet: "<<medel<<endl;
return 0;


}