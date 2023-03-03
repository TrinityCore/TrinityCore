DELETE FROM `spell_area` WHERE `spell` IN (30550, 30557, 30562, 30567);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `raceMask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(30550, 3457, 0, 0, 0, 0, 2, 0, 64, 11),
(30557, 3457, 0, 0, 0, 0, 2, 0, 64, 11),
(30562, 3457, 0, 0, 0, 0, 2, 0, 64, 11),
(30567, 3457, 0, 0, 0, 0, 2, 0, 64, 11);
