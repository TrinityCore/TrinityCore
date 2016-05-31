DELETE FROM `command` WHERE `name` LIKE '%go quest%';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('go quest', 12, 'Syntax: .go quest #quest_id\r\n\r\nTeleport your character to first quest poi with id #quest_id.');
