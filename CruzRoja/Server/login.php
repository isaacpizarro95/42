<?php
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');  
if(isset($_POST['login']) && isset($_POST['password'])){
    require_once('conexion_server.php');
    $new_conexion = new ConexionBD();
    $conex = $new_conexion->getConex();
    $login = $_POST['login'];
    $password = $_POST['password'];
    $resultado = $conex->query("SELECT `tipo` FROM `login_password` WHERE `login` ='$login' AND `password` = '$password'");
    $temp = $resultado->fetch_all();
    if (!sizeof($temp)){
        die('{"error":-2}');
    }
    else{
        die('{"tipo":'.$temp[0][0].'}');
    }
}else{
    die('{"error":-1}');
}
$conex->close();

?>