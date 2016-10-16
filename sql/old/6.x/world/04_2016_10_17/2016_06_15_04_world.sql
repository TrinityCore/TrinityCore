--
DELETE FROM `spell_area` WHERE `spell` IN (60922, 49417, 49416) AND `quest_start` = 14071;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `gender`, `autocast`, `quest_start_status`) VALUES
(60922, 4765, 14071, 2, 1, 8),
(49417, 4737, 14071, 2, 1, 8),
(49416, 4767, 14071, 2, 1, 8);
