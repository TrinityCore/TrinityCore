DELETE FROM `spell_proc_event` WHERE `entry` IN (44557, 44560, 44561);

INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(44557, 0x00, 3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0), -- Enduring Winter (Rank 1)
(44560, 0x00, 3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0), -- Enduring Winter (Rank 2)
(44561, 0x00, 3, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0); -- Enduring Winter (Rank 3)
