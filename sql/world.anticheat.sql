DELETE FROM `trinity_string`  WHERE `entry` IN (30087,30088,30089,30090,30091,30092);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(30087, '|cffffff00[|cffff0000ANTICHEAT ALERT|r|cffffff00]:|r |cFFFF8C00|r |cFFFF8C00[|Hplayer:%s|h%s|h|r|cFFFF8C00] - Latency: %u ms', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30088, '|cffffff00[|cffff0000ANTICHEAT ALERT|r|cffffff00]:|r POSSIBLE TELEPORT HACK DETECTED|cFFFF8C00 %s|r - Latency: %u ms', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30089, '|cffffff00[|cffff0000ANTICHEAT ALERT|r|cffffff00]:|r POSSIBLE IGNORE CONTROL HACK DETECTED|cFFFF8C00] %s|r - Latency: %u ms', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30090, '|cffffff00[|cffff0000ANTICHEAT ALERT|r|cffffff00]:|r TELEPORT HACK USED WHLE DUELING|cFFFF8C00 %s|r - Latency: %u ms vs |cFFFF8C00 %s|r - Latency: %u ms.', NULL, NULL, NULL, NULL, NULL, '', '', NULL),
(30091, '|cffffff00[|cffff0000ANTICHEAT ALERT|r|cffffff00]:|r BG Start Bound Teleport\\Exploit Hack DETECTED|cFFFF8C00[|Hplayer:%s|h%s|h|r|cFFFF8C00] - Latency: %u ms', NULL, NULL, NULL, NULL, NULL, '', '', NULL),
(30092, '|cffffff00[|cffff0000COUNTER MEASURE ALERT|r|cffffff00]:|r |cFFFF8C00|r %s |cFFFF8C00[|Hplayer:%s|h%s|h|r|cFFFF8C00]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE  `name`='anticheat jail';
DELETE FROM `command` WHERE  `name`='anticheat delete';
DELETE FROM `command` WHERE  `name`='anticheat player';
DELETE FROM `command` WHERE  `name`='anticheat';
DELETE FROM `command` WHERE  `name`='anticheat global';
DELETE FROM `command` WHERE  `name`='anticheat parole';
DELETE FROM `command` WHERE  `name`='anticheat purge';
DELETE FROM `command` WHERE  `name`='anticheat warn';
DELETE FROM `command` WHERE  `name`='anticheat handle';
INSERT INTO `command` (`name`, `help`) VALUES
('anticheat', 'Syntax: .anticheat\r\n\r\nDisplay the access level of anticheat commands if you possess the necessary permissions.'),
('anticheat global', 'Syntax: .anticheat global\r\n\r\nDisplay if anticheat is active with global statistics.'),
('anticheat player', 'Syntax: .anticheat player [$charactername]\r\n\r\nDisplay anticheat statistics of current session of player.'),
('anticheat delete', 'Syntax: .anticheat delete [$charactername]\r\n\r\nDeletes anticheat statistics of current session of player.'),
('anticheat jail', 'Syntax: .anticheat jail [$charactername]\r\n\r\nJails and restricts player and teleports GM cmd user to jail with no restrictions'),
('anticheat parole', 'Syntax: .anticheat parole [$charactername]\r\n\r\nDeletes anticheat statistics, removes jail restrictions, and sends to faction capital of player.'),
('anticheat purge', 'Syntax: .anticheat purge\r\n\r\nDeletes stored statistics of daily_players_reports table.'),
('anticheat warn', 'Syntax: .anticheat warn [$charactername]\r\n\r\nSends individual player they are being monitored for possible cheating.'),
('anticheat handle', 'Syntax: .anticheat handle 0 or 1\r\n\r\n0 Turns off and 1 Turns On Anticheat');

DROP TABLE IF EXISTS `lua_private_functions`;
CREATE TABLE IF NOT EXISTS `lua_private_functions` (
  `function_name` varchar(255) NOT NULL DEFAULT '0',
  `enabled` tinyint NOT NULL DEFAULT '1',
  PRIMARY KEY (`function_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `lua_private_functions` VALUES ('CastSpellByName', '1');
INSERT INTO `lua_private_functions` VALUES ('RunMacroText', '1');
