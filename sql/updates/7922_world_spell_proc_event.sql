DELETE FROM `spell_proc_event` WHERE `entry` IN (66191,66192);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(66191, 0x00,  15, 0x00400010, 0x20020004, 0x00000000, 0x00000010, 0x00000000,   0, 100,   0), -- Threat of Thassarian (Rank 2)
(66192, 0x00,  15, 0x00400010, 0x20020004, 0x00000000, 0x00000010, 0x00000000,   0, 100,   0); -- Threat of Thassarian (Rank 3)

