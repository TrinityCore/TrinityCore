DELETE FROM `command` WHERE `name`='reload locales_npc_text';
DELETE FROM `command` WHERE `name`='reload quest_greeting';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_greeting', 664, 'Syntax: .reload quest_greeting\nReload quest_greeting table.');
