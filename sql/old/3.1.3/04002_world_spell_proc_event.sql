DELETE FROM `spell_proc_event` WHERE `entry` IN (50880, 50884, 50885, 50886, 50887, 55610);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 50880, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50884, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50885, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50886, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 50887, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Icy Talons
( 55610, 0x00,  15, 0x00000000, 0x04000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Improved Icy Talons
