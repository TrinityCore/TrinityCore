--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (28273, -28273);
INSERT INTO `spell_linked_spell` VALUES 
(28273, -28274, 0, 'Bloodthistle'),
(-28273, 28274, 0, 'Bloodthistle');
