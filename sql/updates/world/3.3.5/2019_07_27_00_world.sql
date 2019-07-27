-- Borrowed Time
DELETE FROM `spell_ranks` WHERE `first_spell_id`=59887;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(59887,59887,1),
(59887,59888,2),
(59887,59889,3),
(59887,59890,4),
(59887,59891,5);
UPDATE `spell_proc` SET `SpellId`=-59887 WHERE `SpellId`=59891;
