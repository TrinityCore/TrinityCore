DELETE FROM `spell_proc_event` WHERE `entry` in (67365,53527,54925);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(67365,2,10,0,0x0800,0,0x040000,0,0,70,6),
(53527,1,10,0,0,0x0004,0x0400,0x0001,0,100,0),
(54925,2,10,0,0x0200,0,0,0,0,0,0);
