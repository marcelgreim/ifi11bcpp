#include <iostream> // Standardbibliothek laden
#include "Konto1.h" //Ausgelagerten Proogramminhalt hier laden als #include

using namespace std; //Standardnamensraum verwenden


int wdh=0;

int main() {
	
	// Ein neues Objekt nach der Klasse Konto erzeugen und es soll einen neuen Namen haben und zwar Meinkonto
	
	
	Konto(); // Aufruf Konstruktor 
	Konto Meinkonto; // Erstellt en Objekt
	Meinkonto.setdata();

	do {
		int abgleich = 0;
		cout << "Bitte geben Sie 1 fuer Konto anzeigen, 2 fuer Einzahlen, 3 fuer Auszahlen und 4 fuer Beenden ein" << endl;
		cin >> abgleich;
		switch (abgleich) {
			case(1): {
			Meinkonto.Anzeigen();
			break;
		}
			case (2): {
				Meinkonto.Einzahlen();
				break;
			}
			case (3): {
				Meinkonto.Auszahlen();
				break;
			}	
			case (4): {
				wdh=4;
				break;
			}		
	}
}
while(wdh!=4);
	
	
Meinkonto.~Konto();
	
	return 0;
	
	//Systemdestruktur
}
