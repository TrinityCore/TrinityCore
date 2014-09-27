DELETE FROM `spell_area` WHERE `spell` IN(48763,48761, 45614);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(48763, 4180, 12274, 0, 0, 0, 0, 0, 74, 11),
(48761, 4180, 12274, 0, 0, 0, 1, 0, 74, 11),
(45614, 4125, 11633, 0, 0, 0, 2, 0, 74, 11),
(45614, 4135, 11633, 0, 0, 0, 2, 0, 74, 11),
(45614, 4136, 11633, 0, 0, 0, 2, 0, 74, 11),
(45614, 4137, 11633, 0, 0, 0, 2, 0, 74, 11);
