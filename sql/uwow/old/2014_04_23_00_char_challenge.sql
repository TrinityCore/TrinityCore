-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: localhost
-- Время создания: Апр 23 2014 г., 08:25
-- Версия сервера: 5.0.67-community-nt
-- Версия PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `mop_char`
--

-- --------------------------------------------------------

--
-- Структура таблицы `challenge`
--

DROP TABLE IF EXISTS `challenge`;
CREATE TABLE `challenge` (
  `id` int(11) NOT NULL,
  `mapID` mediumint(9) NOT NULL default '0',
  `recordTime` int(11) NOT NULL default '0',
  `date` int(11) NOT NULL default '0',
  `medal` smallint(6) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `mapID` (`mapID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `challenge_member`
--

DROP TABLE IF EXISTS `challenge_member`;
CREATE TABLE `challenge_member` (
  `id` int(11) NOT NULL,
  `member` int(11) NOT NULL default '0',
  `specID` mediumint(6) NOT NULL default '0',
  KEY `id` (`id`,`member`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
