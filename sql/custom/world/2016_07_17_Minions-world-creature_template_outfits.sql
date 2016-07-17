-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 20, 2016 at 04:41 PM
-- Server version: 5.7.12-0ubuntu1
-- PHP Version: 7.0.4-7ubuntu2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `world`
--

-- --------------------------------------------------------

--
-- Table structure for table `creature_template_outfits`
--

CREATE TABLE IF NOT EXISTS `creature_template_outfits` (
  `entry` int(10) UNSIGNED NOT NULL,
  `race` tinyint(3) UNSIGNED NOT NULL DEFAULT '1',
  `gender` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT '0 for male, 1 for female',
  `skin` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `face` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `hair` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `haircolor` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `facialhair` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `head` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `shoulders` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `body` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `chest` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `waist` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `legs` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `feet` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `wrists` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `hands` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `back` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `tabard` int(10) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `creature_template_outfits`
--

REPLACE INTO `creature_template_outfits` (`entry`, `race`, `gender`, `skin`, `face`, `hair`, `haircolor`, `facialhair`, `head`, `shoulders`, `body`, `chest`, `waist`, `legs`, `feet`, `wrists`, `hands`, `back`, `tabard`) VALUES
(70301, 2, 0, 0, 14, 9, 7, 5, 0, 0, 0, 0, 59194, 64674, 0, 36248, 0, 0, 0),
(71000, 11, 1, 0, 5, 0, 6, 0, 0, 53903, 21842, 35049, 35058, 35051, 35067, 35044, 0, 0, 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `creature_template_outfits`
--
ALTER TABLE `creature_template_outfits`
  ADD PRIMARY KEY IF NOT EXISTS (`entry`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
