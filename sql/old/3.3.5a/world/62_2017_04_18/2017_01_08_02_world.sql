-- 
DELETE FROM `spell_area` WHERE `quest_start` IN (13861, 13862, 13863, 13864) AND `area`=4522;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(64576, 4522, 13864, 13864, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13861, 13861, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13862, 13862, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13863, 13863, 0, 0, 2, 1, 74, 11);
