-- Add missing generic spell for opening chests for most of Blood Elf's classes
-- (was preventing them to loot Eye of Eternity Alexstrasza's Gift Box, Heart of Magic and maybe more.)
DELETE FROM `playercreateinfo_spell` WHERE `race`=10 AND `Spell`=61437;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(10,2,61437, 'Opening'),
(10,3,61437, 'Opening'),
(10,4,61437, 'Opening'),
(10,5,61437, 'Opening'),
(10,6,61437, 'Opening'),
(10,8,61437, 'Opening'),
(10,9,61437, 'Opening');
