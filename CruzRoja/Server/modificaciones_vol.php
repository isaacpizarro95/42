<?php
header('Access-Control-Allow-Origin: *'); 
if(isset($_GET['id'])){
    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $id = $_GET['id'];
    $num_usuarios = $_GET['num_usuarios'];
    $num_voluntarios = $_GET['num_voluntarios'];
    $horario = $_GET['horario'];
    $lavadora = $_GET['lavadora'];
    $plancha = $_GET['plancha'];
    $ducha = $_GET['ducha'];
    $cocina = $_GET['cocina'];
    $comida = $_GET['comida'];
    $accesibilidad = $_GET['accesibilidad'];
    $resultado = $conex->query("SELECT * FROM `piso` WHERE `id` ='$id'");
    $sql = "UPDATE `piso` SET `num_usuarios`= $num_usuarios, `num_voluntarios`= $num_voluntarios, `horario` = $horario, `lavadora` = $lavadora, 
    `plancha` = $plancha, `ducha` = $ducha, `cocina` = $cocina, `comida` = $comida, `accesibilidad` = $accesibilidad WHERE `id` = $id";
    if ($sql){
        die("{error: 1}");
    }
    else{
        die("{error: -2}");
    }
}else{
    die("{error:-1}");
}

?>