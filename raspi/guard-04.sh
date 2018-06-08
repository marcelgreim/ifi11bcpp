#!/bin/bash

#Wiring Pi Nummer

LED=29
LED2=28

#IP-Adresse zur Überwachung

IP1=$1

#GPIO als Output auf 0 setzen

gpio mode $LED out
gpio write $LED 0
gpio mode $LED2 out
gpio write $LED2 0

while [ "$?" -ne "10" ]

do

ping -qn -c 1 -W 1 $IP1 > /dev/null

if [ "$?" -ne "0" ]
	then
	gpio write $LED2 0
	gpio write $LED 1

else 
gpio write $LED 0
gpio write $LED2 1
fi

done
 

