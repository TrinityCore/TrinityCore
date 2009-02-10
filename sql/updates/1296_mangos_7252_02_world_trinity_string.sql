/*ALTER TABLE db_version CHANGE COLUMN required_7252_01_mangos_command required_7252_02_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE entry IN (737,738,739,740,741,742,743,744,745,746);
INSERT INTO `trinity_string` VALUES
(737,'Arenas are set to 1v1 for debugging. So, don\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(738,'Arenas are set to normal playercount.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(739,'Battlegrounds are set to 1v0 for debugging.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(740,'Battlegrounds are set to normal playercount.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(741,'Flushing Arena points based on team ratings, this may take a few minutes. Please stand by...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(742,'Distributing arena points to players...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(743,'Finished setting arena points for online players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(744,'Modifying played count, arena points etc. for loaded arena teams, sending updated stats to online players...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(745,'Modification done.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(746,'Done flushing Arena points.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);