DELETE FROM `spell_proc_event` WHERE `entry` IN ('14144','14148');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('14144','0','0','0','2','0','0','0','0'),
('14148','0','0','0','2','0','0','0','0');
DELETE FROM `spell_proc_event` WHERE entry = 38164;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
 (38164,0,0,0,0,1,0,0,60);

