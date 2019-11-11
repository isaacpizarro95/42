-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 08-11-2019 a las 06:52:21
-- Versión del servidor: 10.4.8-MariaDB
-- Versión de PHP: 7.3.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `test`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `login_password`
--

CREATE TABLE `login_password` (
  `login` varchar(50) NOT NULL,
  `password` varchar(30) NOT NULL,
  `tipo` tinyint(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `login_password`
--

INSERT INTO `login_password` (`login`, `password`, `tipo`) VALUES
('isfernan', 'trabajarmata123', 1),
('mbahstou', 'trabajarduele456', 1),
('otros', 'manolo_45', 0),
('pepe_federico', 'identidad000', 0),
('una_mujer', 'botellas_rotas456', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `piso`
--

CREATE TABLE `piso` (
  `id` int(255) NOT NULL,
  `nombre` varchar(1000) NOT NULL,
  `ciudad` varchar(1000) NOT NULL,
  `direccion` varchar(1000) NOT NULL,
  `latitud` float NOT NULL,
  `longitud` float NOT NULL,
  `aforo` int(30) NOT NULL,
  `num_usuarios` int(30) NOT NULL,
  `num_voluntarios` int(30) NOT NULL,
  `horario` varchar(1000) NOT NULL,
  `lavadora` tinyint(2) NOT NULL,
  `plancha` tinyint(2) NOT NULL,
  `ducha` tinyint(2) NOT NULL,
  `cocina` tinyint(2) NOT NULL,
  `comida` tinyint(2) NOT NULL,
  `accesibilidad` tinyint(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `piso`
--

INSERT INTO `piso` (`id`, `nombre`, `ciudad`, `direccion`, `latitud`, `longitud`, `aforo`, `num_usuarios`, `num_voluntarios`, `horario`, `lavadora`, `plancha`, `ducha`, `cocina`, `comida`, `accesibilidad`) VALUES
(1, 'la zapatera', 'madrid', 'c/camino humanes 36 6ºA', 40.4004, -3.66271, 30, 12, 4, '10:00-20:00', 0, 0, 0, 1, 1, 1),
(2, 'la tahona', 'granada', 'c/pez 34 2ºB', 37.1636, -3.59615, 14, 2, 1, '9:00-20:00', 1, 0, 0, 0, 1, 1),
(3, 'kilombo', 'granada', 'c/tiburon 125 3ºA', 37.1788, -3.59223, 12, 3, 2, '8:00-20:00', 1, 0, 1, 1, 1, 0),
(4, 'gaudi', 'barcelona', 'c/federico garcia lopez 45 bajo B', 41.3643, 2.12451, 20, 18, 4, '10:30-21:00', 0, 1, 0, 1, 0, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `piso-voluntario`
--

CREATE TABLE `piso-voluntario` (
  `id_piso` int(255) NOT NULL,
  `id_voluntario` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `piso-voluntario`
--

INSERT INTO `piso-voluntario` (`id_piso`, `id_voluntario`) VALUES
(1, 1),
(1, 2),
(1, 3),
(2, 4),
(3, 5),
(4, 6);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `voluntario`
--

CREATE TABLE `voluntario` (
  `id` int(255) NOT NULL,
  `especialidad` varchar(1000) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `voluntario`
--

INSERT INTO `voluntario` (`id`, `especialidad`) VALUES
(1, 'psicolog@'),
(2, NULL),
(3, 'profesor@'),
(4, 'médico'),
(5, 'fisioterapeuta'),
(6, NULL);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `login_password`
--
ALTER TABLE `login_password`
  ADD PRIMARY KEY (`login`);

--
-- Indices de la tabla `piso`
--
ALTER TABLE `piso`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `piso-voluntario`
--
ALTER TABLE `piso-voluntario`
  ADD PRIMARY KEY (`id_piso`,`id_voluntario`);

--
-- Indices de la tabla `voluntario`
--
ALTER TABLE `voluntario`
  ADD PRIMARY KEY (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
