DELETE FROM `command` WHERE name in ('banaccount', 'banip', 'unbanaccount', 'unbanip');

INSERT INTO `command` VALUES ('ban','3','Syntax is: ban <account|ip|character> $NameOrIp $bantime $reason\r\nBan account or IP and kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like "4d20h3s".');
INSERT INTO `command` VALUES ('unban','3','Syntax is: unban <account|ip|character> $NameOrIp\r\nUnban account or IP.');
INSERT INTO `command` VALUES ('baninfo','3','Syntax is: baninfo <account|ip|character>\r\nWatch full information about a specific ban.');
INSERT INTO `command` VALUES ('banlist','3','Syntax is: banlist <account|ip|character> $NameOrIp\r\nsearches the banlist for a pattern.');