
<?php

/*******************************************************
IoTbutton V0.2
Check the state of a button conected to an ESP8266 v01 from a website with PHP.
Visualizar el estado de un botón conectado a un ESP8266 v01 desde un sitio web con PHP.
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

if($_GET['state']=="ON") {

	file_put_contents($file, "ON");
}

if($_GET['state']=="OFF") {

	file_put_contents($file, "OFF");

}

echo "Estado del botón: ";
echo file_get_contents($file); // muestra el ultimo estado

?>


