/*
DELETE FROM `spell_proc_event` WHERE `entry` IN (44401, 48108, 57761);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(44401, 0, 3, 0x00000800, 0x00000000, 0x00000000,  4096, 0, 0, 0, 0),
(48108, 0, 3, 0x00400000, 0x00000000, 0x00000000, 65536, 0, 0, 0, 0),
(57761, 0, 3, 0x00000001, 0x00001000, 0x00000000, 65536, 0, 0, 0, 0);
*/
