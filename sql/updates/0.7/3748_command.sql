-- Enhanced .gocreature command
DELETE FROM `command` WHERE `name` = 'gocreature';
INSERT INTO `command` VALUES('gocreature',2,'Syntax: .gocreature #creature_guid\r\nTeleport your character to creature with guid #creature_guid.\r\n.gocreature #creature_name\r\nTeleport your character to creature with this name.\r\n.gocreature id #creature_id\r\nTeleport your character to a creature that was spawned from the template with this entry.\r\n*If* more than one creature is found, then you are teleported to the first that is found inside the database.');
