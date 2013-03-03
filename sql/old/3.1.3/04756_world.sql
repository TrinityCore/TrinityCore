DELETE FROM `spell_proc_event` WHERE `entry` IN(54639, 54638, 54637, 61433, 61434, 49467, 50033, 50034);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 54639, 0x00,   15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 54638, 0x00,   15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 54637, 0x00,   15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 61433, 0x00,   15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 61434, 0x00,   15, 0x00400000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Blood of the north
( 49467, 0x00,   15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Death Rune Mastery
( 50033, 0x00,   15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Death Rune Mastery
( 50034, 0x00,   15, 0x00000010, 0x00020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Death Rune Mastery
