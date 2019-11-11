<?php
header('Access-Control-Allow-Origin: *'); 
if(isset($_GET['id'])){
    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $id = $_GET['id'];
    $resultado = $conex->query("SELECT * FROM `piso` WHERE `id` ='$id'");
	$temp = $resultado->fetch_all(MYSQLI_ASSOC);
    if (!sizeof($temp)){
        die('{"error":-2}');
    }
    else{
        $respuesta = new stdClass();
		$respuesta->detalles_piso = $temp[0];
		print(json_encode($respuesta));
    }
}else{
    die('{"error":-1}');
}
