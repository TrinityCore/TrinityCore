-- Spawned Hatecoil Crusher, just missing waypoints
SET @NPC := 21002846; -- Don't change this one, it refers to an already spawned NPC
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3769.575,`position_y`=4365.073,`position_z`=40.03527 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3769.575,4365.073,40.03527,0,0,0,0,100,0),
(@PATH,2,-3771.531,4348.69,36.24962,0,0,0,0,100,0),
(@PATH,3,-3772.038,4325.191,30.93649,0,0,0,0,100,0),
(@PATH,4,-3771.531,4348.69,36.24962,0,0,0,0,100,0),
(@PATH,5,-3769.575,4365.073,40.03527,0,0,0,0,100,0),
(@PATH,6,-3773.363,4392.082,43.57207,0,0,0,0,100,0),
(@PATH,7,-3773.005,4408.425,44.43084,0,0,0,0,100,0),
(@PATH,8,-3773.363,4392.082,43.57207,0,0,0,0,100,0),
(@PATH,9,-3769.575,4365.073,40.03527,0,0,0,0,100,0);

-- Missing Hatecoil Crusher
SET @NPC := 210219109;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@NPC, 91782, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3753.509, 4486.207, 43.82869, 1.474918, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972);
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3749.773,`position_y`=4534.186,`position_z`=42.52508 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3749.773,4534.186,42.52508,0,0,0,0,100,0),
(@PATH,2,-3750,4549.479,42.27508,0,0,0,0,100,0),
(@PATH,3,-3749.773,4534.186,42.52508,0,0,0,0,100,0),
(@PATH,4,-3749.997,4522.347,42.73863,0,0,0,0,100,0),
(@PATH,5,-3749.16,4513.67,42.91295,0,0,0,0,100,0),
(@PATH,6,-3749.997,4522.347,42.73863,0,0,0,0,100,0),
(@PATH,7,-3749.773,4534.186,42.52508,0,0,0,0,100,0);

-- Missing nagas
DELETE FROM `creature` WHERE `guid` BETWEEN @NPC+1 AND @NPC+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@NPC+1, 91783, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3833.797, 4549.335, 61.19432, 4.630162, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(@NPC+2, 91781, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3833.8, 4528.042, 61.52602, 1.611757, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(@NPC+3, 95861, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3736.434, 4491.454, 43.52844, 0.1484137, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(@NPC+4, 91783, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3733.577, 4497.911, 43.70977, 5.311149, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972);

-- Pathing for missing Hatecoil Arcanist
SET @NPC := @NPC+5;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@NPC, 97171, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3732.86, 4606.325, 39.33774, 0.6579589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972);
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3727.243,`position_y`=4610.663,`position_z`=38.17675 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '161837 197115');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3727.243,4610.663,38.17675,0,0,0,0,100,0),
(@PATH,2,-3731.275,4607.55,39.01025,0,0,0,0,100,0),
(@PATH,3,-3727.243,4610.663,38.17675,0,0,0,0,100,0),
(@PATH,4,-3715.375,4610.309,36.16308,0,0,0,0,100,0),
(@PATH,5,-3707.493,4607.405,34.71887,0,0,0,0,100,0),
(@PATH,6,-3695.873,4609.3,29.70098,0,0,0,0,100,0),
(@PATH,7,-3699.67,4608.683,31.25534,0,0,0,0,100,0),
(@PATH,8,-3695.873,4609.3,29.70098,0,0,0,0,100,0),
(@PATH,9,-3686.632,4616.69,26.20769,0,0,0,0,100,0),
(@PATH,10,-3694.741,4612.533,28.95849,0,0,0,0,100,0),
(@PATH,11,-3686.632,4616.69,26.20769,0,0,0,0,100,0),
(@PATH,12,-3669.019,4618.189,21.39568,0,0,0,0,100,0),
(@PATH,13,-3682.152,4617.072,25.01282,0,0,0,0,100,0),
(@PATH,14,-3669.019,4618.189,21.39568,0,0,0,0,100,0),
(@PATH,15,-3654.946,4624.197,16.24043,0,0,0,0,100,0),
(@PATH,16,-3636.337,4634.293,10.48033,0,0,0,0,100,0),
(@PATH,17,-3656.268,4623.632,16.78365,0,0,0,0,100,0),
(@PATH,18,-3636.337,4634.293,10.48033,0,0,0,0,100,0),
(@PATH,19,-3631.184,4649.432,10.06678,0,0,0,0,100,0),
(@PATH,20,-3631.605,4648.194,10.03672,0,0,0,0,100,0),
(@PATH,21,-3631.184,4649.432,10.06678,0,0,0,0,100,0),
(@PATH,22,-3636.337,4634.293,10.48033,0,0,0,0,100,0),
(@PATH,23,-3631.842,4647.5,10.11958,0,0,0,0,100,0),
(@PATH,24,-3636.337,4634.293,10.48033,0,0,0,0,100,0),
(@PATH,25,-3634.451,4639.835,10.28637,0,0,0,0,100,0),
(@PATH,26,-3636.337,4634.293,10.48033,0,0,0,0,100,0),
(@PATH,27,-3654.795,4624.285,16.11287,0,0,0,0,100,0),
(@PATH,28,-3635.743,4636.038,10.36374,0,0,0,0,100,0),
(@PATH,29,-3654.946,4624.197,16.24043,0,0,0,0,100,0),
(@PATH,30,-3669.019,4618.189,21.39568,0,0,0,0,100,0),
(@PATH,31,-3659.136,4622.41,17.91083,0,0,0,0,100,0),
(@PATH,32,-3669.019,4618.189,21.39568,0,0,0,0,100,0),
(@PATH,33,-3666.169,4619.409,20.37093,0,0,0,0,100,0),
(@PATH,34,-3669.019,4618.189,21.39568,0,0,0,0,100,0),
(@PATH,35,-3686.632,4616.69,26.20769,0,0,0,0,100,0),
(@PATH,36,-3695.873,4609.3,29.70098,0,0,0,0,100,0),
(@PATH,37,-3691.98,4614.164,28.05647,0,0,0,0,100,0),
(@PATH,38,-3695.873,4609.3,29.70098,0,0,0,0,100,0),
(@PATH,39,-3707.493,4607.405,34.71887,0,0,0,0,100,0),
(@PATH,40,-3693.837,4611.846,28.59988,0,0,0,0,100,0),
(@PATH,41,-3707.493,4607.405,34.71887,0,0,0,0,100,0),
(@PATH,42,-3695.679,4611.247,29.20147,0,0,0,0,100,0),
(@PATH,43,-3707.493,4607.405,34.71887,0,0,0,0,100,0),
(@PATH,44,-3715.375,4610.309,36.16308,0,0,0,0,100,0),
(@PATH,45,-3727.243,4610.663,38.17675,0,0,0,0,100,0);

