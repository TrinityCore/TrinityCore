-- 
-- Solace of the Defeated/Solace of the Fallen (Normal/Heroic) proc fix
DELETE FROM `spell_proc_event` WHERE `entry` IN (67698,67752);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(67698, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(67752, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0);
