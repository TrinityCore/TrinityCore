/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

DROP TABLE IF EXISTS `creature_template_resistance`;
CREATE TABLE IF NOT EXISTS `creature_template_resistance` (
  `CreatureID` MEDIUMINT(8) UNSIGNED NOT NULL,
  `School` TINYINT(6) UNSIGNED NOT NULL,
  `Resistance` SMALLINT(6) DEFAULT NULL,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`CreatureID`, `School`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `creature_template_spell`;
CREATE TABLE IF NOT EXISTS `creature_template_spell` (
  `CreatureID` mediumint(8) unsigned NOT NULL,
  `Index` TINYINT(6) unsigned NOT NULL DEFAULT '0',
  `Spell` mediumint(8) unsigned DEFAULT NULL,
  `VerifiedBuild` smallint(5) DEFAULT '0',
  PRIMARY KEY (`CreatureID`, `Index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;

INSERT INTO creature_template_resistance SELECT entry, 1, resistance1, VerifiedBuild FROM creature_template WHERE resistance1 <> 0;
INSERT INTO creature_template_resistance SELECT entry, 2, resistance2, VerifiedBuild FROM creature_template WHERE resistance2 <> 0;
INSERT INTO creature_template_resistance SELECT entry, 3, resistance3, VerifiedBuild FROM creature_template WHERE resistance3 <> 0;
INSERT INTO creature_template_resistance SELECT entry, 4, resistance4, VerifiedBuild FROM creature_template WHERE resistance4 <> 0;
INSERT INTO creature_template_resistance SELECT entry, 5, resistance5, VerifiedBuild FROM creature_template WHERE resistance5 <> 0;
INSERT INTO creature_template_resistance SELECT entry, 6, resistance6, VerifiedBuild FROM creature_template WHERE resistance6 <> 0;

INSERT INTO creature_template_spell SELECT entry, 0, spell1, VerifiedBuild FROM creature_template WHERE spell1 <> 0;
INSERT INTO creature_template_spell SELECT entry, 1, spell2, VerifiedBuild FROM creature_template WHERE spell2 <> 0;
INSERT INTO creature_template_spell SELECT entry, 2, spell3, VerifiedBuild FROM creature_template WHERE spell3 <> 0;
INSERT INTO creature_template_spell SELECT entry, 3, spell4, VerifiedBuild FROM creature_template WHERE spell4 <> 0;
INSERT INTO creature_template_spell SELECT entry, 4, spell5, VerifiedBuild FROM creature_template WHERE spell5 <> 0;
INSERT INTO creature_template_spell SELECT entry, 5, spell6, VerifiedBuild FROM creature_template WHERE spell6 <> 0;
INSERT INTO creature_template_spell SELECT entry, 6, spell7, VerifiedBuild FROM creature_template WHERE spell7 <> 0;
INSERT INTO creature_template_spell SELECT entry, 7, spell8, VerifiedBuild FROM creature_template WHERE spell8 <> 0;

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
