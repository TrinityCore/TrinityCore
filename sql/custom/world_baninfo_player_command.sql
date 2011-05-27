DELETE FROM `command` WHERE `name` = 'baninfo player';
INSERT INTO `command` VALUES ('baninfo player', 3, 'Syntax: .baninfo player $playerName\r\nWatch full information about a specific ban.');
