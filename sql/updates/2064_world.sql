DELETE FROM `trinity_string` WHERE `entry` IN (7523,7524);
INSERT INTO `trinity_string` VALUES
(7523,'WORLD: Denying connections.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(7524,'WORLD: Accepting connections.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `command` WHERE `name` IN ('server set closed');
INSERT INTO `command` VALUES ('server set closed', 3, 'Syntax: server set closed on/off\r\n\r\nSets whether the world accepts new client connectsions.');