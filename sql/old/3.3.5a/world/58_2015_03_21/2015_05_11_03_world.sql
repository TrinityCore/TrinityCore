-- DB/Quest: Assault by Air (H)
DELETE FROM `creature` WHERE `id`=32225;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(16398, 32225, 571, 1, 1, 0, 0, 7303.23, 1520.81, 323.2961, 1.53589, 300, 0, 0, 63000, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `spell1`=59880 WHERE `entry`=32227;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=32225;
UPDATE `creature_template` SET `speed_run`=3 WHERE  `entry`=32225;
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE  `entry`=32225 AND `seat_id`=0;

DELETE FROM `waypoints` WHERE `entry`=32225;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(32225, 1, 7224.952, 1493.076, 355.6927, 'Skybreaker Troop Transport'),
(32225, 2, 7158.104, 1468.994, 408.7451, 'Skybreaker Troop Transport'),
(32225, 3, 7091.476, 1447.724, 454.6882, 'Skybreaker Troop Transport'),
(32225, 4, 6959.782, 1423.015, 558.3835, 'Skybreaker Troop Transport'),
(32225, 5, 6779.104, 1463.505, 646.3554, 'Skybreaker Troop Transport'),
(32225, 6, 6655.649, 1608.774, 709.994, 'Skybreaker Troop Transport'),
(32225, 7, 6624.22, 1736.658, 728.0214, 'Skybreaker Troop Transport'),
(32225, 8, 6669.947, 1866.185, 709.688, 'Skybreaker Troop Transport'),
(32225, 9, 6718.041, 1885.129, 690.6326, 'Skybreaker Troop Transport'),
(32225, 10, 6795.828, 1838.745, 659.0216, 'Skybreaker Troop Transport'),
(32225, 11, 6829.202, 1723.054, 616.9384, 'Skybreaker Troop Transport'),
(32225, 12, 6938.554, 1702.879, 585.9383, 'Skybreaker Troop Transport'),
(32225, 13, 7024.898, 1752.804, 565.5496, 'Skybreaker Troop Transport'),
(32225, 14, 7113.707, 1734.315, 556.3559, 'Skybreaker Troop Transport'),
(32225, 15, 7265.8, 1765.196, 556.3559, 'Skybreaker Troop Transport'),
(32225, 16, 7302.899, 1853.759, 575.8558, 'Skybreaker Troop Transport'),
(32225, 17, 7312.44, 1944.328, 581.4116, 'Skybreaker Troop Transport'),
(32225, 18, 7307.329, 2014.243, 581.4116, 'Skybreaker Troop Transport'),
(32225, 19, 7253.363, 2115.422, 583.3, 'Skybreaker Troop Transport'),
(32225, 20, 7193.522, 2155.816, 607.7997, 'Skybreaker Troop Transport'),
(32225, 21, 7128.84, 2168.484, 642.6707, 'Skybreaker Troop Transport'),
(32225, 22, 7069.121, 2157.589, 689.7963, 'Skybreaker Troop Transport'),
(32225, 23, 7024.457, 2135.705, 708.6849, 'Skybreaker Troop Transport'),
(32225, 24, 6934.063, 2183.969, 750.9397, 'Skybreaker Troop Transport'),
(32225, 25, 6941.725, 2249.074, 754.6065, 'Skybreaker Troop Transport'),
(32225, 26, 7072.678, 2295.607, 714.44, 'Skybreaker Troop Transport'),
(32225, 27, 7260.946, 2257.761, 639.7736, 'Skybreaker Troop Transport'),
(32225, 28, 7419.038, 2123.693, 587.7736, 'Skybreaker Troop Transport'),
(32225, 29, 7471.735, 1962.737, 559.6346, 'Skybreaker Troop Transport'),
(32225, 30, 7436.465, 1818.688, 508.0233, 'Skybreaker Troop Transport'),
(32225, 31, 7366.372, 1694.51, 469.3012, 'Skybreaker Troop Transport'),
(32225, 32, 7329.872, 1609.157, 432.2737, 'Skybreaker Troop Transport'),
(32225, 33, 7296.424, 1556.42, 417.7181, 'Skybreaker Troop Transport'),
(32225, 34, 7272.382, 1525.835, 411.4405, 'Skybreaker Troop Transport');

-- Skybreaker Suppression Turret SAI
SET @ENTRY := 32227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,45,1,0,0,0,0,0,19,32225,10,0,0,0,0,0,"Skybreaker Suppression Turret - On Passenger Boarded - Set Data 1 0");

