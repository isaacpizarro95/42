<?php

if(isset($_GET['id'])){
    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $id = $_GET['id'];
    $resultado = $conex->query("SELECT * FROM `piso` WHERE `id` ='$id'");
    $temp = $resultado->fetch_all(MYSQLI_ASSOC);
    var_dump($temp);
    if (!sizeof($temp)){
        die("{error:-2}");
    }
    else{
        die("{error: 1}");
    }
}else{
    die("{error:-1}");
}

?>