-- Deathwhisper Necrolyte pathing
SET @NPC := 202103;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,555.3976,303.5347,507.6232,0,0,0,100,0),
(@PATH,2,568.4896,297.9913,506.9572,0,0,0,100,0),
(@PATH,3,586.1476,292.5486,506.3322,0,0,0,100,0),
(@PATH,4,598.5833,292.6007,506.3322,0,0,0,100,0),
(@PATH,5,602.3438,300.2135,506.9457,0,0,0,100,0),
(@PATH,6,603.0573,307.5399,507.6957,0,0,0,100,0),
(@PATH,7,611.7239,316.1129,508.4457,0,0,0,100,0),
(@PATH,8,620.0677,312.684,508.1957,0,0,0,100,0),
(@PATH,9,622.184,305.0868,508.3207,0,0,0,100,0),
(@PATH,10,616.684,295.2083,507.8819,0,0,0,100,0),
(@PATH,11,613.9236,287.4288,507.0737,0,0,0,100,0),
(@PATH,12,618.5174,272.882,507.6097,0,0,0,100,0),
(@PATH,13,621.4445,263.4861,507.9438,0,0,0,100,0),
(@PATH,14,618.5174,272.882,507.6097,0,0,0,100,0),
(@PATH,15,613.9236,287.4288,507.0737,0,0,0,100,0),
(@PATH,16,616.684,295.2083,507.8819,0,0,0,100,0),
(@PATH,17,622.184,305.0868,508.3207,0,0,0,100,0),
(@PATH,18,620.0677,312.684,508.1,0,0,0,100,0),
(@PATH,19,611.7239,316.1129,508.4457,0,0,0,100,0),
(@PATH,20,603.0573,307.5399,507.6629,0,0,0,100,0),
(@PATH,21,602.3438,300.2135,506.8405,0,0,0,100,0),
(@PATH,22,598.5833,292.6007,506.3498,0,0,0,100,0),
(@PATH,23,586.1476,292.5486,506.3322,0,0,0,100,0),
(@PATH,24,568.4896,297.9913,506.9572,0,0,0,100,0);
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@NPC,@NPC,0,0,2),
(@NPC,201819,7,270,2),
(@NPC,201934,7,306,2),
(@NPC,202121,7,342,2),
(@NPC,202196,7,18,2),
(@NPC,202098,7,54,2),
(@NPC,201954,7,90,2);

-- Deathwhisper Necrolyte pathing
SET @NPC := 202273;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=611.9375,`position_y`=117.441,`position_z`=508.0308 WHERE `guid` IN (202273,202054,201845,201914,202145,202227,201988);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,611.9375,117.441,508.0308,0,0,0,100,0),
(@PATH,2,620.9531,139.3004,506.531,0,0,0,100,0),
(@PATH,3,624.3854,153.9531,507.3376,0,0,0,100,0),
(@PATH,4,625.8316,167.6233,507.4478,0,0,0,100,0),
(@PATH,5,622.8368,183.6788,507.7706,0,0,0,100,0),
(@PATH,6,625.8316,167.6233,507.4478,0,0,0,100,0),
(@PATH,7,624.3854,153.9531,507.3376,0,0,0,100,0),
(@PATH,8,620.9531,139.3004,506.531,0,0,0,100,0),
(@PATH,9,611.9375,117.441,508.0308,0,0,0,100,0),
(@PATH,10,610.8828,99.47656,510.0737,0,0,0,100,0);
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@NPC,@NPC,0,0,2),
(@NPC,202054,7,270,2),
(@NPC,201845,7,306,2),
(@NPC,201914,7,342,2),
(@NPC,202145,7,18,2),
(@NPC,202227,7,54,2),
(@NPC,201988,7,90,2);

-- Fix previous creature removal
DELETE FROM `creature` WHERE `id`=42160;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`, `position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(42160,36881,658,3,1,0,0,592.975,176.104,510.1582,508.746,86400,0,0,1,0,0);
UPDATE `creature` SET `position_x`=611.9375,`position_y`=117.441,`position_z`=508.0308 WHERE `guid` IN (202273,202054,201845,201914,202145,202227,201988);
DELETE FROM `creature_formations` WHERE `leaderGUID`=202231;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(202231,202231,0,0,2),
(202231,202099,7,270,2),
(202231,202282,7,306,2),
(202231,202125,7,342,2),
(202231,202203,7,18,2),
(202231,201960,7,54,2),
(202231,42160,7,90,2);

-- Update Scourgelord Tyrannus "Make him fly"
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36794;
