-- Forsaken Raider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17108;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17108 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17108,0,0,0,0,0,100,0,3000,7000,11000,15000,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Raider - In Combat - Cast Slowing Poison"),
(17108,0,1,0,25,0,100,0,0,0,0,0,11,6718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Raider - On Reset - Cast Phasing Stealth");

-- Forest Moss Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2350 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2350,0,0,0,0,0,100,0,3000,6000,31000,36000,11,3396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Moss Creeper - In Combat - Cast Corrosive Poison");

-- Giant Moss Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2349 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2349,0,0,0,0,0,100,0,3000,6000,31000,36000,11,3396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Moss Creeper - In Combat - Cast Corrosive Poison");

-- Mudsnout Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=2373 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2373,0,1,0,14,0,100,0,400,40,14000,19000,11,11014,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mudsnout Shaman - Friendly At 400 Health - Cast Healing Wave");

-- Mudsnout Gnoll
DELETE FROM `smart_scripts` WHERE `entryorguid`=2372 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2372,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Gnoll - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hillsbrad Councilman
UPDATE `smart_scripts` SET `event_param2`=8, `comment`="Hillsbrad Councilman - Within 0-8 Range - Cast 'Frost Nova'" WHERE `entryorguid`=2387 AND `source_type`=0 AND `id`=2;

-- Magistrate Burnside
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=2335 AND `source_type`=0 AND `id` IN (1,2);

-- Syndicate Shadow Mage
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=2244 AND `source_type`=0 AND `id`=0;

-- Syndicate Watchman
DELETE FROM `smart_scripts` WHERE `entryorguid`=2261 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2261,0,0,0,25,0,100,0,0,0,0,0,11,3582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Watchman - On Reset - Cast Torch Burst"),
(2261,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Watchman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Rogue
DELETE FROM `smart_scripts` WHERE `entryorguid`=2260 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2260,0,0,0,67,0,100,0,6000,8000,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Rogue - On Behind Target - Cast Backstab"),
(2260,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Rogue - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dun Garok Priest
DELETE FROM `smart_scripts` WHERE `entryorguid`=2346 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2346,0,1,0,14,0,100,0,250,40,15000,21000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dun Garok Priest - Friendly At 250 Health - Cast Heal");

-- Remove wrong texts from Jailor Marlgen
DELETE FROM `creature_text` WHERE `CreatureID`=2428;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2428 AND `source_type`=0 AND `id`=0;

-- Random movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (15959,15954,15962,15956,16025,16027);
UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid` IN (15839,15974,90785);

-- Add emote for Hillsbrad Apprentice Blacksmith
UPDATE `creature_addon` SET `emote`=233 WHERE `guid`=15958;

-- Fix bytes2 for Dun Garok Riflemen
UPDATE `creature_addon` SET `bytes2`=2 WHERE `guid` IN (15686,15858,15869,15874,16105,16113,16167,16179,16180,15699,16183);

-- Pooling for Creepthess
SET @GUID := 40492;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14279,0,0,0,1,1,0,0,-747.954,278.299,48.0277,6.23466,72000,15,0,665,0,1,0,0,0,"",0),
(@GUID+1,14279,0,0,0,1,1,0,0,-729.424,-202.325,39.7752,3.78422,72000,15,0,665,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1111;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1111,1,"Creepthess");

DELETE FROM `pool_creature` WHERE `pool_entry`=1111;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1111,0,"Creepthess (14279) - Spawn 1"),
(@GUID+1,1111,0,"Creepthess (14279) - Spawn 2"),
(90785,1111,0,"Creepthess (14279) - Spawn 3");

-- Pooling for Big Samras
SET @GUID := 40494;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1, @GUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14280,0,0,0,1,1,0,0,-636.669,-1651.57,60.7494,0.490619,43200,15,0,665,0,1,0,0,0,"",0),
(@GUID+1,14280,0,0,0,1,1,0,0,-281.772,-1664.94,95.4076,3.78422,43200,15,0,665,0,1,0,0,0,"",0),
(@GUID+2,14280,0,0,0,1,1,0,0,-206.604,-1252.77,114.217,1.35927,43200,15,0,665,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1112;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1112,1,"Big Samras");

DELETE FROM `pool_creature` WHERE `pool_entry`=1112;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1112,0,"Big Samras (14280) - Spawn 1"),
(@GUID+1,1112,0,"Big Samras (14280) - Spawn 2"),
(@GUID+2,1112,0,"Big Samras (14280) - Spawn 3"),
(15839,1112,0,"Big Samras (14280) - Spawn 4");

-- Pathing for Lady Zephris
UPDATE `creature` SET `position_x`=-1276.08, `position_y`=-976, `position_z`=-0.561754, `spawndist`=0, `MovementType`=2 WHERE `guid`=16047;
DELETE FROM `creature_addon` WHERE `guid`=16047;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(16047,160470,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=160470;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(160470,1,-1276.08,-976,-0.561754,0,0,0,0,100,0),
(160470,2,-1258.03,-950.293,1.1057,0,0,0,0,100,0),
(160470,3,-1245.88,-925.964,0.299947,0,0,0,0,100,0),
(160470,4,-1241.09,-902.986,0.176827,0,0,0,0,100,0),
(160470,5,-1216.54,-879.045,-0.012203,0,0,0,0,100,0),
(160470,6,-1204.1,-862.604,-0.022923,0,0,0,0,100,0),
(160470,7,-1177.1,-836.439,0.405907,0,0,0,0,100,0),
(160470,8,-1155.64,-807.945,-0.769681,0,0,0,0,100,0),
(160470,9,-1134.61,-785.771,-0.684184,0,0,0,0,100,0),
(160470,10,-1111.14,-792.039,-0.047394,0,0,0,0,100,0),
(160470,11,-1120.56,-803.641,2.45509,0,0,0,0,100,0),
(160470,12,-1149.99,-814.86,1.4159,0,0,0,0,100,0),
(160470,13,-1170.68,-831.741,0.905636,0,0,0,0,100,0),
(160470,14,-1186.74,-842.143,-0.424433,0,0,0,0,100,0),
(160470,15,-1205.23,-862.842,-0.181762,0,0,0,0,100,0),
(160470,16,-1221.71,-885.192,-0.091555,0,0,0,0,100,0),
(160470,17,-1244.15,-916.463,0.404305,0,0,0,0,100,0),
(160470,18,-1261.29,-949.49,0.631858,0,0,0,0,100,0),
(160470,19,-1277.74,-975.288,-0.7961,0,0,0,0,100,0),
(160470,20,-1290.77,-995.08,-0.895832,0,0,0,0,100,0),
(160470,21,-1313.06,-1004.87,-1.52388,0,0,0,0,100,0),
(160470,22,-1344.6,-1026.51,0.392506,0,0,0,0,100,0),
(160470,23,-1366.78,-1036.92,2.69835,0,0,0,0,100,0),
(160470,24,-1392.12,-1048.81,3.73084,0,0,0,0,100,0),
(160470,25,-1414.89,-1059.5,4.62124,0,0,0,0,100,0),
(160470,26,-1433.06,-1083.33,8.08795,0,0,0,0,100,0),
(160470,27,-1441.77,-1091.69,9.71514,0,0,0,0,100,0),
(160470,28,-1457.46,-1095.82,3.53264,0,0,0,0,100,0),
(160470,29,-1468.13,-1097.07,-1.56115,0,0,0,0,100,0),
(160470,30,-1472.68,-1080.05,-1.56115,0,0,0,0,100,0),
(160470,31,-1458.45,-1062.96,-1.56115,0,0,0,0,100,0),
(160470,32,-1451.28,-1056.44,-1.56115,0,0,0,0,100,0),
(160470,33,-1432.58,-1051.24,-0.703612,0,0,0,0,100,0),
(160470,34,-1409.8,-1040.14,-0.755762,0,0,0,0,100,0),
(160470,35,-1385.61,-1038.06,0.275001,0,0,0,0,100,0),
(160470,36,-1357.3,-1024.25,-0.809856,0,0,0,0,100,0),
(160470,37,-1326.17,-1014.01,-1.29519,0,0,0,0,100,0),
(160470,38,-1303.49,-997.97,-1.23017,0,0,0,0,100,0);

-- Pathing for Scargil
UPDATE `creature` SET `position_x`=-1172.77, `position_y`=123.663, `position_z`=0.157823, `spawndist`=0, `MovementType`=2 WHERE `guid`=15970;
DELETE FROM `creature_addon` WHERE `guid`=15970;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(15970,159700,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=159700;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(159700,1,-1172.77,123.663,0.157823,0,0,0,0,100,0),
(159700,2,-1172.87,118.873,0.322706,0,0,0,0,100,0),
(159700,3,-1164.9,111.492,3.19687,0,0,0,0,100,0),
(159700,4,-1159.58,90.6803,1.9422,0,0,0,0,100,0),
(159700,5,-1152.25,56.6911,0.424014,0,0,0,0,100,0),
(159700,6,-1151.73,33.0373,-0.172392,0,0,0,0,100,0),
(159700,7,-1151.24,14.382,-0.125738,0,0,0,0,100,0),
(159700,8,-1144.4,0.226702,-0.029557,0,0,0,0,100,0),
(159700,9,-1133.86,-10.8596,-0.189161,0,0,0,0,100,0),
(159700,10,-1104.63,-13.0749,0.554654,0,0,0,0,100,0),
(159700,11,-1081.96,-16.5233,1.19604,0,0,0,0,100,0),
(159700,12,-1073.98,-31.1868,0.77585,0,0,0,0,100,0),
(159700,13,-1089.35,-31.3077,-1.07762,0,0,0,0,100,0),
(159700,14,-1115.1,-22.2406,-1.09916,0,0,0,0,100,0),
(159700,15,-1138.02,-7.81281,-0.156224,0,0,0,0,100,0),
(159700,16,-1150.51,10.8034,-0.153825,0,0,0,0,100,0),
(159700,17,-1154.11,26.389,-0.769621,0,0,0,0,100,0),
(159700,18,-1154.74,64.912,0.486252,0,0,0,0,100,0),
(159700,19,-1150.34,95.8842,3.87744,0,0,0,0,100,0),
(159700,20,-1143.77,109.315,7.45656,0,0,0,0,100,0),
(159700,21,-1146.89,127.139,5.36332,0,0,0,0,100,0),
(159700,22,-1163.18,154.262,0.071613,0,0,0,0,100,0),
(159700,23,-1151.92,184.312,0.078821,0,0,0,0,100,0),
(159700,24,-1138.85,210.151,0.64674,0,0,0,0,100,0),
(159700,25,-1120.27,230.815,2.71415,0,0,0,0,100,0),
(159700,26,-1103.25,257.063,3.6444,0,0,0,0,100,0),
(159700,27,-1088.66,273.3,2.29494,0,0,0,0,100,0),
(159700,28,-1067.18,270.992,2.63842,0,0,0,0,100,0),
(159700,29,-1033.01,278.171,0.676006,0,0,0,0,100,0),
(159700,30,-1007.7,280.798,1.6107,0,0,0,0,100,0),
(159700,31,-989.369,301.059,0.846009,0,0,0,0,100,0),
(159700,32,-981.966,323.582,-1.07191,0,0,0,0,100,0),
(159700,33,-975.038,334.123,-1.3281,0,0,0,0,100,0),
(159700,34,-963.251,334.046,2.5684,0,0,0,0,100,0),
(159700,35,-960.338,322.978,6.63507,0,0,0,0,100,0),
(159700,36,-967.984,309.869,5.90922,0,0,0,0,100,0),
(159700,37,-992.889,300.466,0.063592,0,0,0,0,100,0),
(159700,38,-1009.43,291.063,-1.3482,0,0,0,0,100,0),
(159700,39,-1032.87,284.953,-1.52593,0,0,0,0,100,0),
(159700,40,-1049.37,280.662,-0.629822,0,0,0,0,100,0),
(159700,41,-1078.16,282.367,-0.724659,0,0,0,0,100,0),
(159700,42,-1095.26,287.094,-1.10337,0,0,0,0,100,0),
(159700,43,-1105.95,283.475,-0.136028,0,0,0,0,100,0),
(159700,44,-1117.02,277.427,-0.169369,0,0,0,0,100,0),
(159700,45,-1121.42,258.795,0.527346,0,0,0,0,100,0),
(159700,46,-1130.18,237.408,-0.735995,0,0,0,0,100,0),
(159700,47,-1142.05,208.455,-0.004859,0,0,0,0,100,0),
(159700,48,-1155.78,174.963,-0.17143,0,0,0,0,100,0),
(159700,49,-1163.85,152.053,0.127761,0,0,0,0,100,0),
(159700,50,-1169.17,136.967,0.156267,0,0,0,0,100,0);

-- Pathing for Tamra Stormpike
UPDATE `creature` SET `position_x`=-1316.82, `position_y`=-1212.59, `position_z`=49.9032, `spawndist`=0, `MovementType`=2 WHERE `guid`=90783;
DELETE FROM `creature_addon` WHERE `guid`=90783;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(90783,907830,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=907830;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(907830,1,-1316.82,-1212.59,49.9032,0,0,0,0,100,0),
(907830,2,-1353.08,-1242.71,49.9048,0,0,0,0,100,0),
(907830,3,-1357.06,-1248.49,49.9033,0,0,0,0,100,0),
(907830,4,-1329.89,-1278.96,49.9017,0,0,0,0,100,0),
(907830,5,-1289.34,-1243.49,49.9032,0,0,0,0,100,0),
(907830,6,-1331.07,-1278.83,49.9017,0,0,0,0,100,0),
(907830,7,-1357.24,-1246.72,49.9025,0,0,0,0,100,0),
(907830,8,-1334.4,-1227.01,49.9047,0,0,0,0,100,0);
