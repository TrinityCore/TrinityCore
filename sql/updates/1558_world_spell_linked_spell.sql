DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '44869' AND `spell_effect` = '-45018';
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '46019' AND `spell_effect` = '-45018';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(44869, -45018, 1, 'Remove Arcane Buffet'),
(46019, -45018, 1, 'Remove Arcane Buffet');