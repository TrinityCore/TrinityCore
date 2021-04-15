--
DELETE FROM `spell_area` WHERE `spell` IN (74092, 74310);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`) VALUES
(74092,368,25495,25445,0,0,2,1,74),
(74310,133,25287,25393,0,0,2,1,74);
