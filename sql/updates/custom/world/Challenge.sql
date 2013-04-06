-- World db
DELETE FROM `gameobject_template` WHERE `entry` = 42000;
INSERT INTO `gameobject_template`(`entry`, `type`, `displayId`, `name`, `IconName`, `size`, `ScriptName`, `WDBVerified`) VALUES(42000, 10, 327, 'Faster Start', 'PVP' , 1, 'FastArenaCrystal', 12340);
 
DELETE FROM `command` WHERE `name` = 'challenge';
INSERT INTO `command` VALUES ('challenge', '0', 'Syntax: .challenge [$name]\nInvite you and your target to 1x1 arena.');
DELETE FROM `command` WHERE `name` = 'challenge players';
INSERT INTO `command` VALUES ('challenge players', '1', 'Syntax: .challenge players $name1 $name2\nInvite two players to 1x1 arena.');