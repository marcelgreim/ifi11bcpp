<?php
echo "<html><head><title>Ihre Bestellung</title></header><body bgcolor=\"yellow\"><center><h1>Ihre Pizzabestellung</h1><br>";

$vname = $_GET["vname"];
$nname = $_GET["nname"];
$strasse = $_GET["strasse"];
$hnr = $_GET["hnr"];
$plz = $_GET["plz"];
$ort = $_GET["ort"]; /*
$bar = $_GET["bar"];
$kreditkarte = $_GET["kreditkarte"]; 
$schinken = $_GET["schinken"]; */
$zutaten[] = $_GET["zutaten"]; 
$anzahl = count ( $zutaten );
/* $zwiebeln = $_GET["zwiebeln"];
$pepperoni = $_GET["pepperoni"];
echo "Vorname: $vname<br>";
echo "Nachname: $nname<br>";
echo "Strasse: $strasse %<br>";
echo "Hausnummer: $hnr &euro;<br>";
echo "PLZ: $plz <br>";
echo "Ort: $ort<br>";
echo "Ihre Bezahlmethode: $bar <br>";
echo "Ihre Bezahlmethode: $kreditkarte <br>"; 
echo "Schinken: $schinken<br>";
echo "Zwiebeln: $zwiebeln<br>";
echo "Pepperoni: $pepperoni<br>"; */

for ($x = 0; $x < $anzahl; $x++)
{
    echo "<li>Eintrag von $x ist $zutaten[$x] </li>";
}

echo "</center></body></html>";
?>