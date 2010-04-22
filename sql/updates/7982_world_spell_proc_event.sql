-- Make Divine Guardian proc on Divine Sacrifice only
DELETE FROM `spell_proc_event` WHERE `entry`=53530;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES 
(53530,1,10,0x0000,0x0000,0x0004,0x0400,0x0001,0,100,0);
