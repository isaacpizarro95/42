<?php
header('Access-Control-Allow-Origin: *'); 
if(isset($_GET['ciudad'])){
    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $ciudad = $_GET['ciudad'];
    $resultado = $conex->query("SELECT `id`, `nombre`, `latitud`, `longitud` FROM `piso` WHERE `ciudad` ='$ciudad'");
	$temp = $resultado->fetch_all(MYSQLI_ASSOC);
	if (!sizeof($temp)){
        die("{error:-2}");
    }
    else{
		$respuesta = new stdClass();
		$respuesta->pisos = $temp;
		print(json_encode($respuesta));
    }
}else{
    die("{error:-1}");
}

?>