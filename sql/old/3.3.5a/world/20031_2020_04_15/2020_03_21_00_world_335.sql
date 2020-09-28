-- Ragefire Chasm
-- Correction of current linking

-- As seen from entering the area
-- Platform bottom right
DELETE FROM `creature_formations` WHERE `memberGUID` IN (48702,48701);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48702, 48702, 0, 0, 3, 0, 0),
(48702, 48701, 0, 0, 3, 0, 0);

-- Platform bottom left
DELETE FROM `creature_formations` WHERE `memberGUID` IN (48693,48692,48705);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48693, 48693, 0, 0, 3, 0, 0),
(48693, 48692, 0, 0, 3, 0, 0),
(48693, 48705, 0, 0, 3, 0, 0);

-- Platform top right
DELETE FROM `creature_formations` WHERE `memberGUID` IN (48721,48720,48719);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48721, 48721, 0, 0, 3, 0, 0),
(48721, 48720, 0, 0, 3, 0, 0),
(48721, 48719, 0, 0, 3, 0, 0);

-- Platform top left
DELETE FROM `creature_formations` WHERE `memberGUID` IN (48710,48709);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48710, 48710, 0, 0, 3, 0, 0),
(48709, 48709, 0, 0, 3, 0, 0);
