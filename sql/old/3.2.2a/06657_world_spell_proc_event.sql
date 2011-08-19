DELETE FROM `spell_proc_event` WHERE `entry` IN (16952,16954);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(16952,0,7,233472,1024,262144,0,2,0,0,0),
(16954,0,7,233472,1024,262144,0,2,0,0,0);
