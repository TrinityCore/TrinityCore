DROP TABLE IF EXISTS `creature_template_difficulty`;
CREATE TABLE `creature_template_difficulty` (
  `CreatureId` INT(10) UNSIGNED NOT NULL,
  `DifficultyCreatureId1` INT(10) NOT NULL DEFAULT 0,
  `DifficultyCreatureId2` INT(10) NOT NULL DEFAULT 0,
  `DifficultyCreatureId3` INT(10) NOT NULL DEFAULT 0,
  PRIMARY KEY (`CreatureId`)
);

INSERT INTO `creature_template_difficulty` (`CreatureId`, `DifficultyCreatureId1`, `DifficultyCreatureId2`, `DifficultyCreatureId3`) 
SELECT `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3` FROM `creature_template`;
