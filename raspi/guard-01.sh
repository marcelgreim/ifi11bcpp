#!/bin/bash

#Wiring Pi Nummer

LED=29

#IP-Adresse zur Überwachung

IP1=192.168.121.93

#GPIO als Output auf 0 setzen

gpio mode $LED out
gpio write $LED 0

ping -qn -c 1 -W 1 $IP1 > /dev/null

if [  "$?" -ne "0"  ]
 then
 gpio write $LED 1
fi
