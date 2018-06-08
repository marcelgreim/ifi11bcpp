#include <iostream> // Standardbibliothek laden

using namespace std; //Standardnamensraum verwenden

class Konto { // Beginn der Klasse
	
public: 	string Vorname;
			string Nachname;
			int Kontonummer;
			double Kontostand;
			
				void setdata(void) {
					cout << "\nEin neues Konto wird angelegt:";
					cout << "\nNachname:\t";
					cin >> Nachname;
					cout << "Vorname:\t";
					cin >> Vorname;
					cout <<"Kontonummer:\t";
					cin >> Kontonummer;
				}
				
				
				void Anzeigen(void) {
					cout << "\nKontonummer:\t\t" << Kontonummer << endl;
					cout << "Inhaber/in:\t\t" << Vorname << endl;
					cout << "Aktueller Kontostand:\t" << Kontostand << endl;
					cout << " Euro" << endl;
				}
				
				void Einzahlen(void) {
					int temp;
					int temp2;
					cout << "Wieviel moechten Sie einzahlen lassen?\t" << endl;
					cin >> temp;
					temp2=Kontostand+temp;
					Kontostand=temp2;
					cout << endl;
				}
				
				void Auszahlen(void) {
					int temp;
					int temp2;
					cout << "Wieviel moechten Sie sich auszahlen lassen?\t" << endl;
					cin >> temp;
					temp2=Kontostand-temp;
					Kontostand=temp2;
					}
};
