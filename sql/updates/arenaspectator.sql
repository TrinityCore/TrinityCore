-- Implement Arena Spectator
DELETE FROM `command` WHERE `name` = 'spectate';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('spectate', 778, 'Syntax: .spectate $subcommand.\nUse .help sppectate');
DELETE FROM `command` WHERE `name` = 'spectate view';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('spectate view', 779, 'Syntax: .spectate view #player\nAllow player to spectate arena from anotherplayer.');
DELETE FROM `command` WHERE `name` = 'spectate leave';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('spectate leave', 780, 'Syntax: .spectate leave\nDisable spectator mode.');
DELETE FROM `command` WHERE `name` = 'spectate player';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('spectate player', 781, 'Syntax: .spectate player #player\nAllow to spectate player.');
DELETE FROM `command` WHERE `name` = 'spectate reset';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('spectate reset', 782, 'Syntax: .spectate reset\nSend addon data.');
UPDATE `gameobject_template` SET `flags` = 36 WHERE entry IN (185918, 185917, 183970, 183971, 183972, 183973, 183977, 183979, 183978, 183980, 192642, 192643);