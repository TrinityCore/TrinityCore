DELETE FROM `spell_proc_event` WHERE `entry` IN(58872, 58874);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 58872, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0), -- Damage Shield (Rank 1)
( 58874, 0x00,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043,   0,   0,   0); -- Damage Shield (Rank 2)