-- Pathing for missing Hatecoil Arcanist
SET @NPC := @NPC+1;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@NPC, 97171, 1456, 8040, 8081, 8388870, '0', 0, 0, 0, -3732.86, 4606.325, 39.33774, 0.6579589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972);
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3358.214,`position_y`=4634.525,`position_z`=0.4535593 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '161837 197115');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3358.214,4634.525,0.4535593,0,0,0,0,100,0),
(@PATH,2,-3350.567,4631.433,0.364815,0,0,0,0,100,0),
(@PATH,3,-3358.214,4634.525,0.4535593,0,0,0,0,100,0),
(@PATH,4,-3352.084,4632.616,0.2600764,0,0,0,0,100,0),
(@PATH,5,-3358.214,4634.525,0.4535593,0,0,0,0,100,0),
(@PATH,6,-3354.006,4633.215,0.4907893,0,0,0,0,100,0),
(@PATH,7,-3358.214,4634.525,0.4535593,0,0,0,0,100,0),
(@PATH,8,-3367.134,4652.687,0.5513048,0,0,0,0,100,0),
(@PATH,9,-3357.38,4634.266,0.4276132,0,0,0,0,100,0),
(@PATH,10,-3367.134,4652.687,0.5513048,0,0,0,0,100,0),
(@PATH,11,-3363.545,4645.909,0.5449836,0,0,0,0,100,0),
(@PATH,12,-3367.134,4652.687,0.5513048,0,0,0,0,100,0),
(@PATH,13,-3372.575,4663.66,1.427403,0,0,0,0,100,0),
(@PATH,14,-3367.304,4653.031,0.5729282,0,0,0,0,100,0),
(@PATH,15,-3372.575,4663.66,1.427403,0,0,0,0,100,0),
(@PATH,16,-3369.087,4656.631,0.8088958,0,0,0,0,100,0),
(@PATH,17,-3372.575,4663.66,1.427403,0,0,0,0,100,0),
(@PATH,18,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,19,-3372.685,4663.757,1.465489,0,0,0,0,100,0),
(@PATH,20,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,21,-3375.67,4666.407,1.981847,0,0,0,0,100,0),
(@PATH,22,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,23,-3377.944,4668.428,2.048508,0,0,0,0,100,0),
(@PATH,24,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,25,-3399.229,4683.663,3.817551,0,0,0,0,100,0),
(@PATH,26,-3390.683,4678.294,2.386368,0,0,0,0,100,0),
(@PATH,27,-3399.16,4683.617,3.798508,0,0,0,0,100,0),
(@PATH,28,-3410.668,4689.895,4.425845,0,0,0,0,100,0),
(@PATH,29,-3397.452,4682.544,3.357704,0,0,0,0,100,0),
(@PATH,30,-3410.668,4689.895,4.425845,0,0,0,0,100,0),
(@PATH,31,-3400.898,4684.465,4.080981,0,0,0,0,100,0),
(@PATH,32,-3410.668,4689.895,4.425845,0,0,0,0,100,0),
(@PATH,33,-3399.229,4683.663,3.817551,0,0,0,0,100,0),
(@PATH,34,-3405.16,4686.896,4.635074,0,0,0,0,100,0),
(@PATH,35,-3399.229,4683.663,3.817551,0,0,0,0,100,0),
(@PATH,36,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,37,-3398.982,4683.508,3.742886,0,0,0,0,100,0),
(@PATH,38,-3385.125,4674.811,1.951096,0,0,0,0,100,0),
(@PATH,39,-3372.575,4663.66,1.427403,0,0,0,0,100,0),
(@PATH,40,-3383.857,4673.684,1.923997,0,0,0,0,100,0),
(@PATH,41,-3372.575,4663.66,1.427403,0,0,0,0,100,0),
(@PATH,42,-3378.583,4668.998,2.048508,0,0,0,0,100,0),
(@PATH,43,-3372.6,4663.686,1.432652,0,0,0,0,100,0),
(@PATH,44,-3367.134,4652.687,0.5513048,0,0,0,0,100,0),
(@PATH,45,-3370.366,4659.192,0.7761549,0,0,0,0,100,0),
(@PATH,46,-3367.134,4652.687,0.5513048,0,0,0,0,100,0),
(@PATH,47,-3358.214,4634.525,0.4535593,0,0,0,0,100,0),
(@PATH,48,-3338.01,4631.406,-0.5536443,0,0,0,0,100,0),
(@PATH,49,-3357.832,4634.466,0.4606394,0,0,0,0,100,0),
(@PATH,50,-3338.01,4631.406,-0.5536443,0,0,0,0,100,0),
(@PATH,51,-3350.839,4633.389,0.06326863,0,0,0,0,100,0),
(@PATH,52,-3338.01,4631.406,-0.5536443,0,0,0,0,100,0),
(@PATH,53,-3347.826,4632.923,-0.0524236,0,0,0,0,100,0),
(@PATH,54,-3338.01,4631.406,-0.5536443,0,0,0,0,100,0),
(@PATH,55,-3345.847,4632.617,-0.0524236,0,0,0,0,100,0),
(@PATH,56,-3338.01,4631.406,-0.5536443,0,0,0,0,100,0),
(@PATH,57,-3358.214,4634.525,0.4535593,0,0,0,0,100,0);

-- Missing aura on Hatecoil Arcanists
UPDATE `creature_addon` SET `auras` = '161837 197115' WHERE `guid` IN (21003083, 21003084);

-- Hatecoil Wrangler SAI (guid-specific for the SAY line)
SET @GUID := -21003128;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,2000,3000,6000,11,197137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Throw Spear'"),
(@GUID,0,1,0,0,0,100,0,3000,4500,8000,15000,11,197144,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Hooked Net'"),
(@GUID,0,2,0,0,0,100,0,5000,6000,15000,20000,11,197141,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Lightning Prod'"),
(@GUID,0,3,0,10,0,100,1,0,40,5000,10000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Wrangler - Within 0-40 Range Out of Combat LoS - Say Line 0 (No Repeat)");

-- This one is supposed to be a Wrangler, currently it's a Warrior
UPDATE `creature` SET `id`=100216 WHERE `guid`=-@GUID;

DELETE FROM `creature_text` WHERE `CreatureID`=100216;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(100216, 0, 0, 'The landwalkers are here! We will drive them back by salt and scale!', 14, 0, 100, 25, 0, 0, 0, 'Hatecoil Wrangler to Player');
