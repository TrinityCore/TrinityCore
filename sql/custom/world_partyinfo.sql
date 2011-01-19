DELETE FROM `trinity_string` where `entry` = '11004';
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('11004', 'Player%s %s Account: %s (id: %u) GMLevel: %u %s');

DELETE FROM `command` where `name` = 'partyinfo';
INSERT INTO `command` VALUES ('partyinfo', '2', 'Syntax: .partyinfo [$player_name]\nOutput information for members of group that include selected player or player find by $player_name.');
