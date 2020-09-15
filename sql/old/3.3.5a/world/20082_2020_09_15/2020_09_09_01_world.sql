--
DELETE FROM `creature_formations` WHERE `leaderGUID` = 23473;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(23473,23473,0,0,515,0,0),
(23473,23472,7.5,360,515,0,0);
