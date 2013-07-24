-- Molten core
DELETE FROM `spell_proc_event` WHERE `entry` IN (47245, 47246, 47247);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(47245, 0, 5, 4, 0, 0, 0, 1, 0, 0, 0),
(47246, 0, 5, 4, 0, 0, 0, 1, 0, 0, 0),
(47247, 0, 5, 4, 0, 0, 0, 1, 0, 0, 0);
