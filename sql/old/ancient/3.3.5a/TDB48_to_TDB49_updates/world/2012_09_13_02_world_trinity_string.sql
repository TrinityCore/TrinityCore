DELETE FROM `command` WHERE `name` = 'cheat status';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('cheat status', 2, 'Syntax: .cheat status \n\nShows the cheats you currently have enabled.');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 357 AND 362;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(357, 'Cheat Command Status:'),
(358, 'Godmode: %s.'),
(359, 'Casttime: %s.'),
(360, 'Cooldown: %s.'),
(361, 'Power: %s.'),
(362, 'Waterwalk: %s.');
