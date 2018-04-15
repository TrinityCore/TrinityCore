DELETE FROM `spell_proc_event` WHERE `entry` IN (56342, 56343, 56344, 59725);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 59725, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000800,   0,   0,   0), -- Improved Spell Reflection
( 56342, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0), -- Lock and Load
( 56343, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0), -- Lock and Load
( 56344, 0x00,   9, 0x00000018, 0x08000000, 0x00020000, 0x00000000, 0x00000000,   0,   0,   0); -- Lock and Load
