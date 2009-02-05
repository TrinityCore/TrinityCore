DELETE FROM `spell_proc_event` WHERE `entry` IN ('38164','14144','14148');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('38164','0','0','0','0','1','0','0','60'),
('14144','0','0','0','2','0','0','0','0'),
('14148','0','0','0','2','0','0','0','0');