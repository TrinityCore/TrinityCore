DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (781, 57635, 60932, 61507, 49576);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(781,    56446,  0, 'Disengage'),
(57635,  57636,  0, 'Disengage'),
(60932,  60934,  0, 'Disengage'),
(61507,  61508,  0, 'Disengage'),
(49576,  49560,  0, 'Death Grip');
