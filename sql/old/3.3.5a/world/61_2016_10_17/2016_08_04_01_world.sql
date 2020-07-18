-- animal handler, spell ranks
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 34453;
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES
(34453, 34453, 1), -- Animal Handler, Rank 1
(34453, 34454, 2); -- Animal Handler, Rank 2
