-- 
DELETE FROM `waypoint_data` WHERE `id`=1207950;
DELETE FROM `creature_addon` WHERE  `guid`=120795;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=120795;
DELETE FROM `waypoint_scripts` WHERE  `guid`=120795;

-- Refurbished Steam Tank SAI
SET @ENTRY := 29144;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,29144,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,29144,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,2,29144,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,3,29144,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,6,29144,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 6 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,10,29144,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 10 Reached - Pause Waypoint"),
(@ENTRY,0,6,7,40,0,100,0,11,29144,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 11 Reached - Pause Waypoint"),
(@ENTRY,0,7,0,61,0,100,0,11,29144,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 11 Reached - Kill Self"),
(@ENTRY,0,8,0,6,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Just Died - Despawn In 3000 ms");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY, 1, -8463.9, 1109.41, 19.1352, 'Refurbished Steam Tank'),
(@ENTRY, 2, -8463.52, 1112.6, 19.0517, 'Refurbished Steam Tank'),
(@ENTRY, 3, -8463.23, 1108.18, 19.053, 'Refurbished Steam Tank'),
(@ENTRY, 4, -8473.35, 1096.63, 18.7345, 'Refurbished Steam Tank'),
(@ENTRY, 5, -8496.34, 1095.88, 17.9444, 'Refurbished Steam Tank'),
(@ENTRY, 6, -8499.86, 1132.84, 17.9763, 'Refurbished Steam Tank'),
(@ENTRY, 7, -8486, 1138.24, 17.9608, 'Refurbished Steam Tank'),
(@ENTRY, 8, -8462.43, 1136.04, 18.6577, 'Refurbished Steam Tank'),
(@ENTRY, 9, -8440.65, 1137.48, 18.8719, 'Refurbished Steam Tank'),
(@ENTRY, 10, -8412.35, 1137.49, 18.0685, 'Refurbished Steam Tank'),
(@ENTRY, 11, -8412.35, 1137.49, 18.0685, 'Refurbished Steam Tank');
