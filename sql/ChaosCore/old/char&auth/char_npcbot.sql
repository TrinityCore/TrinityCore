# --------------------------------------------------------
# Host:                         127.0.0.1
# Server version:               5.5.9
# Server OS:                    Win64
# HeidiSQL version:             6.0.0.3603
# Date/time:                    2011-05-27 11:31:17
# --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

# Dumping structure for table characters.character_npcbot
DROP TABLE IF EXISTS `character_npcbot`;
CREATE TABLE IF NOT EXISTS `character_npcbot` (
  `owner` int(11) DEFAULT NULL,
  `entry` int(11) DEFAULT NULL,
  `race` tinyint(4) DEFAULT NULL,
  `class` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

# Dumping data for table characters.character_npcbot: ~0 rows (approximately)
DELETE FROM `character_npcbot`;
/*!40000 ALTER TABLE `character_npcbot` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_npcbot` ENABLE KEYS */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
