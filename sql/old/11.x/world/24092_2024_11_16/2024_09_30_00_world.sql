-- SpellArea
DELETE FROM `spell_area` WHERE (`spell` = 59073 AND `area` IN (4756, 4755, 4757, 4714)) OR (`spell` = 49416 AND `area` = 4756) OR (`spell` = 68630 AND `area` = 4786);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(59073, 4756, 14078, 14159, 0, 0, 2, 3, 64, 1|2|8|32),
(59073, 4755, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(59073, 4757, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(59073, 4714, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(49416, 4756, 14078, 14099, 0, 0, 2, 3, 64, 1|8|32),
(68630, 4786, 0, 14375, 0, 0, 2, 3, 0, 1|2|8|32);
