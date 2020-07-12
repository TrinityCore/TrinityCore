-- Blackwing Descent
SET @LEADER := 250049;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 250049, 0, 0, 3, 0, 0),
(@LEADER, 250048, 0, 0, 3, 0, 0);

SET @LEADER := 250141;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 250141, 0, 0, 3, 0, 0),
(@LEADER, 250140, 0, 0, 3, 0, 0);

SET @LEADER := 250132;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 250132, 0, 0, 3, 0, 0),
(@LEADER, 250136, 0, 0, 3, 0, 0),
(@LEADER, 250135, 0, 0, 3, 0, 0),
(@LEADER, 250139, 0, 0, 3, 0, 0);

SET @LEADER := 250134;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 250134, 0, 0, 3, 0, 0),
(@LEADER, 250137, 0, 0, 3, 0, 0),
(@LEADER, 250138, 0, 0, 3, 0, 0),
(@LEADER, 250133, 0, 0, 3, 0, 0);

-- Blackrock Caverns
SET @LEADER := 361731;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361731, 0, 0, 3, 0, 0),
(@LEADER, 361730, 0, 0, 3, 0, 0);

SET @LEADER := 361736;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361736, 0, 0, 3, 0, 0),
(@LEADER, 361739, 0, 0, 3, 0, 0);

SET @LEADER := 361742;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 361744;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361742, 0, 0, 3, 0, 0),
(@LEADER, 361744, 0, 0, 3, 0, 0);

SET @LEADER := 361745;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361745, 0, 0, 3, 0, 0),
(@LEADER, 361746, 0, 0, 3, 0, 0);

SET @LEADER := 361756;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361756, 0, 0, 3, 0, 0),
(@LEADER, 361757, 0, 0, 3, 0, 0),
(@LEADER, 361759, 0, 0, 3, 0, 0),
(@LEADER, 361760, 0, 0, 3, 0, 0),
(@LEADER, 361758, 0, 0, 3, 0, 0);

SET @LEADER := 361774;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361774, 0, 0, 3, 0, 0),
(@LEADER, 361770, 0, 0, 3, 0, 0),
(@LEADER, 361768, 0, 0, 3, 0, 0),
(@LEADER, 361773, 0, 0, 3, 0, 0);

SET @LEADER := 361743;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361743, 0, 0, 3, 0, 0),
(@LEADER, 361740, 0, 0, 3, 0, 0),
(@LEADER, 361741, 0, 0, 3, 0, 0);

SET @LEADER := 361738;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361738, 0, 0, 3, 0, 0),
(@LEADER, 361735, 0, 0, 3, 0, 0),
(@LEADER, 361737, 0, 0, 3, 0, 0);

SET @LEADER := 361734;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361734, 0, 0, 3, 0, 0),
(@LEADER, 361732, 0, 0, 3, 0, 0),
(@LEADER, 361733, 0, 0, 3, 0, 0);

SET @LEADER := 361832;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361832, 0, 0, 3, 0, 0),
(@LEADER, 361814, 0, 0, 3, 0, 0),
(@LEADER, 361839, 0, 0, 3, 0, 0),
(@LEADER, 361831, 0, 0, 3, 0, 0);

SET @LEADER := 361828;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 361827;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361828, 0, 0, 3, 0, 0),
(@LEADER, 361837, 0, 0, 3, 0, 0),
(@LEADER, 361812, 0, 0, 3, 0, 0),
(@LEADER, 361827, 0, 0, 3, 0, 0);

SET @LEADER := 361829;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 361830;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361829, 0, 0, 3, 0, 0),
(@LEADER, 361813, 0, 0, 3, 0, 0),
(@LEADER, 361838, 0, 0, 3, 0, 0),
(@LEADER, 361830, 0, 0, 3, 0, 0);

SET @LEADER := 361840;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361840, 0, 0, 3, 0, 0),
(@LEADER, 361815, 0, 0, 3, 0, 0),
(@LEADER, 361816, 0, 0, 3, 0, 0),
(@LEADER, 361834, 0, 0, 3, 0, 0),
(@LEADER, 361833, 0, 0, 3, 0, 0);

SET @LEADER := 361817;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 361841;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 361817, 0, 0, 3, 0, 0),
(@LEADER, 361818, 0, 0, 3, 0, 0),
(@LEADER, 361841, 0, 0, 3, 0, 0),
(@LEADER, 361836, 0, 0, 3, 0, 0),
(@LEADER, 361835, 0, 0, 3, 0, 0);
