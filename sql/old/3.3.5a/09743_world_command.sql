DELETE FROM `command` WHERE `name` IN ('reload lfg_dungeon_encounters','reload lfg_dungeon_rewards');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload lfg_dungeon_encounters',3,'Syntax: .reload lfg_dungeon_encounters\nReload lfg_dungeon_encounters table.'),
('reload lfg_dungeon_rewards',3,'Syntax: .reload lfg_dungeon_rewards\nReload lfg_dungeon_rewards table.');
