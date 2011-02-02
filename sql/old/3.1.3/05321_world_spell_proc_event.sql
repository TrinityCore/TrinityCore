DELETE FROM `spell_proc_event` WHERE `entry` IN (54815,54845,56800);
INSERT INTO `spell_proc_event` VALUES
( 54815, 0x00,   7, 0x00008000, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0), -- Glyph of Shred
( 54845, 0x00,   7, 0x00000004, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   0), -- Glyph of Starfire
( 56800, 0x00,   8, 0x00800004, 0x00000000, 0x00000000, 0x00000010, 0x00000000,   0,   0,   0); -- Glyph of Backstab
