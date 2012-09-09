DELETE FROM `command` WHERE `name` = 'start';
DELETE FROM `command` WHERE `name` = 'unstuck';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('unstuck', 0, 'Syntax: .unstuck $playername [inn/graveyard/startzone]\n\nTeleports specified player to specified location. Default location is player\'s current hearth location.');
