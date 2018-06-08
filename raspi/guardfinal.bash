#!/bin/bash

trap Beenden 1 2 3 4 15

if [ $# -ne 2 ]
 then
 echo "Falsche Parameterzahl!"
 exit 1
fi

# Setzt WiringPi-Nummern der LEDs und Dateipfad
ROT=$1
GRUEN=$2
IPFILE="/work/guard/guard.conf"

# GPIOs als Output mit 0 Volt setzen
gpio mode $ROT out
gpio mode $GRUEN out
gpio write $ROT 0
gpio write $GRUEN 0

function Beenden {
gpio write $ROT 0
gpio write $GRUEN 0
exit 0
}

# Log-Datei anlegen
LOGFILE="/work/guard/guard.log"
echo "" > $LOGFILE

while [ true ]
do

iparray=( `cat $IPFILE` )
# Zähler für Ping-Fehler
counter=0

 # For-Schleife durchläuft Array-Werte und zählt Fehler
 for i in ${iparray[@]}
 do
  ping -qn -c 1 -W 1 $i > /dev/null
  if [ "$?" -ne "0" ]
  then
   ((counter++))
   echo $(date +%Y-%m-%d_%H:%M:%S) $i >> $LOGFILE
  fi
 done

 # Auswertung des Zählerstandes
 if [ $counter -gt 0 ]
  then
   gpio write $ROT 1
   gpio write $GRUEN 0
 else
   gpio write $ROT 0
   gpio write $GRUEN 1
 fi
 
 sleep 1
 
done
