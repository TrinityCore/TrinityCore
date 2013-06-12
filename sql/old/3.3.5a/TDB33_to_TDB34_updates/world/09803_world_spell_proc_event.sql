DELETE FROM `spell_proc_event` WHERE `entry` IN (75474,75465,75457,75455);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(75474,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,45), -- Charred Twilight Scale (Heroic)
(75465,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,45), -- Charred Twilight Scale
(75457,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,45), -- Sharpened Twilight Scale (Heroic)
(75455,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,45); -- Sharpened Twilight Scale
