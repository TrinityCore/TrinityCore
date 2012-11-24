DELETE FROM `spell_proc_event` WHERE `entry` IN (56636,56637,56638);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 56636, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Taste for Blood (Rank 1)
( 56637, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6), -- Taste for Blood (Rank 2)
( 56638, 0x00,   4, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   6); -- Taste for Blood (Rank 3)
