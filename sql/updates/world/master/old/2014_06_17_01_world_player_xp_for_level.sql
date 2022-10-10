-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Хост: localhost
-- Время создания: Июн 17 2014 г., 19:20
-- Версия сервера: 10.0.10-MariaDB
-- Версия PHP: 5.3.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `u_world`
--

-- --------------------------------------------------------

--
-- Структура таблицы `player_xp_for_level`
--

DROP TABLE IF EXISTS `player_xp_for_level`;
CREATE TABLE `player_xp_for_level` (
  `lvl` tinyint(3) unsigned NOT NULL,
  `xp_for_next_level` int(10) unsigned NOT NULL,
  PRIMARY KEY (`lvl`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `player_xp_for_level`
--

INSERT INTO `player_xp_for_level` (`lvl`, `xp_for_next_level`) VALUES
(1, 400),
(2, 900),
(3, 1400),
(4, 2100),
(5, 2800),
(6, 3600),
(7, 4500),
(8, 5400),
(9, 6500),
(10, 6080),
(11, 6960),
(12, 7840),
(13, 8800),
(14, 9840),
(15, 10800),
(16, 12000),
(17, 13120),
(18, 14240),
(19, 15400),
(20, 16640),
(21, 17920),
(22, 19200),
(23, 20400),
(24, 21760),
(25, 23120),
(26, 24400),
(27, 25760),
(28, 21120),
(29, 29040),
(30, 31040),
(31, 33280),
(32, 35680),
(33, 38400),
(34, 41200),
(35, 44000),
(36, 46960),
(37, 49920),
(38, 52960),
(39, 56160),
(40, 74300),
(41, 78500),
(42, 82800),
(43, 87100),
(44, 91600),
(45, 96300),
(46, 101000),
(47, 105800),
(48, 110700),
(49, 115700),
(50, 120900),
(51, 126100),
(52, 131500),
(53, 137000),
(54, 142500),
(55, 148200),
(56, 154000),
(57, 159900),
(58, 165800),
(59, 172000),
(60, 290000),
(61, 317000),
(62, 349000),
(63, 386000),
(64, 428000),
(65, 475000),
(66, 527000),
(67, 585000),
(68, 648000),
(69, 717000),
(70, 812700),
(71, 821000),
(72, 830000),
(73, 838000),
(74, 847000),
(75, 855000),
(76, 865000),
(77, 873000),
(78, 882000),
(79, 891000),
(80, 1686300),
(81, 2121500),
(82, 2642640),
(83, 3434200),
(84, 4582500),
(85, 8670000),
(86, 10050000),
(87, 12650000),
(88, 15250000),
(89, 18370000);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
