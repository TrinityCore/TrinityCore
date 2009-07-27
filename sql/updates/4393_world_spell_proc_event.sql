DELETE FROM `spell_proc_event` WHERE `entry` IN (57470, 57472, 18119, 18120, 35100, 35102);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 57470, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Renewed Hope
( 57472, 0x00,   6, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Renewed Hope
( 35100, 0x00,   9, 0x00001000, 0x00000000, 0x00000001, 0x00000000, 0x00000000,   0,   0,   0), -- Concussive Barrage
( 35102, 0x00,   9, 0x00001000, 0x00000000, 0x00000001, 0x00000000, 0x00000000,   0,   0,   0), -- Concussive Barrage
( 18119, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Aftermath
( 18120, 0x00,   5, 0x00000000, 0x00800000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Aftermath