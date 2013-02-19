DELETE FROM `spell_proc_event` WHERE `entry` IN (53709, 53710, 53711);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(53709, 2, 10, 16384, 0, 0, 0, 0, 0, 0, 0),
(53710, 2, 10, 16384, 0, 0, 0, 0, 0, 0, 0),
(53711, 2, 10, 16384, 0, 0, 0, 0, 0, 0, 0);
