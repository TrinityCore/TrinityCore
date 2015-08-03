-- Taste for Blood, Overpower Ready!, Sudden Death and Fingers of Frost proc data.
DELETE FROM `spell_proc_event` WHERE `entry` IN (60503, 68051, 52437, 74396);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(60503, 0x01, 4, 0x00000004, 0x00000000, 0x00000000, 0x00000010, 0x00000000, 0, 0, 0),
(68051, 0x01, 4, 0x00000004, 0x00000000, 0x00000000, 0x00000010, 0x00000000, 0, 0, 0),
(52437, 0x01, 4, 0x20000000, 0x00000000, 0x00000000, 0x00000010, 0x00000000, 0, 0, 0),
(74396, 0x10, 3, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000003, 0, 0, 0);
