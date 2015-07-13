DELETE FROM `command` WHERE `name`='reload locales_quest';

DELETE FROM `command` WHERE `name`='reload quest_locale';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_locale', 667, 'Syntax: .reload quest_locale\nReload all quest_*_locale tables.');
