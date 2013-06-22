DELETE FROM `spell_proc_event` WHERE `entry` IN (56333, 56336);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56333, 0, 0, 0, 134217728, 147456, 262144, 0, 0, 10, 0),
(56336, 0, 0, 0, 134217728, 147456, 262144, 0, 0, 20, 0);
