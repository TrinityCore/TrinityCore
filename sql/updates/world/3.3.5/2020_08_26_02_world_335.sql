--
DELETE FROM `creature_formations` WHERE `leaderGUID` = 42895;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(42895,42895,0,0,515,0,0),
(42895,42896,6.3,360,515,0,0);
