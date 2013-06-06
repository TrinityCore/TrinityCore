-- Set Fel Steed Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=16441;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(16441,16441,0,0,2),
(16441,16442,10,225,2),
(16441,16440,10,120,2);
