DELETE FROM `spell_proc_event` WHERE `entry` IN(46913, 46914, 46915);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 46913, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bloodsurge (Rank 1)
( 46914, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Bloodsurge (Rank 2)
( 46915, 0x00,   4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Bloodsurge (Rank 3)