-- 
DELETE FROM `spell_area` WHERE `spell` IN (55012,72914);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(55012, 4422, 12841, 0, 0, 0, 2, 1, 64, 0), -- Brunnhildar Village
(55012, 4425, 12841, 0, 0, 0, 2, 1, 64, 0), -- The Forlorn Mine
(55012, 4535, 12841, 0, 0, 0, 2, 1, 64, 0), -- The Pit of the Fang
(55012, 4455, 12841, 0, 0, 0, 2, 1, 64, 0), -- Hibernal Cavern
(55012, 4437, 12841, 12924, 0, 0, 2, 1, 64, 1), -- Valley of Ancient Winters
(55012, 4438, 12841, 12924, 0, 0, 2, 1, 64, 1), -- Dun Niffelem
(55012, 4430, 12886, 13064, 0, 0, 2, 1, 74, 1); -- temple of storm 12886
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-55012;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-55012,-72914,0,"Lok'lira's Bargain");
