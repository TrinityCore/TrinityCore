DELETE FROM `spell_proc_event` WHERE `entry` IN (71545,71406);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(71545,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,50,0), -- Tiny Abomination in a Jar (Heroic)
(71406,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,50,0); -- Tiny Abomination in a Jar
