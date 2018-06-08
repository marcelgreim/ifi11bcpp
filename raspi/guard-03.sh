#!/bin/bash

#Wiring Pi Nummer

LED=29

#IP-Adresse zur Überwachung

IP1=$1

#GPIO als Output auf 0 setzen

gpio mode $LED out
gpio write $LED 0

while [ "$?" -ne "10" ]

do

ping -qn -c 1 -W 1 $IP1 > /dev/null

if [ "$?" -ne "0" ]
	then
	gpio write $LED 1

else 
gpio write $LED 0
fi

done
 

