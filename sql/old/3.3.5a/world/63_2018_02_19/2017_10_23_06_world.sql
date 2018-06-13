--
-- Add missing Darnassian Huntress spawns and waypoints
SET @ENTRY := 16332;
SET @CGUID := 8142; -- Need new GUID
SET @PATHID_1 := @CGUID * 10 + 10;
SET @PATHID_2 := @CGUID * 10 + 40;
SET @PATHID_3 := @CGUID * 10 + 50;
SET @PATHID_4 := 822920;

-- Replace broken old script
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1500,1500,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Huntress - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,4000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Huntress - In Combat CMC - Cast 'Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darnassian Huntress - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Update existing spawn
UPDATE `creature` SET `position_x`=7751.952, `position_y`=-5668.519, `position_z`=3.2572, `orientation`=4.7679, `MovementType`=2 WHERE `guid`=82292;

-- Add six Darnassian Huntresses
DELETE FROM `creature` where `guid` BETWEEN @CGUID + 1 AND @CGUID + 6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID + 1, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7774.547, -5636.031, 17.778, 0.6634, 300, 0, 0, 300, 0, 2, 0, 0, 0, 0),
(@CGUID + 2, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7773.823, -5630.231, 17.635, 2.5365, 300, 0, 0, 300, 0, 0, 0, 0, 0, 0),
(@CGUID + 3, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7763.575, -5621.737, 12.646, 2.2106, 300, 0, 0, 300, 0, 0, 0, 0, 0, 0),
(@CGUID + 4, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7760.331, -5604.991, 6.1089, 3.7932, 300, 0, 0, 300, 0, 2, 0, 0, 0, 0),
(@CGUID + 5, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7758.369, -5602.312, 5.8449, 2.2145, 300, 0, 0, 300, 0, 2, 0, 0, 0, 0),
(@CGUID + 6, @ENTRY, 530, 0, 0, 1, 1, 0, 1, 7745.804, -5595.838, 5.2045, 5.2971, 300, 3, 0, 300, 0, 1, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (82292, @CGUID + 1, @CGUID + 4, @CGUID + 5);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES 
(82292, @PATHID_4, 4907),
(@CGUID + 1, @PATHID_1, 4907),
(@CGUID + 4, @PATHID_2, 4907),
(@CGUID + 5, @PATHID_3, 4907);

-- Add waypoints
DELETE FROM `waypoint_data` WHERE `id` IN (@PATHID_1, @PATHID_2, @PATHID_3, @PATHID_4);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATHID_1, 1, 7780.032, -5630.046, 17.763),
(@PATHID_1, 2, 7781.274, -5623.627, 17.603),
(@PATHID_1, 3, 7779.118, -5620.582, 15.310),
(@PATHID_1, 4, 7775.551, -5621.366, 12.893),
(@PATHID_1, 5, 7771.632, -5620.182, 12.739),
(@PATHID_1, 6, 7761.813, -5626.793, 12.722),
(@PATHID_1, 7, 7762.528, -5631.518, 12.907),
(@PATHID_1, 8, 7760.252, -5634.204, 14.688),
(@PATHID_1, 9, 7762.723, -5637.752, 17.435),
(@PATHID_1, 10, 7769.044, -5639.117, 17.778),
(@PATHID_1, 11, 7774.547, -5636.031, 17.778),
(@PATHID_2, 1, 7748.84, -5613.78, 6.110),
(@PATHID_2, 2, 7735.15, -5624.36, 2.786),
(@PATHID_2, 3, 7726.56, -5630.98, 1.811),
(@PATHID_2, 4, 7726.56, -5630.98, 1.811),
(@PATHID_2, 5, 7735.15, -5624.36, 2.786),
(@PATHID_2, 6, 7748.84, -5613.78, 6.110),
(@PATHID_2, 7, 7760.33, -5604.99, 6.108),
(@PATHID_3, 1, 7742.552, -5581.803, 6.046),
(@PATHID_3, 2, 7737.227, -5576.881, 6.575),
(@PATHID_3, 3, 7729.966, -5574.968, 6.920),
(@PATHID_3, 4, 7730.269, -5582.284, 6.563),
(@PATHID_3, 5, 7733.807, -5588.920, 6.011),
(@PATHID_3, 6, 7748.309, -5609.775, 5.842),
(@PATHID_3, 7, 7758.369, -5602.312, 5.844),
(@PATHID_4, 1, 7755.931, -5703.133, 3.984),
(@PATHID_4, 2, 7731.408, -5733.688, 3.972),
(@PATHID_4, 3, 7697.184, -5732.922, 3.670),
(@PATHID_4, 4, 7696.596, -5753.390, 4.803),
(@PATHID_4, 5, 7672.940, -5753.602, 3.817),
(@PATHID_4, 6, 7696.596, -5753.390, 4.803),
(@PATHID_4, 7, 7697.184, -5732.922, 3.670),
(@PATHID_4, 8, 7731.408, -5733.688, 3.972),
(@PATHID_4, 9, 7755.931, -5703.133, 3.984),
(@PATHID_4, 10, 7751.952, -5668.519, 3.257);