-- Skybreaker Troop Transport SAI
SET @ENTRY := 32225;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Data Set 1 0 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,9,32225,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 11 Reached - Cast 'Eject Passenger 3'"),
(@ENTRY,0,2,0,40,0,100,0,13,32225,0,0,11,64614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 16 Reached - Cast 'Eject Passenger 4'"),
(@ENTRY,0,3,0,40,0,100,0,17,32225,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 19 Reached - Cast 'Eject Passenger 5'"),
(@ENTRY,0,4,0,40,0,100,0,22,32225,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 22 Reached - Cast 'Eject Passenger 6'"),
(@ENTRY,0,5,0,40,0,100,0,34,32225,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 32 Reached - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 3222500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,53,1,32225,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Start Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Reactstate Passive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Flag Pacified"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Health Regeneration Off");

-- Skybreaker Infiltrator SAI
SET @ENTRY := 32222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,1,46598,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Has Aura 'Ride Vehicle Hardcoded' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3222200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,60208,0,0,0,0,0,21,20,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Cast 'Ally Air Dropoff Kill Credit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,11,45472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Cast 'Parachute'"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=32222;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(32222, 0, 0, 'I''ll kill one just for you.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32532),
(32222, 0, 1, 'Dropping. Good luck, boys!', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32526),
(32222, 0, 2, 'Thanks for the cover!', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32527),
(32222, 0, 3, 'Destination reached - engaging in scouting mission.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32528),
(32222, 0, 4, 'Infiltration commencing.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32529);

-- Ymirheim Spear Gun SAI
SET @ENTRY := 31280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,32225,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,1,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,32225,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,2,3,8,0,100,0,59880,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Set Event Phase 2"),
(@ENTRY,0,3,0,61,0,100,0,59880,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Run Script"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Reset - Set Event Phase 1");

-- Actionlist SAI
SET @ENTRY := 3128000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,15000,15000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=32227 AND `SourceEntry`=46598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 32227, 46598, 0, 0, 9, 0, 13309, 0, 0, 0, 0, 0, '', 'Required quest ''Assault by Ait'' active for spellclick');


-- DB/Quest: Assault by Air (A)
UPDATE `creature_template` SET `spell1`=59880 WHERE `entry`=31884;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=125330;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=31881;
UPDATE `creature_template` SET `speed_run`=3 WHERE  `entry`=31881;
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE  `entry`=31881 AND `seat_id`=0;

DELETE FROM `waypoints` WHERE `entry`=31881;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(31881, 1, 7513.354, 1781.131, 381.561, 'Kor\'kron Troop Transport'),
(31881, 2, 7508.576, 1843.856, 445.5052, 'Kor\'kron Troop Transport'),
(31881, 3, 7496.634, 1890.942, 496.6479, 'Kor\'kron Troop Transport'),
(31881, 4, 7451.161, 1990.051, 581.2389, 'Kor\'kron Troop Transport'),
(31881, 5, 7372.757, 2143.088, 590.3499, 'Kor\'kron Troop Transport'),
(31881, 6, 7293.971, 2233.48, 602.4611, 'Kor\'kron Troop Transport'),
(31881, 7, 7117.833, 2278.535, 605.0721, 'Kor\'kron Troop Transport'),
(31881, 8, 7017.111, 2263.003, 647.082, 'Kor\'kron Troop Transport'),
(31881, 9, 6996.222, 2205.772, 679.2115, 'Kor\'kron Troop Transport'),
(31881, 10, 7061.963, 2173.603, 675.7964, 'Kor\'kron Troop Transport'),
(31881, 11, 7121.235, 2156.643, 656.629, 'Kor\'kron Troop Transport'),
(31881, 12, 7217.851, 2134.94, 612.4905, 'Kor\'kron Troop Transport'),
(31881, 13, 7288.108, 2086.021, 596.8795, 'Kor\'kron Troop Transport'),
(31881, 14, 7327.417, 1958.794, 585.9348, 'Kor\'kron Troop Transport'),
(31881, 15, 7298.545, 1875.991, 585.4906, 'Kor\'kron Troop Transport'),
(31881, 16, 7249.319, 1800.969, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 17, 7157.543, 1745.975, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 18, 7067.531, 1718.656, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 19, 6988.929, 1710.539, 589.5177, 'Kor\'kron Troop Transport'),
(31881, 20, 6858.088, 1715.7, 617.0735, 'Kor\'kron Troop Transport'),
(31881, 21, 6789.24, 1811.618, 658.2943, 'Kor\'kron Troop Transport'),
(31881, 22, 6741.477, 1881.004, 687.6509, 'Kor\'kron Troop Transport'),
(31881, 23, 6687.517, 1859.595, 701.3486, 'Kor\'kron Troop Transport'),
(31881, 24, 6683.648, 1766.575, 692.5154, 'Kor\'kron Troop Transport'),
(31881, 25, 6738.948, 1709.63, 686.7657, 'Kor\'kron Troop Transport'),
(31881, 26, 6906.804, 1642.973, 664.1547, 'Kor\'kron Troop Transport'),
(31881, 27, 7009.317, 1640.16, 631.8771, 'Kor\'kron Troop Transport'),
(31881, 28, 7174.014, 1608.189, 554.7385, 'Kor\'kron Troop Transport'),
(31881, 29, 7328.232, 1587.251,  465.3495, 'Kor\'kron Troop Transport'),
(31881, 30, 7449.845, 1582.211, 415.2385, 'Kor\'kron Troop Transport'),
(31881, 31, 7493.209, 1659.839, 383.9886, 'Kor\'kron Troop Transport'),
(31881, 32, 7508.813, 1745.664, 371.2109, 'Kor\'kron Troop Transport');

-- Kor'kron Suppression Turret SAI
SET @ENTRY := 31884;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,45,1,0,0,0,0,0,19,31881,10,0,0,0,0,0,"Kor'kron Suppression Turret - On Passenger Boarded - Set Data 1 0");

-- Kor'kron Troop Transport SAI
SET @ENTRY := 31881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,0,0,0,80,3188100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Data Set 1 0 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,11,31881,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger3'"),
(@ENTRY,0,2,0,40,0,100,0,16,31881,0,0,11,64614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger4'"),
(@ENTRY,0,3,0,40,0,100,0,19,31881,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger5'"),
(@ENTRY,0,4,0,40,0,100,0,22,31881,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger6'"),
(@ENTRY,0,5,0,40,0,100,0,32,31881,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 32 Reached - Despawn");

-- Actionlist SAI
SET @ENTRY := 3188100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,53,1,31881,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Start Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Reactstate Passive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Flag Pacified"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Health Regeneration Off");

-- Kor'kron Infiltrator SAI
SET @ENTRY := 31882;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,1,46598,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Has Aura 'Ride Vehicle Hardcoded' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3188200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,59977,0,0,0,0,0,21,20,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Cast 'Horde Air Dropoff Kill Credit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,11,45472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Cast 'Parachute'"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=31882;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(31882, 0, 0, 'I''ll kill one just for you.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32532),
(31882, 0, 1, 'Dropping. Good luck, boys!', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32526),
(31882, 0, 2, 'Thanks for the cover!', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32527),
(31882, 0, 3, 'Destination reached - engaging in scouting mission.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32528),
(31882, 0, 4, 'Infiltration commencing.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32529);

-- Ymirheim Spear Gun SAI
SET @ENTRY := 31280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,31881,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,1,2,8,0,100,0,59880,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Set Event Phase 2"),
(@ENTRY,0,2,0,61,0,100,0,59880,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Run Script"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Reset - Set Event Phase 1");

-- Actionlist SAI
SET @ENTRY := 3128000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,15000,15000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31884 AND `SourceEntry`=46598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 31884, 46598, 0, 0, 9, 0, 13310, 0, 0, 0, 0, 0, '', 'Required quest ''Assault by Ait'' active for spellclick');
