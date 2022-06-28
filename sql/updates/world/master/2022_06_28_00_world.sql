-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Versión del servidor:         5.7.38-log - MySQL Community Server (GPL)
-- SO del servidor:              Win64
-- HeidiSQL Versión:             12.0.0.6468
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

DROP TABLE IF EXISTS `creature_template_personal`;
CREATE TABLE IF NOT EXISTS `creature_template_personal` (
  `Entry` int unsigned NOT NULL DEFAULT '0' COMMENT 'This is the Entry of the generic creature that will be kept for everyone else but the summoner on UpdateObject packet.',
  `EntryForSummoner` int unsigned NOT NULL DEFAULT '0' COMMENT 'This is the EntryID of the creature that will be switched for the summoner of the spell on UpdateObject packet.',
  `GroundMountDisplayID` int unsigned NOT NULL DEFAULT '0',
  `FlightMountDisplayID` int unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Entry`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DELETE FROM `creature_template_personal`;
INSERT INTO `creature_template_personal` (`Entry`, `EntryForSummoner`, `GroundMountDisplayID`, `FlightMountDisplayID`) VALUES
	(90382, 90240, 54563, 46930),
	(91911, 91913, 59339, 0);

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
