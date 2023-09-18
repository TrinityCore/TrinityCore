--
DELETE FROM `spell_area` WHERE `spell` = 57940 AND `area` IN (4723, 4809, 4813, 4820);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(57940, 4723, 0, 0, 0, 0, 2, 1, 0, 0),
(57940, 4809, 0, 0, 0, 0, 2, 1, 0, 0),
(57940, 4813, 0, 0, 0, 0, 2, 1, 0, 0),
(57940, 4820, 0, 0, 0, 0, 2, 1, 0, 0);

UPDATE `spell_area` SET `quest_start_status` = 0, `quest_end_status` = 0 WHERE `spell` = 57940;
