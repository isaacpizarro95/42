<?php
	header('Access-Control-Allow-Origin: *'); 
    $respuesta = new stdClass();

    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $resultado = $conex->query("SELECT DISTINCT `ciudad` FROM `piso`");
    $temp = $resultado->fetch_all();
    for($i = 0; $i < sizeof($temp); $i++){
       $respuesta->ciudades[$i] = $temp[$i][0]; 
    }
    print(json_encode($respuesta));
?>