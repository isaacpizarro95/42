<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
class ConexionBD {

    private $conex;

    public function __construct() {
        $this->conex = new mysqli("remotemysql.com", "pBlHUB3z4B", "R4v97XCBJb", "pBlHUB3z4B", "3306");
        if ($this->conex->connect_error) {
            die('La conexión ha fallado, error número ' . $this->conex->connect_errno . ': ' . $this->conex->connect_error);
        }
    }

    public function __destruct(){
        $this->conex->close();
    }

    public function getConex() {
        return($this->conex);
    }
}
?>