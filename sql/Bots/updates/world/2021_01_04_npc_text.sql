--
SET @LOCALIZED_STRINGS_START = 70621;
SET @LOCALIZED_STRINGS_END   = 70633;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70621','Male','-1'),
('70622','Female','-1'),
('70623','Human','-1'),
('70624','Orc','-1'),
('70625','Dwarf','-1'),
('70626','Night Elf','-1'),
('70627','Undead','-1'),
('70628','Tauren','-1'),
('70629','Gnome','-1'),
('70630','Troll','-1'),
('70631','Blood Elf','-1'),
('70632','Draenei','-1'),
('70633','Unknown','-1');
