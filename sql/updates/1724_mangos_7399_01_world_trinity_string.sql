/*ALTER TABLE db_version CHANGE COLUMN required_7393_01_mangos_game_event required_7399_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (753, 754, 755);
INSERT INTO `trinity_string` VALUES
(753,'The battle for Warsong Gulch begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(754,'The battle for Arathi Basin begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(755,'The battle for Eye of the Storm begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);