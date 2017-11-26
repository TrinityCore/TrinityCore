/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

DROP TABLE IF EXISTS `creature_template_resistance`;
CREATE TABLE IF NOT EXISTS `creature_template_resistance` (
  `CreatureID` mediumint(8) unsigned NOT NULL,
  `Resistance1` smallint(6) DEFAULT NULL,
  `Resistance2` smallint(6) DEFAULT NULL,
  `Resistance3` smallint(6) DEFAULT NULL,
  `Resistance4` smallint(6) DEFAULT NULL,
  `Resistance5` smallint(6) DEFAULT NULL,
  `Resistance6` smallint(6) DEFAULT NULL,
  `VerifiedBuild` smallint(5) DEFAULT '0',
  PRIMARY KEY (`CreatureID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `creature_template_spell`;
CREATE TABLE IF NOT EXISTS `creature_template_spell` (
  `CreatureID` mediumint(8) unsigned NOT NULL,
  `Spell1` mediumint(8) unsigned DEFAULT NULL,
  `Spell2` mediumint(8) unsigned DEFAULT NULL,
  `Spell3` mediumint(8) unsigned DEFAULT NULL,
  `Spell4` mediumint(8) unsigned DEFAULT NULL,
  `Spell5` mediumint(8) unsigned DEFAULT NULL,
  `Spell6` mediumint(8) unsigned DEFAULT NULL,
  `Spell7` mediumint(8) unsigned DEFAULT NULL,
  `Spell8` mediumint(8) unsigned DEFAULT NULL,
  `VerifiedBuild` smallint(5) DEFAULT '0',
  PRIMARY KEY (`CreatureID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;

INSERT INTO creature_template_resistance SELECT entry, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, VerifiedBuild FROM creature_template
WHERE resistance1 <> 0 OR resistance2 <> 0 OR resistance3 <> 0 OR resistance4 <> 0 OR resistance5 <> 0 OR resistance5 <> 0 OR resistance6 <> 0;

INSERT INTO creature_template_spell SELECT entry, spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8, VerifiedBuild FROM creature_template
WHERE spell1 <> 0 OR spell2 <> 0 OR spell3 <> 0 OR spell4 <> 0 OR spell5 <> 0 OR spell5 <> 0 OR spell6 <> 0 OR spell7 <> 0 OR spell8 <> 0;

ALTER TABLE `creature_template`
	DROP COLUMN `resistance1`,
	DROP COLUMN `resistance2`,
	DROP COLUMN `resistance3`,
	DROP COLUMN `resistance4`,
	DROP COLUMN `resistance5`,
	DROP COLUMN `resistance6`,
	DROP COLUMN `spell1`,
	DROP COLUMN `spell2`,
	DROP COLUMN `spell3`,
	DROP COLUMN `spell4`,
	DROP COLUMN `spell5`,
	DROP COLUMN `spell6`,
	DROP COLUMN `spell7`,
	DROP COLUMN `spell8`;
