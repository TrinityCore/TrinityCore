DELETE FROM `spell_proc_event` WHERE `entry`IN(44546, 44548, 44549);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 44546, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brain Freeze (Rank 1)
( 44548, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Brain Freeze (Rank 2)
( 44549, 0x00,   3, 0x00100220, 0x00001000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Brain Freeze (Rank 3)