SET @LEADER := 255000;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 255000, 0, 0, 3, 0, 0),
(@LEADER, 255004, 0, 0, 3, 0, 0),
(@LEADER, 254998, 0, 0, 3, 0, 0),
(@LEADER, 254999, 0, 0, 3, 0, 0),
(@LEADER, 255001, 0, 0, 3, 0, 0);

SET @LEADER := 255021;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 255021, 0, 0, 3, 0, 0),
(@LEADER, 255020, 0, 0, 3, 0, 0),
(@LEADER, 255022, 0, 0, 3, 0, 0),
(@LEADER, 255019, 0, 0, 3, 0, 0),
(@LEADER, 255023, 0, 0, 3, 0, 0);
