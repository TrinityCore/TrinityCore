ALTER TABLE `quest_objectives` DROP COLUMN `VisualEffect1`;
ALTER TABLE `quest_objectives` DROP COLUMN `VisualEffect2`;
ALTER TABLE `quest_objectives` DROP COLUMN `VisualEffect3`;
ALTER TABLE `quest_objectives` DROP COLUMN `VisualEffect4`;
ALTER TABLE `quest_objectives` DROP COLUMN `VisualEffect5`;

DROP TABLE IF EXISTS `quest_objectives_visual_effects`;
CREATE TABLE `quest_objectives_visual_effects` (
  `ObjectiveID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Index` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `VisualEffect` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ObjectiveID`, `Index`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
