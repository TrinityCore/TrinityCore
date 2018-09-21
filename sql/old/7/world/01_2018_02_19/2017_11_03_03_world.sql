UPDATE `creature_addon` SET `bytes2`=1, `mount`=29284 WHERE `guid` IN (280010);
DELETE FROM `creature_addon` WHERE `guid` IN (280023, 280024, 280025);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(280023,0,29284,0,1,0,""),
(280024,0,29284,0,1,0,""),
(280025,0,29284,0,1,0,"");
 
DELETE FROM `creature_formations` WHERE `leaderGUID`=280010;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(280010, 280010, 0,   0, 515, 0, 0),
(280010, 280023, 5,  90, 515, 0, 0),
(280010, 280024, 5, 360, 515, 0, 0),
(280010, 280025, 7, 45, 515, 0, 0);
