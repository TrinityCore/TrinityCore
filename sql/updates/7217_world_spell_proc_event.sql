-- Entrapment
DELETE FROM `spell_proc_event` WHERE `entry` IN (19387,19388,19184);
INSERT INTO `spell_proc_event`
(`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(19184,0x00,9,0x00000010,0x00002000,0x00000000,0x00000000,0x00000000,0,0,0),
(19387,0x00,9,0x00000010,0x00002000,0x00000000,0x00000000,0x00000000,0,0,0),
(19388,0x00,9,0x00000010,0x00002000,0x00000000,0x00000000,0x00000000,0,0,0);

-- Lock and Load
DELETE FROM `spell_proc_event` WHERE `entry` IN (56342,56343,56344);
INSERT INTO `spell_proc_event`
(`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(56342,0x00,9,0x00000018,0x08000000,0x00024000,0x00000000,0x00000000,0,0,0),
(56343,0x00,9,0x00000018,0x08000000,0x00024000,0x00000000,0x00000000,0,0,0),
(56344,0x00,9,0x00000018,0x08000000,0x00024000,0x00000000,0x00000000,0,0,0);
