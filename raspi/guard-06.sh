#!/bin/bash

#Wiring Pi Nummer

LED=29
LED2=28
temp=0

#IP-Adresse zur Überwachung

iparray=(192.168.121.46 192.168.121.161)


#GPIO als Output auf 0 setzen

gpio mode $LED out
gpio write $LED 0
gpio mode $LED2 out
gpio write $LED2 0

while [ "0" -ne "1" ]

do

for i in ${iparray[@]}

do

ping -qn -c 1 -W 1 $i > /dev/null

if [ "$?" -ne "0" ]
	then
	gpio write $LED2 0
	gpio write $LED 1
	temp=1
else

if [ $temp -eq "1" ]
then  
echo hi > /dev/null
temp=0
else
gpio write $LED2 1
gpio write $LED 0
fi
fi


done
done
