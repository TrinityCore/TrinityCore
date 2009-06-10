DELETE FROM `spell_proc_event` WHERE `entry` IN (59088, 59089, 58388);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(59088,	0x00,	4,	0x00000000,	0x00000002,	0x00000000,	0x00010000,	0x00000000,	0,	0,	0), -- Improved Spell Reflection
(59089,	0x00,	4,	0x00000000,	0x00000002,	0x00000000,	0x00010000,	0x00000000,	0,	0,	0); -- Improved Spell Reflection