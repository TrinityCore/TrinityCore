DELETE FROM `spell_proc_event` WHERE `entry` IN (70215,72858,72859,72860);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(70215,0x00,0,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000,0,100,0), -- Gaseous Bloat
(72858,0x00,0,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000,0,100,0), -- Gaseous Bloat
(72859,0x00,0,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000,0,100,0), -- Gaseous Bloat
(72860,0x00,0,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000,0,100,0); -- Gaseous Bloat
