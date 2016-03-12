--
DELETE FROM `spell_proc_event` WHERE `entry` IN (71174,71198);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(71174, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0),
(71198, 4, 11, 0, 0, 0, 0, 0, 0, 0, 0);
