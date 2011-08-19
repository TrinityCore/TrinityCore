-- Nature's Grace --
DELETE FROM `spell_proc_event` WHERE `entry` IN (16880, 61345, 61346);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(16880, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0),
(61345, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0),
(61346, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- Blade Twisting --
DELETE FROM `spell_proc_event` WHERE `entry` IN (31124, 31126);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(31124, 0x00, 8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0),
(31126, 0x00, 8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
