DELETE FROM `spell_proc_event` WHERE `entry` IN (20210, 20212, 20213, 20214, 20215);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 20210, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 1)
( 20212, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 2)
( 20213, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 3)
( 20214, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Illumination (Rank 4)
( 20215, 0x00,  10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0); -- Illumination (Rank 5)