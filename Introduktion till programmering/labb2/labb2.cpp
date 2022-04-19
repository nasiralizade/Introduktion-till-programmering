#include <iostream>
#include <sstream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream minfil; //läser från textfiler 
	ofstream utfil;   //skriver till textfiler
	minfil.open("names.txt");
	utfil.open("resultat.txt");
	string förnam,efternam,adress,personnummer,gender;
	while(!minfil.eof()) //loopen körs tills den har gått igenom hela filen.
	{
		minfil>>förnam; //här tilldelar jag variabler
		minfil>>efternam;
		minfil>>personnummer;
		int genders=personnummer[8]; //om den näst sista siffran på personnumret udda=man, jämt=kvinna
		if (genders%2==0)
		{
			gender="[K]";
		}
		else
		{
			gender="[M]";
		}
		minfil.ignore(); 
		getline(minfil,adress);
		if (minfil.fail	())
		{
			break;
			
		}
		utfil<<efternam<<' '<<förnam<<' '<<gender<<endl;
		utfil<<adress<<endl;
		


	}


	utfil.close();
	minfil.close();


	return 0;
}