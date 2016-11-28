
<?php

/*******************************************************
IoTServo V0.1
Control a Servo with a ESP8266 v01 from a website with PHP.
Controle un Servo con un ESP8266 v01 desde un sitio web con PHP.
https://github.com/hiteclab/IoTController
********************************************************
ENGLISH
********************************************************
Developed by Jose David Cuartas
Hypermedia Lab of Technologies for Communication
University Los Libertadores
Bogotá, Colombia, 2016.
GPL license V3
********************************************************
ESPAÑOL
********************************************************
Desarrollado por Jose David Cuartas Correa
Laboratorio Hipermedia de Tecnologias para Comunicación
Fundación Universitaria Los Libertadores
Bogotá, Colombia, 2016.
Licencia GPL Versión 3 
*******************************************************/

$file = 'valor.txt';
$valor = file_get_contents($file);

if($_GET['state']=="MAS1") {

	if($valor<180) $valor += 1;
}

if($_GET['state']=="MENOS1") {
	
	if($valor>0) $valor -= 1;
}

if($_GET['state']=="0") {
	
	$valor = 0;
}

if($_GET['state']=="90") {
	
	$valor = 90;
}

if($_GET['state']=="180") {
	
	$valor = 180;
}

if($_GET['state']=="MAS10") {

	if($valor<171) $valor += 10;
}

if($_GET['state']=="MENOS10") {
	
	if($valor>9) $valor -= 10;
}


file_put_contents($file, $valor);

echo "Posición asignada al servo: ";
echo file_get_contents($file); // muestra el ultimo estado

?>
<br>
<br>
<form method="post" action="index.php?state=MAS1">
    <button type="submit">+1</button>
</form>
<form method="post" action="index.php?state=MENOS1">
    <button type="submit">-1</button>
</form>

<form method="post" action="index.php?state=0">
    <button type="submit">0</button>
</form>

<form method="post" action="index.php?state=90">
    <button type="submit">90</button>
</form>

<form method="post" action="index.php?state=180">
    <button type="submit">180</button>
</form>

<form method="post" action="index.php?state=MAS10">
    <button type="submit">+10</button>
</form>
<form method="post" action="index.php?state=MENOS10">
    <button type="submit">-10</button>
</form>