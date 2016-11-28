<?php

/*******************************************************

IoTController V0.2
Control a ESP8266 v01 from a website with PHP.
Controle a ESP8266 v01 desde un sitio web con PHP.
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

$file = 'data.txt';
$file2 = 'data2.txt';

if($_GET['GPIO0']=="ON") {

	file_put_contents($file, "ON");
}

if($_GET['GPIO0']=="OFF") {

	file_put_contents($file, "OFF");

}

if($_GET['GPIO2']=="ON") {

	file_put_contents($file2, "ON");
}

if($_GET['GPIO2']=="OFF") {

	file_put_contents($file2, "OFF");

}

echo "Estado actual GPIO0: ";
echo file_get_contents($file); // muestra el ultimo estado
echo " Estado actual GPIO2: ";
echo file_get_contents($file2); // muestra el ultimo estado
?>
<br>
<br>
Control de estado para GPIO0:
<form method="post" action="index.php?GPIO0=ON">
    <button type="submit">ON</button>
</form>
<form method="post" action="index.php?GPIO0=OFF">
    <button type="submit">OFF</button>
</form>
<br>
Control de estado para GPIO2:
<form method="post" action="index.php?GPIO2=ON">
    <button type="submit">ON</button>
</form>
<form method="post" action="index.php?GPIO2=OFF">
    <button type="submit">OFF</button>
</form>


