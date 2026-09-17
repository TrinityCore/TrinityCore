DELETE FROM `spell_area` WHERE `spell` = 388530 AND `area` IN (13862,13647);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(388530, 13862, 0, 0, 0, 0, 2, 3, 64, 11),
(388530, 13647, 0, 0, 0, 0, 2, 3, 64, 11);
