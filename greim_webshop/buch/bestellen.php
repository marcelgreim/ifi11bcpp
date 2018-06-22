<?php
$bestellmenge = $_GET["menge"];
$faktor = 0;
$pauschale = 0;
$preis = 0;
$mwstsatz = 7;
$endpreistmp = 0;
$endpreis = 0;

if ($bestellmenge >=100) {
	$faktor=15;
}
else {
	if ($bestellmenge >=50) {
		$faktor = 10;
	}
		else {
			if ($bestellmenge >=10) {
				$faktor = 5;
			}
		}
		
}

$preis = ($bestellmenge*23.50)-((($bestellmenge*23.50) / 100) * $faktor);

if ($preis >= 100) {
	$pauschale = 0;
}
	else {
		$pauschale = 5.50;
	}

$endpreistmp = $preis + $pauschale;


$endpreis = (($endpreistmp/100)*7)+$endpreistmp;

$endpreisrnd = round ($endpreis,2);
$preisrnd = round ($preis,2);

echo "<html><head><title>Ihr Bestellung</title></header><body bgcolor=\"yellow\"><center><h1>Ihr Rechnungsbetrag</h1><br>";
echo "Bestellmenge: $bestellmenge Stk<br>";
echo "Preis ohne MwST: $preisrnd &euro;<br>";
echo "Rabatt von: $faktor %<br>";
echo "Versandpauschale: $pauschale &euro;<br>";
echo "Anzuwendender Steuersatz: $mwstsatz %<br> <br>";
echo "<b>Gesammtsumme: $endpreisrnd &euro;</b><br>";
echo "</center></body></html>";


?>