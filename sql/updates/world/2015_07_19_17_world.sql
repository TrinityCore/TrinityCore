-- Add Cyclonic Inspiration at Entering Area "Shrine of Two Moons" and "Shrine of Seven Stars"
DELETE FROM `spell_area` WHERE `spell` IN (128943, 131526); -- These spells are used only here
INSERT INTO `spell_area` (`spell`, `area`, `autocast`, `racemask`) VALUES
(128943, 6484, 1, 18875469), -- Shrine of Seven Stars
(131526, 6519, 1, 33555378); -- Shrine of Two Moons 
