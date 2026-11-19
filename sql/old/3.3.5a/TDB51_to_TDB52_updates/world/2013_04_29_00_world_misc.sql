DELETE FROM `command` WHERE `name` = 'character rename';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('character rename', 2, 'Syntax: .character rename [$name] [$newName] \n\nMark selected in game or by $name in command character for rename at next login.\n\nIf $newName then the player will be forced rename.');

SET @ENTRY  := 98;
SET @ENTRY1 := 167;
DELETE FROM `trinity_string` WHERE `entry` IN (@ENTRY, @ENTRY+1, @ENTRY1);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@ENTRY,   '\'%s\' already exists as character name, choose another one'),
(@ENTRY+1, 'Player \'%s\' forced rename to \'%s\''),
(@ENTRY1,  'This name is reserved, choose another one');
