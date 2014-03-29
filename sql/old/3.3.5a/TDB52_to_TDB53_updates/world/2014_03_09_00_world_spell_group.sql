--
UPDATE `spell_group` SET `spell_id`=58179 WHERE `id`=1061;
DELETE FROM `spell_ranks` WHERE `first_spell_id`=58179;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(58179,58179,1), -- Infected Wounds (Rank 1)
(58179,58180,2), -- Infected Wounds (Rank 2)
(58179,58181,3); -- Infected Wounds (Rank 3)
