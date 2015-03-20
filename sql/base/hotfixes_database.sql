-- MySQL dump 10.13  Distrib 5.6.9-rc, for Win64 (x86_64)
--
-- Host: localhost    Database: hotfixes
-- ------------------------------------------------------
-- Server version	5.6.9-rc

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dump completed on 2014-10-19 23:50:46

-- Workaround for the update system
-- As long as no full hotfix db exists

-- Updates base tables
DROP TABLE IF EXISTS `updates`;
CREATE TABLE `updates` (
    `name` VARCHAR(200) NOT NULL COMMENT 'filename with extension of the update.',
    `hash` CHAR(40) NULL DEFAULT '' COMMENT 'sha1 hash of the sql file.',
    `state` ENUM('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
    `timestamp` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
    `speed` INT(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'time the query takes to apply in ms.',
    PRIMARY KEY (`name`)
)
COMMENT='List of all applied updates in this database.'
COLLATE='utf8_general_ci'
ENGINE=MyISAM;

DROP TABLE IF EXISTS `updates_include`;
CREATE TABLE `updates_include` (
    `path` VARCHAR(200) NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
    `state` ENUM('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
    PRIMARY KEY (`path`)
)
COMMENT='List of directories where we want to include sql updates.'
COLLATE='utf8_general_ci'
ENGINE=MyISAM;

-- Hotfixes database update data
TRUNCATE TABLE `updates_include`;
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/updates/hotfixes', 'RELEASED'),
('$/sql/custom/hotfixes', 'RELEASED'),
('$/sql/old/6.x/hotfixes', 'ARCHIVED');

INSERT IGNORE INTO `updates` (`name`, `hash`) VALUES
('2015_03_20_00_hotfixes.sql', 'B761760804EA73BD297F296C5C1919687DF7191C'),
('2015_03_20_01_hotfixes.sql', 'A79521F16AE82F0D7487495D0BF7A726D81F250D');
