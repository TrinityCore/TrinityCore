-- Positions
UPDATE `creature` SET `position_x` = 143.049, `position_y` = 192.726, `position_z` = -11.2147, `orientation` = 3.40339, `VerifiedBuild` = 15595 WHERE `guid` = 7483 AND `id` = 18831;
UPDATE `creature` SET `position_x` = 149.823, `position_y` = 178.019, `position_z` = -10.5928, `orientation` = 3.10669, `VerifiedBuild` = 15595 WHERE `guid` = 81651 AND `id` = 18832;
UPDATE `creature` SET `position_x` = 146.521, `position_y` = 185.358, `position_z` = -10.8378, `orientation` = 3.22886, `VerifiedBuild` = 15595 WHERE `guid` = 81652 AND `id` = 18834;
UPDATE `creature` SET `position_x` = 145.96, `position_y` = 207.296, `position_z` = -8.6713, `orientation` = 3.57792, `VerifiedBuild` = 15595 WHERE `guid` = 81643 AND `id` = 18835;
UPDATE `creature` SET `position_x` = 144.731, `position_y` = 199.921, `position_z` = -9.97698, `orientation` = 3.47321, `VerifiedBuild` = 15595 WHERE `guid` = 48348 AND `id` = 18836;
UPDATE `creature` SET `position_x` = 237.403, `position_y` = 357.981, `position_z` = -3.40797, `orientation` = 3.14159, `VerifiedBuild` = 15595 WHERE `guid` = 81644 AND `id` = 19044;

UPDATE `creature` SET `position_x` = 65.5642, `position_y` = 130.827, `position_z` = -6.12329, `orientation` = 6.16101, `VerifiedBuild` = 15595 WHERE `guid` = 81646 AND `id` = 21350;
UPDATE `creature` SET `position_x` = 77.751, `position_y` = 130.134, `position_z` = -7.05176, `orientation` = 2.93215, `VerifiedBuild` = 15595 WHERE `guid` = 81645 AND `id` = 21350;
UPDATE `creature` SET `position_x` = 107.871, `position_y` = 282.512, `position_z` = 1.97182, `orientation` = 2.9147, `VerifiedBuild` = 15595 WHERE `guid` = 69871 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 96.3461, `position_y` = 282.478, `position_z` = 2.28934, `orientation` = 0.0174533, `VerifiedBuild` = 15595 WHERE `guid` = 72432 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 102.204, `position_y` = 325.543, `position_z` = 1.53778, `orientation` = 1.06465, `VerifiedBuild` = 15595 WHERE `guid` = 83206 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 107.682, `position_y` = 333.561, `position_z` = 2.02375, `orientation` = 4.24115, `VerifiedBuild` = 15595 WHERE `guid` = 65618 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 178.218, `position_y` = 360.483, `position_z` = -1.0015, `orientation` = 3.10669, `VerifiedBuild` = 15595 WHERE `guid` = 81650 AND `id` = 21350;
UPDATE `creature` SET `position_x` = 178.741, `position_y` = 367.175, `position_z` = -0.286067, `orientation` = 3.22886, `VerifiedBuild` = 15595 WHERE `guid` = 81648 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 178.031, `position_y` = 373.566, `position_z` = 0.628656, `orientation` = 3.35103, `VerifiedBuild` = 15595 WHERE `guid` = 81649 AND `id` = 21350;

-- Waypoints
UPDATE `creature` SET `position_x` = 109.243, `position_y` = 317.835, `position_z` = 1.5722027, `orientation` = 1.780235767364501953 WHERE `guid` = 81647 AND `id` = 21350;
UPDATE `creature` SET `position_x` = 110.84852, `position_y` = 322.73474, `position_z` = 1.7697936, `orientation` = 2.635447263717651367 WHERE `guid` = 86065 AND `id` = 19389;
UPDATE `creature` SET `position_x` = 66.57837, `position_y` = 93.9671, `position_z` = -5.0328717, `orientation` = 1.38982 WHERE `guid` = 81642 AND `id` = 19389;

DELETE FROM `waypoint_data` WHERE `id` IN (816470,860650,816420);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
-- Too short sniff, maybe there are more different delays, quite possible they're random. Anyway all should be sniffed again
(816470,1,109.243,317.835,1.5722027,1.780235767364501953,45000,0,0,0,0),
(816470,2,103.174,288.091,1.2337822,0,35000,0,0,0,0),
(816470,3,109.243,317.835,1.5722027,1.780235767364501953,55000,0,0,0,0),
(816470,4,103.174,288.091,1.2337822,0,35000,0,0,0,0),
(816470,5,109.243,317.835,1.5722027,1.780235767364501953,60000,0,0,0,0),
(816470,6,103.174,288.091,1.2337822,0,35000,0,0,0,0),
(860650,1,110.84852,322.73474,1.7697936,2.635447263717651367,40000,0,0,0,0),
(860650,2,114.52596,332.3754,2.6824906,0,0,0,0,0,0),
(860650,3,120.59276,352.0573,5.4062705,0,0,0,0,0,0),
(860650,4,144.23323,365.1607,3.8937109,0,0,0,0,0,0),
(860650,5,170.33693,367.4104,1.0497984,0,30000,0,0,0,0),
(860650,6,162.34904,367.0106,2.1333566,0,0,0,0,0,0),
(860650,7,132.46819,362.64624,6.336301,0,0,0,0,0,0),
(860650,8,117.73458,344.41876,4.624224,0,0,0,0,0,0),
(816420,1,66.57837,93.9671,-5.0328717,0,0,0,0,0,0),
(816420,2,70.51746,115.49409,-6.29502,0,0,0,0,0,0),
(816420,3,75.322044,137.46254,-8.535737,0,0,0,0,0,0),
(816420,4,90.887764,154.45749,-12.043716,0,35000,0,0,0,0),
(816420,5,78.73197,141.4726,-8.55019,0,0,0,0,0,0),
(816420,6,68.1937,120.67173,-6.3062334,0,0,0,0,0,0),
(816420,7,66.57837,93.9671,-5.0328717,0,35000,0,0,0,0);

