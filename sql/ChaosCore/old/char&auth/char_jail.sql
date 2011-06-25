# --------------------------------------------------------
# Host:                         127.0.0.1
# Server version:               5.5.9
# Server OS:                    Win64
# HeidiSQL version:             6.0.0.3603
# Date/time:                    2011-05-26 23:49:51
# --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

# Dumping structure for table characters.jail
DROP TABLE IF EXISTS `jail`;
CREATE TABLE IF NOT EXISTS `jail` (
  `guid` int(11) unsigned NOT NULL COMMENT 'GUID of the jail brother',
  `char` varchar(13) NOT NULL COMMENT 'Jailed charname',
  `release` int(11) unsigned NOT NULL COMMENT 'Release time for the char',
  `amnestietime` int(11) NOT NULL,
  `reason` varchar(255) NOT NULL COMMENT 'Reason for the jail',
  `times` int(11) unsigned NOT NULL COMMENT 'How many times this char already was jailed',
  `gmacc` int(11) unsigned NOT NULL COMMENT 'Used GM acc to jail this char',
  `gmchar` varchar(13) NOT NULL COMMENT 'Used GM char to jail this char',
  `lasttime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00' ON UPDATE CURRENT_TIMESTAMP COMMENT 'Last time jailed',
  `duration` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Duration of the jail',
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Jail table for Trinitycore by WarHead Edited by SPGM';

# Dumping data for table characters.jail: 0 rows
DELETE FROM `jail`;
/*!40000 ALTER TABLE `jail` DISABLE KEYS */;
/*!40000 ALTER TABLE `jail` ENABLE KEYS */;


# Dumping structure for table characters.jail_conf
DROP TABLE IF EXISTS `jail_conf`;
CREATE TABLE IF NOT EXISTS `jail_conf` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `obt` varchar(50) DEFAULT NULL,
  `jail_conf` int(11) DEFAULT NULL,
  `jail_tele` float DEFAULT NULL,
  `help_ger` varchar(255) CHARACTER SET latin1 DEFAULT '',
  `help_enq` varchar(255) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;

# Dumping data for table characters.jail_conf: 17 rows
DELETE FROM `jail_conf`;
/*!40000 ALTER TABLE `jail_conf` DISABLE KEYS */;
INSERT INTO `jail_conf` (`id`, `obt`, `jail_conf`, `jail_tele`, `help_ger`, `help_enq`) VALUES
	(1, 'm_jailconf_max_jails', 3, NULL, 'Hier legst ihre fest nach wie fielen Jails der Char gelöscht werden \r\nStandart = 3\r\n ', 'How many time the characters can be Jailed before being deleted\r\nDefault = 3'),
	(2, 'm_jailconf_max_duration', 672, NULL, 'Hier legst ihre fest wie hoch der maximale Jail Time in Stunden \r\nStandart = 672\r\n', 'Here put how high the maximum Jail Time in hours\r\nDefault = 672'),
	(3, 'm_jailconf_min_reason', 25, NULL, 'Hier legst ihre die minimalen Zeichen fest die als Grund angeben müsst  \r\nStandart = 25\r\n\r\n', 'Here list how many characters are needed as the minimum reason\r\nDefault = 25'),
	(4, 'm_jailconf_warn_player', 1, NULL, 'Hier legst ihre fest wann der Char gewarnt wirt  bevor er gelöscht wird \r\nStandart = 1\r\n', 'How many time to warn the player before jailing them\r\nDefault = 1'),
	(5, 'm_jailconf_amnestie', 180, NULL, '', 'This is how many in days when the Jail is status is set to 0\r\nStandard = 180 days (approximately ˝ year)\r\n                     0 days (off)'),
	(6, 'm_jailconf_ally_x', NULL, 31.7282, 'Teleport Alliance  X Achse \r\nStandart = 31,7282\r\n', 'Teleport Alliance  X Axis \r\nStandart = 31,7282\r\n'),
	(7, 'm_jailconf_ally_y', NULL, 135.794, 'Teleport Alliance  Y Achse \r\nStandart = 135,794\r\n', 'Teleport Alliance  Y Axis \r\nStandart = 135,794\r\n'),
	(8, 'm_jailconf_ally_z', NULL, -40.0508, 'Teleport Alliance  Z Achse \r\nStandart = -40,0508', 'Teleport Alliance  Z Axis \r\nStandart = -40,0508'),
	(9, 'm_jailconf_ally_o', NULL, 4.73516, 'Teleport Alliance  blickrichtung\r\nStandart = 4,73516', 'Teleport Alliance  Orientation\r\nStandart = 4,73516'),
	(10, 'm_jailconf_ally_m', 35, NULL, 'Teleport Alliance  Mape\r\nStandart = 35', 'Teleport Alliance  Map\r\nStandart = 35'),
	(11, 'm_jailconf_horde_x', NULL, 2179.85, 'Teleport Horde  X Achse \r\nStandart = \r\n', 'Teleport Horde  X Axis \r\nStandart = \r\n'),
	(12, 'm_jailconf_horde_y', NULL, -4763.96, 'Teleport Horde  Y Achse \r\nStandart = -4763,96', 'Teleport Horde  Y Axis \r\nStandart = -4763,96'),
	(13, 'm_jailconf_horde_z', NULL, 54.911, 'Teleport Horde  Z Achse \r\nStandart = 54,911', 'Teleport Horde  Z Axis \r\nStandart = 54,911'),
	(14, 'm_jailconf_horde_o', NULL, 4.44216, 'Teleport  Horde  blickrichtung\r\nStandart = 4,44216', 'Teleport  Horde  Orientation\r\nStandart = 4,44216'),
	(15, 'm_jailconf_horde_m', 1, NULL, 'Teleport Horde  Mape\r\nStandart = 1', 'eleport Horde  Map\r\nStandart = 1'),
	(16, 'm_jailconf_ban', 0, NULL, 'Nach wie vielen Jail soll der  Account Gebant werden\r\nStandart = 0  (aus)\r\n', 'After how many jails the account will be Banned\r\nDefault = 0 (off)'),
	(17, 'm_jailconf_radius', 10, NULL, 'Legt den Bewegung Radius in Metern waren des Jails fest\r\nStandart = 10\r\n', 'Sets the range of motion in meters of the jail\r\nDefault = 10');
/*!40000 ALTER TABLE `jail_conf` ENABLE KEYS */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
