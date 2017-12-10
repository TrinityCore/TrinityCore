-- Dekin -- http://wotlk.openwow.com/npc=16708
UPDATE `creature` SET `position_x` = -3751.045898, `position_y` = -11377.740234, `position_z` = -137.525208, `orientation` = 3.976810, `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 57702;

-- Dekin SAI
SET @ENTRY := 16708;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16708,1,0,0,0,1,0,0,0,0,0,0,0,"Dekin - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,6,16708,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dekin - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,12,16708,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dekin - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,3,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dekin - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1670800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,2,0,0,0,100,0,19000,19000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Flag Standstate Kneel");

-- Actionlist SAI
SET @ENTRY := 1670801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,245000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,379,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 379"),
(@ENTRY,9,2,0,0,0,100,0,235000,235000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 0"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 18");

DELETE FROM `waypoints` WHERE `entry`=16708;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16708,1,-3746.39,-11372,-135.298, 'Dekin'),
(16708,2,-3743.14,-11371,-135.256, 'Dekin'),
(16708,3,-3734.39,-11370,-135.152, 'Dekin'),
(16708,4,-3728.64,-11371.5,-135.092, 'Dekin'),
(16708,5,-3722.89,-11376,-135.043, 'Dekin'),
(16708,6,-3721.73,-11378.3,-135.039, 'Dekin'),
(16708,7,-3722.61,-11376.3,-135.042, 'Dekin'),
(16708,8,-3728.57,-11371.6,-135.092, 'Dekin'),
(16708,9,-3734.09,-11369.9,-135.149, 'Dekin'),
(16708,10,-3742.64,-11370.7,-135.249, 'Dekin'),
(16708,11,-3746.09,-11372.2,-135.295, 'Dekin'),
(16708,12,-3751.04,-11377.7,-137.525, 'Dekin');
