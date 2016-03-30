DELETE FROM `trinity_string` WHERE `entry` IN (13000, 13001);
INSERT INTO `trinity_string` VALUES ('13000', 'Guild Level: %u.', null, null, null, null, null, null, null, null);
INSERT INTO `trinity_string` VALUES ('13001', 'Guild Experience: %u/%u.', null, null, null, null, null, null, null, null);
DELETE FROM `command` WHERE `permission` IN (1000, 1001, 1002);
INSERT INTO `command` VALUES ('guild linfo', '1000', 'Syntax: .guild linfo');
INSERT INTO `command` VALUES ('guild setlevel', '1001', 'Syntax: .guild setlevel $GuildName $Level');
INSERT INTO `command` VALUES ('guild givexp', '1002', 'Syntax: .guild givexp $GuildName $Xp');