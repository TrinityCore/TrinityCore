/*
UPDATE `command` SET `security`=5 WHERE `name` like 'modify%';
UPDATE `command` SET `security`=5 WHERE `name` like 'debug%';
UPDATE `command` SET `security`=5 WHERE `name` like 'character%';
UPDATE `command` SET `security`=5 WHERE `name` like 'npc%';
UPDATE `command` SET `security`=5 WHERE `name` like 'wp%';
UPDATE `command` SET `security`=5 WHERE `name` like 'honor%';
UPDATE `command` SET `security`=5 WHERE `name` like 'gobject%';
UPDATE `command` SET `security`=5 WHERE `name` like 'titles%';
UPDATE `command` SET `security`=5 WHERE `name` like 'add%';
UPDATE `command` SET `security`=5 WHERE `name` like 'reload%';
UPDATE `command` SET `security`=5 WHERE `name` like 'instance%';
UPDATE `command` SET `security`=5 WHERE `name` like 'lookup%';
UPDATE `command` SET `security`=5 WHERE `name` like 'quest%';
UPDATE `command` SET `security`=5 WHERE `name` like 'learn%';
*/
REPLACE INTO `command` (`name`, `security`, `help`) VALUES
('gogroup', 1, 'Syntax: .gogroup [$charactername]\r\n\r\nTeleport the given character and his group to you. Teleported only online characters but original selected group member can be offline.'),
('goname', 1, 'Syntax: .goname [$charactername]\r\n\r\nTeleport to the given character. Either specify the character name or click on the character''s portrait, e.g. when you are in a group. Character can be offline.'),
('namego', 1, 'Syntax: .namego [$charactername]\r\n\r\nTeleport the given character to you. Character can be offline.');
