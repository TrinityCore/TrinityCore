
DELETE FROM `spell_proc_event` WHERE `entry` IN
(15318,15272,15320);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 15318, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0), -- Shadow Affinity (Rank 1)
( 15272, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0), -- Shadow Affinity (Rank 2)
( 15320, 0x20,   0, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00002000,   0,   0,   0); -- Shadow Affinity (Rank 3)