-- Addons
DELETE FROM `creature_addon` WHERE `guid` IN (81650,81648,81649,83206,65618);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(81650,0,0,0,1,375,3,""),
(81648,0,0,0,1,375,3,""),
(81649,0,0,0,1,375,3,""),
(83206,0,0,1,1,0,3,""),
(65618,0,0,1,1,0,3,"");

UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (18831,18832,18834,18835,18836,19044,19389,21350,18847);

-- Stats, immunities - CMaNGOS
UPDATE `creature_model_info` SET `BoundingRadius` = 1.041, `CombatReach` = 4.5 WHERE `DisplayID` = 7972;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64 WHERE `entry` = 18831; -- High King Maulgar
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64 WHERE `entry` = 18832; -- Krosh Firehand
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64 WHERE `entry` = 18834; -- Olm the Summoner
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64 WHERE `entry` = 18835; -- Kiggler the Crazed
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64 WHERE `entry` = 18836; -- Blindeye the Seer
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64, `mechanic_immune_mask` = 12584976 WHERE `entry` = 18847; -- Wild Fel Stalker
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.57142857143 WHERE `entry` = 19044; -- Gruul the Dragonkiller
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 19198; -- Invisible Tractor Beam Source
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64, `mechanic_immune_mask` = 652951551 WHERE `entry` = 19389; -- Lair Brute
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429, `unit_flags` = 64, `mechanic_immune_mask` = 619397119 WHERE `entry` = 21350; -- Gronn-Priest

-- Scripts
-- Lair Brute SAI
-- I checked them in retail in MoP but looks like I put maximum effort only for CallForHelp thing(even checked if they can pull Gruul)
SET @ID := 19389;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- 58460 in Cata
(@ID,0,0,0,0,0,100,0,8000,10000,9000,12000,0,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast 'Mortal Strike'"),
(@ID,0,1,0,0,0,100,0,6000,10000,6000,10000,0,11,39174,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast 'Cleave'"),
(@ID,0,2,3,0,0,100,0,10000,20000,20000,30000,0,11,24193,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast 'Charge'"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lair Brute - On Link - Set All Threat 0-100"),
(@ID,0,4,0,2,0,100,1,0,15,0,0,0,39,65,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lair Brute - Between 0-15% Health - Call for Help (No Repeat)"),
(@ID,0,5,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lair Brute - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s lets out a massive roar, calling for aid!",16,0,100,0,0,0,2441,0,"Lair Brute");

-- Gronn-Priest SAI
SET @ID := 21350;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,9000,12000,20000,25000,0,11,22884,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gronn-Priest - In Combat - Cast 'Psychic Scream'"),
(@ID,0,1,0,74,0,100,0,0,50,18000,22000,100,11,36678,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gronn Priest - On Friendly Between 0-50% Health - Cast 'Heal'"),
(@ID,0,2,0,74,0,100,0,0,40,18000,22000,100,11,36679,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gronn Priest - On Friendly Between 0-40% Health - Cast 'Renew'"),
(@ID,0,3,0,2,0,100,1,0,15,0,0,0,39,65,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gronn-Priest - Between 0-15% Health - Call for Help (No Repeat)"),
(@ID,0,4,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gronn-Priest - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s lets out a massive roar, calling for aid!",16,0,100,0,0,0,2441,0,"Gronn-Priest");

-- Wild Fel Stalker SAI
SET @ID := 18847;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wild Fel Stalker - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,10000,15000,10000,15000,0,11,33086,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Wild Fel Stalker - In Combat - Cast 'Wild Bite'");

-- Objects
UPDATE `gameobject_template_addon` SET `faction` = 1375, `flags` = 32 WHERE `entry` IN (183817,184662);
UPDATE `gameobject` SET `position_x` = 166.897, `position_y` = 368.226, `position_z` = 16.9209, `orientation` = 4.71239, `rotation2` = -0.707107, `rotation3` = 0.707107, `spawntimesecs` = 300, `animprogress` = 255, `VerifiedBuild` = 15595 WHERE `guid` = 50479 AND `id` = 184662;
UPDATE `gameobject` SET `position_x` = 99.0729, `position_y` = 249.704, `position_z` = 18.3478, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `spawntimesecs` = 300, `animprogress` = 255, `VerifiedBuild` = 15595, `id` = 183817 WHERE `guid` = 12443 AND `id` = 184468;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0.00000004371138828 WHERE `guid` IN (12443,50479);
