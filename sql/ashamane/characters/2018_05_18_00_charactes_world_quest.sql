DROP TABLE IF EXISTS `world_quest`;
CREATE TABLE `world_quest` (
  `id` INT (10) UNSIGNED NOT NULL,
  `rewardid` INT(10) UNSIGNED NOT NULL,
  `starttime` INT (10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`)
);

DELETE FROM updates WHERE name IN ( "2017_05_20_char_world_quest.sql",
                                    "2018_01_05_01_characters_world_quest.sql",
                                    "2018_01_14_01_charactes_world_quest.sql",
                                    "2017_05_20_char_world_quest2018_05_8_00_charactes_world_questsql");
