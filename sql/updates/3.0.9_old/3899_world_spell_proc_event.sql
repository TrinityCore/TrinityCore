DELETE FROM `spell_proc_event` WHERE `entry` IN (18096, 18073);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(18096,	0x00,	5,	0x00000060,	0x00800080,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0), -- Pyroclasm (Rank 1)
(18073,	0x00,	5,	0x00000060,	0x00800080,	0x00000000,	0x00000000,	0x00000000,	0,	0,	0); -- Pyroclasm (Rank 2)
