-- Summon Water Elemental
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=31687 AND `spell_effect`=70907;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (31687, 70907, 0,'Summon Water Elemental');
