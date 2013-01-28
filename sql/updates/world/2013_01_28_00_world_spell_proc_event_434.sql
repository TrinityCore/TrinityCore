-- Daybreak proc
DELETE FROM `spell_proc_event` WHERE `entry` IN (88820,88821);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(88820, 0, 10, 3221225472, 0, 1024, 0, 0, 0, 0, 0),
(88821, 0, 10, 3221225472, 0, 1024, 0, 0, 0, 0, 0);
