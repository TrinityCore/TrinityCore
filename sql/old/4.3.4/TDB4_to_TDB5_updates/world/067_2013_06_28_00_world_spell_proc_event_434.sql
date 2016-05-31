-- Shadow and Flame
DELETE FROM `spell_proc_event` WHERE `entry` IN (17793,17796,17801);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(17793, 0, 5, 0x1, 0x40, 0, 0, 0, 0, 0, 0),
(17796, 0, 5, 0x1, 0x40, 0, 0, 0, 0, 0, 0),
(17801, 0, 5, 0x1, 0x40, 0, 0, 0, 0, 0, 0);
