--
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127649);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127649,127649,0,0,2,0,0),
(127649,127701,3,360,2,9,19),
(127649,127702,3,40,2,9,19),
(127649,127670,3,320,2,9,19),
(127649,127671,3,260,2,9,19);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127645);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127645,127645,0,0,2,0,0),
(127645,127691,3,360,2,7,15),
(127645,127692,3,40,2,7,15),
(127645,127664,3,320,2,7,15),
(127645,127665,3,260,2,7,15);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127640);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127640,127640,0,0,2,0,0),
(127640,127685,3,360,2,8,17),
(127640,127686,3,40,2,8,17),
(127640,127656,3,320,2,8,17),
(127640,127657,3,260,2,8,17);
