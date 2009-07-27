DELETE FROM `spell_proc_event` WHERE `entry` IN(47569, 47570);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 47569, 0x00,   6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,  50,   0), -- Improved Shadowform (Rank 1)
( 47570, 0x00,   6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0, 100,   0); -- Improved Shadowform (Rank 2)