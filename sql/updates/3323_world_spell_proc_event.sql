-- Glyph of Ice Block --
DELETE FROM `spell_proc_event` WHERE `entry` = 56372;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56372, 0x00, 3, 0x00000000, 0x00000080, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);