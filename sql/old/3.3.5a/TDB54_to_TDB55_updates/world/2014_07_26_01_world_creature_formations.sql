-- Fix Garadar Wolf Rider Formations
UPDATE `creature` SET `position_x`=-1312.285,`position_y`=6940.27,`position_z`=31.40549,`orientation`=1.049322 WHERE `guid`=68368;
DELETE FROM `creature_formations` WHERE `leaderGUID`=68369;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(68369,68369,0,0,2),(68369,68368,8,0,2);
UPDATE `creature` SET `position_x`=-1212.921,`position_y`=7400.358,`position_z`=28.68889,`orientation`=2.005122 WHERE `guid`=68370;
DELETE FROM `creature_formations` WHERE `leaderGUID`=68371;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(68371,68371,0,0,2),(68371,68370,8,0,2);
