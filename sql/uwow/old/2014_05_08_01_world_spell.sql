-- Displacer Beast
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 137452 AND `spell_trigger` = 768;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
('137452', '768', '0', '0', '0', '0', '0', '0', '0', '0', 'Druid: talent Displacer Beast');