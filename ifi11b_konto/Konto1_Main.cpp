#include <iostream> // Standardbibliothek laden
#include "Konto1.h" //Ausgelagerten Proogramminhalt hier laden als #include

using namespace std; //Standardnamensraum verwenden


int main() {
	
	// Ein neues Objekt nach der Klasse Konto erzeugen und es soll einen neuen Namen haben und zwar Meinkonto
	
	Konto Meinkonto; // Erstellt en Objekt
// 	Konto Meinkonto2; // Zweites Objekt
	
	//Kontostand auf Anfangswert setzen
	
	Meinkonto.Kontostand = 10000;
//	Meinkonto2.Kontonummer = -100; // Zweites Objekt
	// Setze Anfangswerte ein.
	
	Meinkonto.setdata();
//	Meinkonto2.setdata(); // Zweites Objekt
	
	// Zeige alles an
	
	Meinkonto.Anzeigen();
//	Meinkonto2.Anzeigen(); // Zweites Objekt

	Meinkonto.Einzahlen();
	
	Meinkonto.Anzeigen();
	
	Meinkonto.Auszahlen();
	
	Meinkonto.Anzeigen();
	
	return 0;
}
