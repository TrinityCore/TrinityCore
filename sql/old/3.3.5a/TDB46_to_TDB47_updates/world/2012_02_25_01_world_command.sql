DELETE FROM `command` WHERE `name` IN ('group','group leader','group disband','group remove');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('group', 3, 'Syntax: .group $subcommand\nType .group to see the list of possible subcommands or .help group $subcommand to see info on subcommands'),
('group leader', 3, 'Syntax: .group leader [$characterName]\n\nSets the given character as his group''s leader.'),
('group disband', 3, 'Syntax: .group disband [$characterName]\n\nDisbands the given character''s group.'),
('group remove', 3, 'Syntax: .group remove [$characterName]\n\nRemoves the given character from his group.');
