-- 
DELETE FROM `event_scripts` WHERE `id`=2313;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(2313, 0, 10, 7411, 3000000, 0, 9639.5,2528.97,1331.72,5.28395);

-- Spirit of Sathrah SAI
SET @ENTRY := 7411;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,0,7411,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Sathrah - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,9,7411,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Sathrah - On Waypoint 9 Reached - Despawn In 3000 ms");

DELETE FROM `waypoints` WHERE `entry`=7411;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(7411, 1, 9642.47,2523.25,1331.54, 'Spirit of Sathrah'),
(7411, 2, 9640.32,2517.43,1331.57, 'Spirit of Sathrah'),
(7411, 3, 9635.62,2514.35,1331.4, 'Spirit of Sathrah'),
(7411, 4, 9630.91,2515.59,1331.72, 'Spirit of Sathrah'),
(7411, 5, 9626.52,2520.1,1331.73, 'Spirit of Sathrah'),
(7411, 6, 9625.02,2526.36,1331.61, 'Spirit of Sathrah'),
(7411, 7, 9630.56,2532.58,1331.39, 'Spirit of Sathrah'),
(7411, 8, 9636.59,2532.65,1331.73, 'Spirit of Sathrah'),
(7411, 9, 9640.05,2529.06,1331.77, 'Spirit of Sathrah');
