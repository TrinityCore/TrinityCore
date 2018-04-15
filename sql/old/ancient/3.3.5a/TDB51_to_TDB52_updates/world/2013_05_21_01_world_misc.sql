DELETE FROM `command` WHERE `name` LIKE 'arena%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('arena create', 3, 'Syntax: .arena create $name \"arena name\" #type\n\nA command to create a new Arena-team in game. #type  = [2/3/5]'),
('arena disband', 3, 'Syntax: .arena disband #TeamID\n\nA command to disband Arena-team in game.'),
('arena rename', 3, 'Syntax: .arena rename \"oldname\" \"newname\"\n\nA command to rename Arena-team name.'),
('arena captain', 3, 'Syntax: .arena captain #TeamID $name\n\nA command to set new captain to the team $name must be in the team'),
('arena info', 2, 'Syntax: .arena info #TeamID\n\nA command that show info about arena team'),
('arena lookup', 2, 'Syntax: .arena lookup $name\n\nA command that give a list of arenateam with the given $name');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 857 AND 870;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(857, 'Arena team [%u] not found'),
(858, 'There is already an arena team named \"%s\"'),
(859, '%s is already in an arena team of that size'),
(860, 'Arena Team In Combat'),
(861, 'Arena with name: \"%s\" or silmilar not found'),
(862, '[%s] not member of the team \"%s\"'),
(863, '[%s] already capitan in the team \"%s\"'),
(864, 'New ArenaTeam created [Name: \"%s\"][Id: %u][Type: %u][Captain GUID: %u]'),
(865, 'Arena team Name: \"%s\"[Id: %u] disbanded'),
(866, 'Arena team [Id: %u] change from \"%s\" to \"%s\"'),
(867, 'Arena team Name: \"%s\"[Id: %u] change capitan from[%s] to [%s]'),
(868, 'Arena team: \"%s\"[%u] - Rating: %u - Type: %ux%u'),
(869, 'Name:\"%s\"[guid:%u] - PR: %u - %s'),
(870, '|\"%s\"[ID:%u](%ux%u)|');
