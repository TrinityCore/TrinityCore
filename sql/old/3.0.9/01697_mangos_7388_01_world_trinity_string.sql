/*ALTER TABLE db_version CHANGE COLUMN required_7382_01_mangos_creature_template required_7388_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (750,751);
INSERT INTO `trinity_string` VALUES
(750,'Not enough players. This game will close in %u mins.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(751,'Not enough players. This game will close in %u seconds.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
