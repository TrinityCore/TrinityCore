-- [NPC][WotlK] Stormforged Loreseeker and Stormforged Pillager -- add missing paths and incorrect spawn loc
SET @CGUID := 106461;
DELETE FROM `creature` WHERE `id` IN (29586, 29843);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 29586, 571, 0, 0, 1, 1,  0, 0, 7049.645, -27.82183, 808.5272, 3.089233, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: -Unknown-)
(@CGUID+1, 29843, 571, 0, 0, 1, 1,  0, 0, 6995.886, -13.95654, 809.7472, 0.4717727, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: -Unknown-) (Auras: 12550 - Lightning Shield) (possible waypoints or random movement)
(@CGUID+2, 29586, 571, 0, 0, 1, 1,  0, 0, 6974.152, -17.91818, 809.2553, 0.2562811, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Pillager (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+3, 29843, 571, 0, 0, 1, 1,  0, 0, 6984.833, -0.527235, 809.966, 0.03490658, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: -Unknown-) (Auras: 12550 - Lightning Shield)
(@CGUID+4, 29843, 571, 0, 0, 1, 1,  0, 0, 6953.073, -4.012344, 808.3405, 3.840379, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield) (possible waypoints or random movement)
(@CGUID+5, 29843, 571, 0, 0, 1, 1,  0, 0, 7010.22, 61.93403, 812.8073, 1.53589, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+6, 29586, 571, 0, 0, 1, 1,  0, 0, 7011.019, 73.10926, 812.0643, 0.4426216, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow) (possible waypoints or random movement)
(@CGUID+7, 29843, 571, 0, 0, 1, 1,  0, 0, 6926.479, -24.19451, 803.7806, 5.987985, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield) (possible waypoints or random movement)
(@CGUID+8, 29586, 571, 0, 0, 1, 1,  0, 0, 6954.638, 55.05556, 816.7207, 0.122173, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+9, 29843, 571, 0, 0, 1, 1,  0, 0, 6921.624, 7.681424, 801.1466, 4.328416, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+10, 29586, 571, 0, 0, 1, 1, 0, 0, 6935.855, 40.69868, 796.5327, 3.473205, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+11, 29843, 571, 0, 0, 1, 1, 0, 0, 6919.627, 23.92171, 797.3717, 2.617994, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+12, 29843, 571, 0, 0, 1, 1, 0, 0, 6958.898, 77.93271, 811.8732, 5.014532, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield) (possible waypoints or random movement)
(@CGUID+13, 29586, 571, 0, 0, 1, 1, 0, 0, 6905.328, -12.22879, 801.8771, 0.4363323, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+14, 29843, 571, 0, 0, 1, 1, 0, 0, 6896.476, 14.36659, 797.7606, 0.5759587, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+15, 29843, 571, 0, 0, 1, 1, 0, 0, 6912.183, 53.53537, 797.6075, 4.014257, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+16, 29586, 571, 0, 0, 1, 1, 0, 0, 6944.983, 109.52, 811.0266, 5.061455, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+17, 29586, 571, 0, 0, 1, 1, 0, 0, 6886.117, 65.42665, 794.3042, 4.764749, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+18, 29843, 571, 0, 0, 1, 1, 0, 0, 6879.436, 35.18378, 795.2526, 0.8566515, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+19, 29843, 571, 0, 0, 1, 1, 0, 0, 7007.188, -8.436795, 807.9281, 2.792527, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield) (possible waypoints or random movement)
(@CGUID+20, 29586, 571, 0, 0, 1, 1, 0, 0, 6989.952, -16.83491, 809.6952, 3.08325, 300, 10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow) (possible waypoints or random movement)
(@CGUID+21, 29843, 571, 0, 0, 1, 1, 0, 0, 6984.833, -0.527235, 809.966, 0.03490658, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+22, 29843, 571, 0, 0, 1, 1, 0, 0, 6912.183, 53.53537, 797.6075, 4.014257, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+23, 29586, 571, 0, 0, 1, 1, 0, 0, 6886.117, 65.42665, 794.3042, 4.764749, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Pillager (Area: Frostgrip's Hollow)
(@CGUID+24, 29843, 571, 0, 0, 1, 1, 0, 0, 6989.167, 68.96354, 821.4493, 3.979351, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+25, 29843, 571, 0, 0, 1, 1, 0, 0, 7010.22, 61.93403, 812.8073, 1.53589, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormforged Loreseeker (Area: Frostgrip's Hollow) (Auras: 12550 - Lightning Shield)
(@CGUID+26, 29586, 571, 0, 0, 1, 1, 0, 0, 7049.645, -27.82183, 808.5272, 3.089233, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Stormforged Pillager (Area: Frostgrip's Hollow)

-- Stormforged Loreseeker SAI
SET @ENTRY := 29843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,300000,300000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Loreseeker - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,6000,12000,11,61561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Loreseeker - In Combat - Cast 'Lightning Fury'");

SET @MAXGUID := 943; 
SET @SCRIPTID := 2984300; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
-- UNIT_FIELD_BYTES_1 UNIT_FIELD_BYTES_1(74) | UNIT_NPC_EMOTESTATE (83)
(@SCRIPTID+0, 6, 2, 74, 8, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 10, 2, 74, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+23;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6946.438,`position_y`=106.5034,`position_z`=810.6962 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6946.438,106.5034,810.6962,0,0,0,0,100,0),
(@PATH,2,6947.188,105.0034,810.6962,0,0,0,0,100,0),
(@PATH,3,6948.688,101.0034,810.4462,0,0,0,0,100,0),
(@PATH,4,6950.188,97.50343,810.6962,0,0,0,0,100,0),
(@PATH,5,6950.688,96.50343,810.4462,0,0,0,0,100,0),
(@PATH,6,6951.938,93.75343,810.4462,0,0,0,0,100,0),
(@PATH,7,6944.983,109.52,811.0266,0,0,0,0,100,0);
-- 0x203CD047601CE480000C1D0000091FBB .go 6946.438 106.5034 810.6962

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+6;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7017.078,`position_y`=75.90573,`position_z`=812.8029 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7017.078,75.90573,812.8029,0,0,0,0,100,0),
(@PATH,2,7015.328,76.40573,813.0529,0,0,0,0,100,0),
(@PATH,3,7015.192,78.22704,814.0416,0,0,0,0,100,0),
(@PATH,4,7016.692,79.97704,813.5416,0,0,0,0,100,0),
(@PATH,5,7014.942,82.97704,813.2916,0,0,0,0,100,0),
(@PATH,6,7012.192,88.47704,813.5416,0,0,0,0,100,0),
(@PATH,7,7009.895,87.34792,813.0079,0,0,0,0,100,0),
(@PATH,8,7007.145,84.84792,812.0079,0,0,0,0,100,0),
(@PATH,9,7006.395,84.09792,812.2579,0,0,0,0,100,0),
(@PATH,10,7004.645,82.34792,812.5079,0,0,0,0,100,0),
(@PATH,11,7003.645,81.34792,813.5079,0,0,0,0,100,0),
(@PATH,12,7002.895,81.09792,813.7579,0,0,0,0,100,0),
(@PATH,13,6998.502,79.34874,813.9199,0,0,0,0,100,0),
(@PATH,14,6998.615,77.56315,813.6628,5.77704,11000,0,@SCRIPTID,100,0),
(@PATH,15,6999.143,74.79276,813.6234,0,0,0,0,100,0),
(@PATH,16,7000.893,73.79276,813.3734,0,0,0,0,100,0),
(@PATH,17,7002.143,73.29276,812.6234,0,0,0,0,100,0),
(@PATH,18,7003.143,73.04276,812.1234,0,0,0,0,100,0),
(@PATH,19,7005.393,72.29276,810.8734,0,0,0,0,100,0),
(@PATH,20,7007.978,71.71059,810.9788,0,0,0,0,100,0),
(@PATH,21,7009.478,72.46059,811.4788,0,0,0,0,100,0),
(@PATH,22,7012.728,74.21059,813.2288,0,0,0,0,100,0);
-- 0x203CD047601CE480000C1D00000A2736 .go 7017.078 75.90573 812.8029

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+20;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6979.65,`position_y`=-16.3447,`position_z`=810.4337 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6979.65,-16.3447,810.4337,0,0,0,0,100,0),
(@PATH,2,6980.65,-16.0947,810.4337,0,0,0,0,100,0),
(@PATH,3,6983.15,-15.0947,810.1837,0,0,0,0,100,0),
(@PATH,4,6986.9,-13.5947,809.6837,0,0,0,0,100,0),
(@PATH,5,6983.584,-14.9034,810.3876,0,0,0,0,100,0),
(@PATH,6,6979.434,-16.47582,810.3889,0,0,0,0,100,0),
(@PATH,7,6973.934,-17.72582,809.6389,0,0,0,0,100,0),
(@PATH,8,6972.344,-18.15562,809.4249,0,0,0,0,100,0),
(@PATH,9,6970.094,-18.15562,809.1749,0,0,0,0,100,0),
(@PATH,10,6968.344,-17.90562,809.1749,0,0,0,0,100,0),
(@PATH,11,6966.336,-18.15109,809.0977,0,0,0,0,100,0),
(@PATH,12,6963.836,-19.15109,809.3477,0,0,0,0,100,0),
(@PATH,13,6962.336,-19.40109,809.3477,0,0,0,0,100,0),
(@PATH,14,6963.628,-19.06475,809.354,0,0,0,0,100,0),
(@PATH,15,6966.361,-17.97179,809.1749,0,0,0,0,100,0),
(@PATH,16,6970.152,-18.01622,809.3362,0,0,0,0,100,0),
(@PATH,17,6972.402,-18.26622,809.5862,0,0,0,0,100,0),
(@PATH,18,6973.902,-17.76622,809.5862,0,0,0,0,100,0);
-- 0x203CD047601CE480000C1D00000A7A17 .go 6979.65 -16.3447 810.4337

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6979.378,`position_y`=-16.45584,`position_z`=810.4595 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6979.378,-16.45584,810.4595,0,0,0,0,100,0),
(@PATH,2,6973.678,-17.88321,809.4398,0,0,0,0,100,0),
(@PATH,3,6972.428,-18.13321,809.4398,0,0,0,0,100,0),
(@PATH,4,6970.178,-18.13321,809.1898,0,0,0,0,100,0),
(@PATH,5,6968.172,-18.15616,809.1057,0,0,0,0,100,0),
(@PATH,6,6966.172,-18.15616,809.1057,0,0,0,0,100,0),
(@PATH,7,6963.922,-19.15616,809.3557,0,0,0,0,100,0),
(@PATH,8,6962.128,-19.31475,809.104,0,0,0,0,100,0),
(@PATH,9,6963.628,-19.06475,809.354,0,0,0,0,100,0),
(@PATH,10,6966.347,-17.977,809.1736,0,0,0,0,100,0),
(@PATH,11,6967.847,-18.227,809.1736,0,0,0,0,100,0),
(@PATH,12,6970.113,-18.01394,809.3331,0,0,0,0,100,0),
(@PATH,13,6972.363,-18.26394,809.5831,0,0,0,0,100,0),
(@PATH,14,6973.863,-17.76394,809.5831,0,0,0,0,100,0),
(@PATH,15,6979.363,-16.51394,810.3331,0,0,0,0,100,0),
(@PATH,16,6979.677,-16.20655,810.2766,0,0,0,0,100,0),
(@PATH,17,6980.677,-15.95655,810.2766,0,0,0,0,100,0),
(@PATH,18,6983.177,-15.20655,810.2766,0,0,0,0,100,0),
(@PATH,19,6986.677,-13.70655,809.7766,0,0,0,0,100,0),
(@PATH,20,6983.584,-14.9034,810.3876,0,0,0,0,100,0);
-- 0x203CD047601CE480000C1D00000B249A .go 6979.378 -16.45584 810.4595

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6932.451,`position_y`=-25.68229,`position_z`=804.7579 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6932.451,-25.68229,804.7579,0,0,0,0,100,0),
(@PATH,2,6933.701,-25.68229,805.0079,0,0,0,0,100,0),
(@PATH,3,6937.201,-25.18229,806.0079,0,0,0,0,100,0),
(@PATH,4,6941.201,-25.18229,806.2579,0,0,0,0,100,0),
(@PATH,5,6941.431,-24.84581,806.5109,0,0,0,0,100,0),
(@PATH,6,6943.431,-24.84581,806.5109,0,0,0,0,100,0),
(@PATH,7,6946.143,-22.43077,806.916,0,0,0,0,100,0),
(@PATH,8,6943.097,-24.83194,806.5005,0,0,0,0,100,0),
(@PATH,9,6941.347,-24.83194,806.2505,0,0,0,0,100,0),
(@PATH,10,6937.597,-25.33194,806.0005,0,0,0,0,100,0),
(@PATH,11,6933.597,-25.58194,805.2505,0,0,0,0,100,0),
(@PATH,12,6932.061,-25.70512,804.6917,0,0,0,0,100,0),
(@PATH,13,6930.811,-25.20512,804.4417,0,0,0,0,100,0),
(@PATH,14,6924.748,-23.51042,803.6984,0,0,0,0,100,0),
(@PATH,15,6923.498,-23.01042,803.6984,0,0,0,0,100,0),
(@PATH,16,6919.998,-21.26042,802.6984,0,0,0,0,100,0),
(@PATH,17,6914.395,-18.69633,802.4689,0,0,0,0,100,0),
(@PATH,18,6919.895,-21.19633,802.4689,0,0,0,0,100,0),
(@PATH,19,6923.89,-23.39651,803.6684,0,0,0,0,100,0),
(@PATH,20,6925.14,-23.64651,803.6684,0,0,0,0,100,0),
(@PATH,21,6929.89,-24.89651,804.4184,0,0,0,0,100,0);
-- 0x203CD047601D24C0000C1D00000A7995 .go 6932.451 -25.68229 804.7579

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6986.543,`position_y`=-0.593694,`position_z`=810.2161 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6986.543,-0.593694,810.2161,0,0,0,0,100,0),
(@PATH,2,6990.543,-1.343694,809.7161,0,0,0,0,100,0),
(@PATH,3,6992.793,-1.593694,809.9661,0,0,0,0,100,0),
(@PATH,4,6996.293,-1.843694,810.4661,0,0,0,0,100,0),
(@PATH,5,7000.293,-2.343694,809.7161,0,0,0,0,100,0),
(@PATH,6,7001.793,-2.593694,809.4661,0,0,0,0,100,0),
(@PATH,7,6984.833,-0.527235,809.966,0,0,0,0,100,0);
-- 0x203CD047601D24C0000C1D00000B1BE0 .go 6986.543 -0.593694 810.2161

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+19;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6997.178,`position_y`=-13.808,`position_z`=810.0263 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6997.178,-13.808,810.0263,0.77727,11000,0,@SCRIPTID,100,0),
(@PATH,2,6999.178,-14.058,809.5263,0,0,0,0,100,0),
(@PATH,3,7003.928,-12.808,809.0263,0,0,0,0,100,0),
(@PATH,4,7005.873,-12.00844,808.4652,0,0,0,0,100,0),
(@PATH,5,7007.162,-8.437175,807.8546,2.70526,11000,0,@SCRIPTID,100,0),
(@PATH,6,7006.5,-7.468664,808.8807,0,0,0,0,100,0),
(@PATH,7,7004.5,-4.218664,809.6307,0,0,0,0,100,0),
(@PATH,8,7000,-0.7186637,809.8807,0,0,0,0,100,0),
(@PATH,9,6998.008,-1.002355,810.2969,0,0,0,0,100,0),
(@PATH,10,6996.508,-2.752355,810.2969,0,0,0,0,100,0),
(@PATH,11,6991.508,-9.002356,809.7969,0,0,0,0,100,0),
(@PATH,12,6990.349,-10.61985,809.9248,0,0,0,0,100,0),
(@PATH,13,6991.349,-16.17867,809.6908,0,0,0,0,100,0),
(@PATH,14,6995.099,-14.42867,809.6908,0,0,0,0,100,0);
-- 0x203CD047601D24C0000C1D00000B1C0B .go 6997.178 -13.808 810.0263
