DELETE FROM `spell_proc_event` WHERE `entry` IN (51483, 51485, 51486);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(51483, 0x00000001, 11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001, 0.000000, 0.000000,  0),
(51485, 0x00000001, 11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001, 0.000000, 0.000000,  0),
(51486, 0x00000001, 11, 0x20000000, 0x00000000, 0x00000000, 0x00004000, 0x00000001, 0.000000, 0.000000,  0);
