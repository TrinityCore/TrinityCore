DELETE FROM `spell_proc_event` WHERE `entry` in (30293,30295,30296);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
( 30293, 0x00,   5, 0x00000381, 0x008200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0),
( 30295, 0x00,   5, 0x00000381, 0x008200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0),
( 30296, 0x00,   5, 0x00000381, 0x008200C0, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0);
