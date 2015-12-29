# ************************************************************
# Sequel Pro SQL dump
# Version 4499
#
# http://www.sequelpro.com/
# https://github.com/sequelpro/sequelpro
#
# Host: localhost (MySQL 5.7.10)
# Datenbank: hotfixes
# Erstellt am: 2015-12-29 16:47:35 +0000
# ************************************************************


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


# Export von Tabelle BattlePetEffectProperties
# ------------------------------------------------------------

DROP TABLE IF EXISTS `BattlePetEffectProperties`;

CREATE TABLE `BattlePetEffectProperties` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `unk_4` int(11) DEFAULT NULL,
  `name0` text,
  `name1` text,
  `name2` text,
  `name3` text,
  `name4` text,
  `name5` text,
  `value0` int(11) DEFAULT NULL,
  `value1` int(11) DEFAULT NULL,
  `value2` int(11) DEFAULT NULL,
  `value3` int(11) DEFAULT NULL,
  `value4` int(11) DEFAULT NULL,
  `value5` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Export von Tabelle BattlePetEffectProperties_locale
# ------------------------------------------------------------

DROP TABLE IF EXISTS `BattlePetEffectProperties_locale`;

CREATE TABLE `BattlePetEffectProperties_locale` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `locale` int(11) DEFAULT NULL,
  `name0` text,
  `name1` text,
  `name2` text,
  `name3` text,
  `name4` text,
  `name5` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;




/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
