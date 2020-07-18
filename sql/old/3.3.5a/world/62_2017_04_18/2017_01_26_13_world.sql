-- [NPC][WotlK] Stormforged Taskmaster, missing speech + spawns
SET @CGUID := 74020;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 29384, 571, 0, 0, 1, 1, 24119, 1, 7764.507, -73.30479, 876.4452, 3.996804, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: -Unknown-)
(@CGUID+1, 29384, 571, 0, 0, 1, 1, 24119, 1, 7756.334, -66.37359, 875.0351, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: -Unknown-)
(@CGUID+2, 29384, 571, 0, 0, 1, 1, 24119, 1, 7794.047, -60.66504, 880.9378, 5.794493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+3, 29384, 571, 0, 0, 1, 1, 24119, 1, 7771.401, -65.84267, 876.7804, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+4, 29384, 571, 0, 0, 1, 1, 24119, 1, 7779.678, -71.71181, 877.9554, 5.340707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+5, 29384, 571, 0, 0, 1, 1, 24119, 1, 7822.476, -76.57845, 882.7716,2.984513, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+6, 29384, 571, 0, 0, 1, 1, 24119, 1, 7828.539, -87.213, 882.2543, 0.1047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+7, 29384, 571, 0, 0, 1, 1, 24119, 1, 7794.343, -48.1097, 881.7289, 3.577925, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+8, 29384, 571, 0, 0, 1, 1, 24119, 1, 7827.557, -65.01367, 882.1137, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Captive Mechagnome (Area: Snowdrift Plains)
(@CGUID+9, 29384, 571, 0, 0, 1, 1, 24119, 1, 7743.003, -25.28744, 867.4526, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Captive Mechagnome (Area: The Frozen Mine)

SET @OGUID := 7338;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,`position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 192058, 571, 0, 0, 1, 1, 7760.876, -69.60856, 875.7332, 2.094393, 0, 0, 0.866025, 0.5000008, 120, 255, 1, 23360), -- Ore Cart (Area: -Unknown-)
(@OGUID+1, 192058, 571, 0, 0, 1, 1, 7839.519, -114.0295, 882.8144, 4.852017, 0, 0, -0.6560583, 0.7547102, 120, 255, 1, 23360), -- Ore Cart (Area: Snowdrift Plains)
(@OGUID+2, 192058, 571, 0, 0, 1, 1, 7776.323, -73.01736, 877.5671, 0.9599299, 0, 0, 0.4617481, 0.8870111, 120, 255, 1, 23360), -- Ore Cart (Area: Snowdrift Plains)
(@OGUID+3, 192058, 571, 0, 0, 1, 1, 7810.222, -91.17882, 879.3587, 1.902409, 0, 0, 0.8141155, 0.580703, 120, 255, 1, 23360), -- Ore Cart (Area: Snowdrift Plains)
(@OGUID+4, 192058, 571, 0, 0, 1, 1, 7824.928, -74.9356, 882.8175, 0.2792516, 0, 0, 0.1391726, 0.9902682, 120, 255, 1, 23360), -- Ore Cart (Area: Snowdrift Plains)
(@OGUID+5, 192058, 571, 0, 0, 1, 1, 7840.633, -73.57677, 880.7795, 1.797689, 0, 0, 0.782608, 0.6225148, 120, 255, 1, 23360); -- Ore Cart (Area: Snowdrift Plains)

-- Stormforged Taskmaster SAI
SET @GUID := -63373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936900,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Stormforged Taskmaster SAI
SET @GUID := -63374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936901,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Stormforged Taskmaster SAI
SET @GUID := -113453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936902,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Stormforged Taskmaster SAI
SET @GUID := -113454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936903,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Stormforged Taskmaster SAI
SET @GUID := -113455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936904,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Stormforged Taskmaster SAI
SET @GUID := -113456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Lightning Charged'"),
(@GUID,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 'Stormstrike'"),
(@GUID,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0 (No Repeat)"),
(@GUID,0,3,0,1,0,100,0,2000,3000,40000,45000,80,2936900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - Out of Combat - Run Script"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,53,0,2936905,1,0,0,2,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Reset - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 2936900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,100,100,0,0,66,0,0,0,0,0,0,19,29384,20,0,0,0,0,0,"On Script - Set Orientation Closest Creature 'Captive Mechagnome'"),
(@ENTRY,9,2,0,0,0,100,0,900,900,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `entry`=29369 AND `groupid`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(29369, 1, 0, 'You''re not worth the scrap you''re made from!', 12, 0, 100, 25, 0, 0, 30237, 'Stormforged Taskmaster'),
(29369, 1, 1, 'Your tinker must''ve made you from tin, you lazy piles of slag!', 12, 0, 100, 25, 0, 0, 30235, 'Stormforged Taskmaster'),
(29369, 1, 2, 'A pack of mechanical squirrels could mine faster than you!', 12, 0, 100, 25, 0, 0, 30233, 'Stormforged Taskmaster');

UPDATE `creature` SET `MovementType`=0 WHERE  `guid` IN (63373,63374,113453,113454,113455,113456);
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid` IN (63373,63374,113453,113454,113455,113456);
DELETE FROM `waypoint_data` WHERE `id` IN (633730,633740,1134530,1134540,1134550,1134560);

DELETE FROM `waypoints` WHERE `entry` IN (2936900, 2936901, 2936902, 2936903, 2936904, 2936905);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2936900, 1, 7842.54, -110.646, 882.807, 'Stormforged Taskmaster'),
(2936900, 2, 7839.24, -106.356, 882.685, 'Stormforged Taskmaster'),
(2936900, 3, 7833.71, -100.741, 881.317, 'Stormforged Taskmaster'),
(2936900, 4, 7827.77, -96.5826, 881.028, 'Stormforged Taskmaster'),
(2936900, 5, 7822.92, -90.5375, 880.513, 'Stormforged Taskmaster'),
(2936900, 6, 7822.85, -83.7952, 881.53, 'Stormforged Taskmaster'),
(2936900, 7, 7822.92, -90.488, 880.509, 'Stormforged Taskmaster'),
(2936900, 8, 7827.69, -96.49, 881.013, 'Stormforged Taskmaster'),
(2936900, 9, 7833.71, -100.741, 881.317, 'Stormforged Taskmaster'),
(2936900, 10, 7839.1, -106.212, 882.604, 'Stormforged Taskmaster'),
-- 1
(2936901, 1, 7827.68, -77.0993, 882.731, 'Stormforged Taskmaster'),
(2936901, 2, 7824.65, -79.7332, 882.546, 'Stormforged Taskmaster'),
(2936901, 3, 7827.68, -77.0993, 882.731, 'Stormforged Taskmaster'),
(2936901, 4, 7832.38, -77.6355, 881.928, 'Stormforged Taskmaster'),
(2936901, 5, 7837.4, -75.3101, 880.054, 'Stormforged Taskmaster'),
(2936901, 6, 7832.38, -77.6355, 881.928, 'Stormforged Taskmaster'),
-- 2
(2936902, 1, 7831.41, -36.4311, 881.704, 'Stormforged Taskmaster'),
(2936902, 2, 7825.86, -41.5228, 882.661, 'Stormforged Taskmaster'),
(2936902, 3, 7825.45, -46.9974, 881.745, 'Stormforged Taskmaster'),
(2936902, 4, 7825.43, -52.6922, 881.685, 'Stormforged Taskmaster'),
(2936902, 5, 7829.17, -59.9388, 881.891, 'Stormforged Taskmaster'),
(2936902, 6, 7830.55, -64.6877, 881.66, 'Stormforged Taskmaster'),
(2936902, 7, 7829.18, -59.9475, 881.894, 'Stormforged Taskmaster'),
(2936902, 8, 7825.43, -52.6922, 881.685, 'Stormforged Taskmaster'),
(2936902, 9, 7825.45, -46.9974, 881.745, 'Stormforged Taskmaster'),
(2936902, 10, 7825.86, -41.5228, 882.661, 'Stormforged Taskmaster'),
(2936902, 11, 7831.41, -36.4311, 881.704, 'Stormforged Taskmaster'),
(2936902, 12, 7834.93, -35.8157, 881.031, 'Stormforged Taskmaster'),
-- 3
(2936903, 1, 7806.82, -50.189, 883.404, 'Stormforged Taskmaster'),
(2936903, 2, 7810.62, -51.103, 883.561, 'Stormforged Taskmaster'),
(2936903, 3, 7814.73, -51.1784, 883.116, 'Stormforged Taskmaster'),
(2936903, 4, 7818.9, -50.9843, 882.591, 'Stormforged Taskmaster'),
(2936903, 5, 7814.93, -51.182, 883.094, 'Stormforged Taskmaster'),
(2936903, 6, 7810.62, -51.103, 883.561, 'Stormforged Taskmaster'),
(2936903, 7, 7806.82, -50.189, 883.404, 'Stormforged Taskmaster'),
(2936903, 8, 7802.53, -48.5442, 883.128, 'Stormforged Taskmaster'),
(2936903, 9, 7796.82, -50.1725, 882.255, 'Stormforged Taskmaster'),
(2936903, 10, 7802.53, -48.5442, 883.128, 'Stormforged Taskmaster'),
-- 4
(2936904, 1, 7755.48, -0.0631561, 865.862, 'Stormforged Taskmaster'),
(2936904, 2, 7761.08, 1.82399, 865.304, 'Stormforged Taskmaster'),
(2936904, 3, 7766.31, -2.84863, 864.675, 'Stormforged Taskmaster'),
(2936904, 4, 7771.37, -8.78397, 863.862, 'Stormforged Taskmaster'),
(2936904, 5, 7776.65, -11.9133, 863.228, 'Stormforged Taskmaster'),
(2936904, 6, 7771.37, -8.78397, 863.862, 'Stormforged Taskmaster'),
(2936904, 7, 7766.31, -2.84863, 864.675, 'Stormforged Taskmaster'),
(2936904, 8, 7761.08, 1.82399, 865.304, 'Stormforged Taskmaster'),
(2936904, 9, 7755.48, -0.0631561, 865.862, 'Stormforged Taskmaster'),
(2936904, 10, 7747.01, -1.09679, 865.626, 'Stormforged Taskmaster'),
(2936904, 11, 7738.89, -1.10406, 866.172, 'Stormforged Taskmaster'),
(2936904, 12, 7732.29, 0.640083, 866.125, 'Stormforged Taskmaster'),
(2936904, 13, 7726.06, 0.671768, 867.406, 'Stormforged Taskmaster'),
(2936904, 14, 7732.29, 0.640083, 866.125, 'Stormforged Taskmaster'),
(2936904, 15, 7738.89, -1.10406, 866.172, 'Stormforged Taskmaster'),
(2936904, 16, 7747.01, -1.09679, 865.626, 'Stormforged Taskmaster'),
-- 5
(2936905, 1, 7741.84, -35.6213, 868.321, 'Stormforged Taskmaster'),
(2936905, 2, 7742.5, -41.7692, 868.102, 'Stormforged Taskmaster'),
(2936905, 3, 7745.92, -49.207, 869.457, 'Stormforged Taskmaster'),
(2936905, 4, 7748.48, -53.6265, 870.862, 'Stormforged Taskmaster'),
(2936905, 5, 7745.92, -49.207, 869.457, 'Stormforged Taskmaster'),
(2936905, 6, 7742.51, -41.7868, 868.101, 'Stormforged Taskmaster'),
(2936905, 7, 7741.92, -36.0035, 868.283, 'Stormforged Taskmaster'),
(2936905, 8, 7736.81, -27.0224, 867.023, 'Stormforged Taskmaster'),
(2936905, 9, 7730.21, -23.2195, 867.558, 'Stormforged Taskmaster'),
(2936905, 10, 7736.81, -27.0224, 867.023, 'Stormforged Taskmaster');
