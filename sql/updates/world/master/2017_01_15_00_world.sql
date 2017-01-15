-- Hinterlands fixes
DELETE FROM `quest_template_addon` WHERE `ID` IN (27625,27626);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`) VALUES
(27625,27725),(27626,27725);

-- Missing Silvermane Wolf Spawns
SET @CGUID := 250981;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 2924, 0, 0, 0, 1, 169, 0, 0, 0, -233.8715, -2569.186, 119.0644, 0.8901179, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23222),
(@CGUID+1, 2924, 0, 0, 0, 1, 169, 0, 0, 0, -248.5712, -2559.398, 117.1755, 1.745329, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23222);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (279376);

-- Silvermane Wolf SAI
SET @GUID1 := -279376;
SET @GUID2 := -250981;
SET @GUID3 := -250982;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GUID1,@GUID2,@GUID3) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID1,0,0,0,1,0,100,0,0,2000,2500,2500,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Wolf - OOC - Emote 'oneshoteat'"),
(@GUID1,0,1,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Wolf - In Combat - Cast 'Snarl'"),
(@GUID2,0,0,0,1,0,100,0,0,2000,2500,2500,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Wolf - OOC - Emote 'oneshoteat'"),
(@GUID2,0,1,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Wolf - In Combat - Cast 'Snarl'"),
(@GUID3,0,0,0,1,0,100,0,0,2000,2500,2500,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Wolf - OOC - Emote 'oneshoteat'"),
(@GUID3,0,1,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Wolf - In Combat - Cast 'Snarl'");

-- Pathing for Razorbeak Gryphon Entry: 2658 'TDB FORMAT' 
SET @NPC := 279348;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-264.686,`position_y`=-2694.686,`position_z`=117.7743 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-264.686,-2694.686,117.7743,0,0,0,0,100,0),
(@PATH,2,-241.1465,-2656.771,122.8372,0,0,0,0,100,0),
(@PATH,3,-205.0752,-2649.225,118.0129,0,0,0,0,100,0),
(@PATH,4,-169.6267,-2648.036,122.4109,0,0,0,0,100,0),
(@PATH,5,-136.5572,-2640.875,121.2451,0,0,0,0,100,0),
(@PATH,6,-115.7628,-2613.94,118.2566,0,0,0,0,100,0),
(@PATH,7,-93.07563,-2595.024,121.4831,0,0,0,0,100,0),
(@PATH,8,-46.80187,-2590.259,122.2297,0,0,0,0,100,0),
(@PATH,9,-14.3724,-2595.485,119.8287,0,0,0,0,100,0),
(@PATH,10,13.93218,-2610.342,120.374,0,0,0,0,100,0),
(@PATH,11,55.56196,-2598.068,113.6422,0,0,0,0,100,0),
(@PATH,12,89.41504,-2615.898,115.8561,0,0,0,0,100,0),
(@PATH,13,55.56196,-2598.068,113.6422,0,0,0,0,100,0),
(@PATH,14,13.93218,-2610.342,120.374,0,0,0,0,100,0),
(@PATH,15,-14.3724,-2595.485,119.8287,0,0,0,0,100,0),
(@PATH,16,-46.80187,-2590.259,122.2297,0,0,0,0,100,0),
(@PATH,17,-93.07563,-2595.024,121.4831,0,0,0,0,100,0),
(@PATH,18,-115.7628,-2613.94,118.2566,0,0,0,0,100,0),
(@PATH,19,-136.5488,-2640.834,121.4392,0,0,0,0,100,0),
(@PATH,20,-169.6267,-2648.036,122.4109,0,0,0,0,100,0),
(@PATH,21,-205.0752,-2649.225,118.0129,0,0,0,0,100,0),
(@PATH,22,-241.1465,-2656.771,122.8372,0,0,0,0,100,0);

-- Pathing for Razorbeak Gryphon Entry: 2658 'TDB FORMAT' 
SET @NPC := 279195;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=227.1463,`position_y`=-3390.636,`position_z`=120.6472 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,227.1463,-3390.636,120.6472,0,0,0,0,100,0),
(@PATH,2,209.5332,-3372.843,114.8947,0,0,0,0,100,0),
(@PATH,3,182.41,-3362.229,115.6538,0,0,0,0,100,0),
(@PATH,4,154.5072,-3353.447,116.4072,0,0,0,0,100,0),
(@PATH,5,129.5901,-3335.738,116.8715,0,0,0,0,100,0),
(@PATH,6,138.4413,-3310.63,115.7752,0,0,0,0,100,0),
(@PATH,7,124.9734,-3287.15,116.8529,0,0,0,0,100,0),
(@PATH,8,78.90766,-3284.23,117.6309,0,0,0,0,100,0),
(@PATH,9,55.79438,-3262.541,117.6753,0,0,0,0,100,0),
(@PATH,10,30.43392,-3257.792,118.0032,0,0,0,0,100,0),
(@PATH,11,25.31977,-3236.021,120.8758,0,0,0,0,100,0),
(@PATH,12,33.44521,-3209.979,118.4602,0,0,0,0,100,0),
(@PATH,13,25.31977,-3236.021,120.8758,0,0,0,0,100,0),
(@PATH,14,30.43392,-3257.792,118.0032,0,0,0,0,100,0),
(@PATH,15,55.79438,-3262.541,117.6753,0,0,0,0,100,0),
(@PATH,16,78.90766,-3284.23,117.6309,0,0,0,0,100,0),
(@PATH,17,124.9734,-3287.15,116.8529,0,0,0,0,100,0),
(@PATH,18,138.4413,-3310.63,115.7752,0,0,0,0,100,0),
(@PATH,19,129.5901,-3335.738,116.8715,0,0,0,0,100,0),
(@PATH,20,154.5072,-3353.447,116.4072,0,0,0,0,100,0),
(@PATH,21,182.41,-3362.229,115.6538,0,0,0,0,100,0),
(@PATH,22,209.5332,-3372.843,114.8947,0,0,0,0,100,0);

-- Pathing for Razorbeak Gryphon Entry: 2658 'TDB FORMAT' 
SET @NPC := 279280;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=345.6426,`position_y`=-2954.533,`position_z`=118.0503 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,345.6426,-2954.533,118.0503,0,0,0,0,100,0),
(@PATH,2,321.3816,-2950.144,112.7444,0,0,0,0,100,0),
(@PATH,3,292.0919,-2927.606,107.2928,0,0,0,0,100,0),
(@PATH,4,259.9815,-2934.587,105.5057,0,0,0,0,100,0),
(@PATH,5,224.9548,-2947.813,106.6061,0,0,0,0,100,0),
(@PATH,6,201.1062,-2972.911,113.2153,0,0,0,0,100,0),
(@PATH,7,186.4525,-2995.777,119.7258,0,0,0,0,100,0),
(@PATH,8,147.3204,-3004.738,127.5346,0,0,0,0,100,0),
(@PATH,9,114.7075,-3003.448,126.0727,0,0,0,0,100,0),
(@PATH,10,90.01324,-2983.98,123.6671,0,0,0,0,100,0),
(@PATH,11,78.53245,-2954.068,115.9802,0,0,0,0,100,0),
(@PATH,12,73.88477,-2919.41,113.9231,0,0,0,0,100,0),
(@PATH,13,78.53245,-2954.068,115.9802,0,0,0,0,100,0),
(@PATH,14,90.01324,-2983.98,123.6671,0,0,0,0,100,0),
(@PATH,15,114.7075,-3003.448,126.0727,0,0,0,0,100,0),
(@PATH,16,147.3204,-3004.738,127.5346,0,0,0,0,100,0),
(@PATH,17,186.3047,-2995.832,119.6818,0,0,0,0,100,0),
(@PATH,18,201.1062,-2972.911,113.2153,0,0,0,0,100,0),
(@PATH,19,224.9548,-2947.813,106.6061,0,0,0,0,100,0),
(@PATH,20,259.9815,-2934.587,105.5057,0,0,0,0,100,0),
(@PATH,21,292.0919,-2927.606,107.2928,0,0,0,0,100,0),
(@PATH,22,321.3816,-2950.144,112.7444,0,0,0,0,100,0);
--
