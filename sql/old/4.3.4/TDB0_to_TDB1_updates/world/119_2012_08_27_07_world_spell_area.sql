-- Fix quest - The Angry Gorloc ID: 12578
DELETE FROM `spell_area` WHERE `spell`=54057;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
(54057, 4297, 12578, 1, 12578, 0, 0, 2, 1);
