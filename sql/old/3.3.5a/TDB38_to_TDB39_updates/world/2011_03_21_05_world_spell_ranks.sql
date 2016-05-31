DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (5487,33943);
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES
(5487,5487,1),
(5487,9634,2),
(33943,33943,1),
(33943,40120,2);
