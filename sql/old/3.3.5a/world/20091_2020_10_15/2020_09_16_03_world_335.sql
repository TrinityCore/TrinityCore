--
DELETE FROM `creature_formations` WHERE `leaderGUID` = 42897;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(42897,42897,0,0,515,0,0),
(42897,42898,5.5,360,515,0,0);
