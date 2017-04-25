-- 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (48778, 73313);
INSERT INTO `spell_linked_spell` (`spell_trigger` ,`spell_effect`, `type`, `comment`)  VALUES
(48778, 50772, 0, 'Acherus Deathcharger - Summon Unholy Mount Visual'),
(73313, 50772, 0, 'Crimson Deathcharger - Summon Unholy Mount Visual');
