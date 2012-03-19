DELETE FROM `spell_proc_event` WHERE `entry` IN (12281, 12812, 12813, 12814, 12815);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 12281, 0x00,   4, 0xAA600444, 0x00400105, 0x00000000, 0x00000000, 0x00000000,   0,   0,  6), -- Sword Specialization (Rank 1)
( 12812, 0x00,   4, 0xAA600444, 0x00400105, 0x00000000, 0x00000000, 0x00000000,   0,   0,  6), -- Sword Specialization (Rank 2)
( 12813, 0x00,   4, 0xAA600444, 0x00400105, 0x00000000, 0x00000000, 0x00000000,   0,   0,  6), -- Sword Specialization (Rank 3)
( 12814, 0x00,   4, 0xAA600444, 0x00400105, 0x00000000, 0x00000000, 0x00000000,   0,   0,  6), -- Sword Specialization (Rank 4)
( 12815, 0x00,   4, 0xAA600444, 0x00400105, 0x00000000, 0x00000000, 0x00000000,   0,   0,  6); -- Sword Specialization (Rank 5)