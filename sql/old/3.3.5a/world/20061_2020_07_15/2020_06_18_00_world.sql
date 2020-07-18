-- 
DELETE FROM  `creature_addon` WHERE `guid` IN (43202,43203);
DELETE FROM  `waypoint_data` WHERE `id` IN (432020,432030);
DELETE FROM `creature_formations` WHERE `memberGUID` IN (43201,43202,43203);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(43201, 43201, 0, 0, 515),
(43201, 43202, 5, 45, 515),
(43201, 43203, 5, 315, 515);
