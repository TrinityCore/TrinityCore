-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Versión del servidor:         5.7.31-log - MySQL Community Server (GPL)
-- SO del servidor:              Win64
-- HeidiSQL Versión:             11.0.0.5919
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Volcando estructura para tabla hotfixesshadowlands.map_challenge_mode
DROP TABLE IF EXISTS `map_challenge_mode`;
CREATE TABLE IF NOT EXISTS `map_challenge_mode` (
  `Name` text NOT NULL,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CriteriaCount1` smallint(5) NOT NULL DEFAULT '0',
  `CriteriaCount2` smallint(5) NOT NULL DEFAULT '0',
  `CriteriaCount3` smallint(5) NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) unsigned NOT NULL DEFAULT '0',
  `ExpansionLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla hotfixesshadowlands.map_challenge_mode: ~0 rows (aproximadamente)
DELETE FROM `map_challenge_mode`;
/*!40000 ALTER TABLE `map_challenge_mode` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_challenge_mode` ENABLE KEYS */;

-- Volcando estructura para tabla hotfixesshadowlands.map_challenge_mode_locale
DROP TABLE IF EXISTS `map_challenge_mode_locale`;
CREATE TABLE IF NOT EXISTS `map_challenge_mode_locale` (
  `ID` int(10) unsigned NOT NULL,
  `locale` varchar(4) NOT NULL,
  `Name_lang` text NOT NULL,
  `VerifiedBuild` smallint(6) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla hotfixesshadowlands.map_challenge_mode_locale: ~0 rows (aproximadamente)
DELETE FROM `map_challenge_mode_locale`;
/*!40000 ALTER TABLE `map_challenge_mode_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `map_challenge_mode_locale` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
