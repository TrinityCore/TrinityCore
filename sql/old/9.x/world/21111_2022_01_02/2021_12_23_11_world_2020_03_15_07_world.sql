-- Molten Core Creature Formations
-- Golemagg 11988 and his 2 Corer Rager 11672
DELETE FROM `creature_formations` WHERE `memberGUID` IN (56685,56699,56684);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(56684, 56685, 0, 0, 3, 0, 0),
(56684, 56699, 0, 0, 3, 0, 0),
(56684, 56684, 0, 0, 3, 0, 0);
-- Sulfuron Harbinger 12098 and 4 Flamewaker Priests
DELETE FROM `creature_formations` WHERE `memberGUID` IN (56677,56682,56679,56678,56681);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(56677, 56677, 0, 0, 3, 0, 0),
(56677, 56682, 0, 0, 3, 0, 0),
(56677, 56679, 0, 0, 3, 0, 0),
(56677, 56678, 0, 0, 3, 0, 0),
(56677, 56681, 0, 0, 3, 0, 0);
-- Gehennas 12259 and 2 Flamewaker 11661
DELETE FROM `creature_formations` WHERE `memberGUID` IN (56737,56739,56738);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(56737, 56737, 0, 0, 3, 0, 0),
(56737, 56739, 0, 0, 3, 0, 0),
(56737, 56738, 0, 0, 3, 0, 0);
