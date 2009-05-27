-- Teleports in dk starting area
DELETE FROM `spell_script_target` WHERE entry IN
(54699,54725,54744,54746);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(54699,1,0),
(54725,1,0),
(54744,1,0),
(54746,1,0);