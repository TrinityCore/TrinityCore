-- wrong entry
DELETE FROM `spell_chain` WHERE `spell_id` IN (5159);


DELETE FROM `spell_chain` WHERE `spell_id` IN (5195,5196);
INSERT INTO `spell_chain` (`spell_id`, `prev_spell`, `first_spell`, `rank`) VALUES
(5195,1062,339,3),
(5196,5195,339,4);
