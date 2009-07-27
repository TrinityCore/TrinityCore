DELETE FROM `spell_proc_event` WHERE `entry` IN (16164, 49149, 50115, 49217, 49654, 49655, 49137, 49657, 58620);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 16164, 0x00,  11, 0x901000C3, 0x00001000, 0x00000000, 0x00000000, 0x00000002,   0,   0,   0), -- Elemental Focus
( 49149, 0x00,  15, 0x00000006, 0x00020002, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chill of the Grave
( 50115, 0x00,  15, 0x00000006, 0x00020002, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Chill of the Grave
( 49217, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49654, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49655, 0x00,  15, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000,   0,   0,   1), -- Wandering Plague
( 49137, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Endless Winter
( 49657, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Endless Winter
( 58620, 0x00,  15, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Glyph of Chains of Ice