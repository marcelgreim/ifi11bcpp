#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>

using namespace std;

class LED
{
protected:	int pinnumber;
			int zeitdauer;
			int gesamtzeit;

public:		LED(void);
			~LED();
			void zeit(void);
			void ein(void);
			void aus(void);
			
};

LED::LED()
{
	cout << "Pin-Nummer: ";
	cin >> pinnumber;
	cout << "Zeitdauer in Sekunden: ";
	cin >> zeitdauer;
	pinMode (pinnumber, OUTPUT) ;
}

LED::~LED()
{
	digitalWrite (pinnumber,  LOW) ; 
}

void LED::ein()
{
	digitalWrite (pinnumber,  HIGH) ;
	delay(zeitdauer*1000);
}

void LED::aus()
{
	digitalWrite (pinnumber,  LOW) ;
}

class BLINK : public LED
{
	protected:	int blinkzeit;
	
	public:		BLINK(void);
                        void blinken(void);
};

BLINK::BLINK()
{
	cout << "Blinkzeit in Millisekunden: ";
	cin >> blinkzeit;
}

void BLINK::blinken()
{
	for (gesamtzeit = 0; gesamtzeit < 1000*zeitdauer; )
	{
	digitalWrite (pinnumber,  HIGH) ;
	delay(blinkzeit);
	digitalWrite (pinnumber,  LOW) ;
	delay(blinkzeit);
	gesamtzeit = gesamtzeit + 2*blinkzeit;
	}
}

class PWM : public LED
{
	protected:	int tastverh;
	
	public:		PWM(void);
                        void puls(void);
				
};

PWM::PWM()
{
	cout << "TastverhÃ¤ltnis 1000:x mit x = ";
	cin >> tastverh;
	if (tastverh < 0 || tastverh > 1000)
	{
	 cout << "Das TastverhÃ¤ltnis muss zwischen 0 und 1000 liegen!" << endl;
	 exit(1);	
	}
}

void PWM::puls()
{
	for (gesamtzeit = 0; gesamtzeit < 1000*zeitdauer; gesamtzeit++)
	{
		
	digitalWrite (pinnumber,  HIGH) ;
	delayMicroseconds(tastverh);
	digitalWrite (pinnumber,  LOW) ;
	delayMicroseconds(1000-tastverh);
	}
}


int main (void)
{
  int auswahl;
	
  if (wiringPiSetup() == -1)
  {
	  exit(1);
  }
  
  cout << "Auswahl:" << endl << "(1) Ein" << endl << "(2) Blinken" << endl << "(3) PWM" << endl;
  cin >> auswahl;
  
  if ( auswahl == 1)
  {
	  LED Rot;
	  Rot.ein();
  }
  else
  {
	if ( auswahl == 2)
	{
	  BLINK Rot;
	  Rot.blinken();
	}
	else
	{
	  	if ( auswahl == 3)
		{
		 PWM Rot;
		 Rot.puls();
		}
		else
		{
		 cout << "Falsche Eingabe!" << endl;
		}
	}
  }
  
  return 0 ;
}
