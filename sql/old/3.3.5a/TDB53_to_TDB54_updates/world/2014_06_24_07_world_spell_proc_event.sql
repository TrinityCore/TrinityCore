-- Improved Mana Gems
DELETE FROM `spell_proc_event` WHERE `entry` IN (37447, 61062);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES 
(37447, 0, 3, 0, 0x00000100, 0, 0x04000, 0, 0, 0, 0), -- Serpent-Coil Braid
(61062, 0, 3, 0, 0x00000100, 0, 0x04000, 0, 0, 0, 0); -- 2/5 Frostfire Garb
