INSERT INTO `command` VALUES('idleshutdown','3','Syntax: .idleshutdown #delay\r\n\r\nShutting down server after #delay seconds if no active connections present (no players).');
INSERT INTO `command` VALUES('banaccount','3','Syntax: .banaccount $name\r\n\r\nBan account $name (can be view for player using .pinfo command) and kick affected player if he loginned at server.');
INSERT INTO `command` VALUES('banip','3','Syntax: .banip #ip\r\n\r\nBan loggining to server from computer with provide IP address and kick all affected players with equal last IP.');
INSERT INTO `command` VALUES('unbanaccount','3','Syntax: .unbanaccount $name\r\n\r\nUnban account $name.');
INSERT INTO `command` VALUES('unbanip','3','Syntax: .unbanip #ip\r\n\r\nUnban provide IP address.');
UPDATE `command` SET `help` = 'Syntax: .kick [$charactername]\r\n\r\nKick the given character from the world. If no character name provide then selected player (except self) will be kicked.' WHERE `name` = 'kick';
