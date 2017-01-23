-- Bildine -- http://wotlk.openwow.com/npc=16757
UPDATE `creature` SET `position_x` = -3697.55, `position_y` = -11479.4, `position_z` = -119.491, `orientation` = 1.77213, `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 57747;
UPDATE `creature_template_addon` SET `emote` = 0 WHERE `Entry` = 16757;
UPDATE `creature_template` SET `MovementType` = 0 WHERE `Entry` = 16757;
-- Bildine SAI
SET @ENTRY := 16757;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16757,1,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,16757,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,5,16757,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,9,16757,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Waypoint 9 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,11,16757,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,12,16757,0,0,54,240000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Waypoint 12 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1675700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.06725,"Bildine - On Script - Set Orientation 6,06725"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,114000,114000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Remove Flag Standstate Kneel");

-- Actionlist SAI
SET @ENTRY := 1675701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.58345,"Bildine - On Script - Set Orientation 5,58345"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Set Emote State 69"),
(@ENTRY,9,3,0,0,0,100,0,56000,56000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bildine - On Script - Set Emote State 0");

DELETE FROM `waypoints` WHERE `entry`=16757;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16757,1,-3697.55,-11479.4,-119.491, 'Bildine'),
(16757,2,-3695.86,-11481.5,-119.479, 'Bildine'),
(16757,3,-3692.86,-11482.8,-119.448, 'Bildine'),
(16757,4,-3690.11,-11485.8,-119.428, 'Bildine'),
(16757,5,-3689.16,-11486.2,-119.418, 'Bildine'),
(16757,6,-3690.65,-11490.3,-119.451, 'Bildine'),
(16757,7,-3692.9,-11491.8,-119.483, 'Bildine'),
(16757,8,-3696.4,-11491.6,-119.523, 'Bildine'),
(16757,9,-3699.65,-11487.4,-119.546, 'Bildine'),
(16757,10,-3698.958,-11484.89,-119.2843, 'Bildine'),
(16757,11,-3698.27,-11485.3,-119.522, 'Bildine'),
(16757,12,-3697.55,-11479.4,-119.491, 'Bildine');
