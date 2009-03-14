-- Nature's Grace --
DELETE FROM `spell_proc_event` WHERE `entry` IN (16880, 61345, 61346);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(16880, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0),
(61345, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0),
(61346, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);
