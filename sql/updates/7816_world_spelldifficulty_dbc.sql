-- Add examples for spell difficulties
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (3000,3001);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(3000, 47772, 56935, 0, 0),
(3001, 47773, 56934, 0, 0);
