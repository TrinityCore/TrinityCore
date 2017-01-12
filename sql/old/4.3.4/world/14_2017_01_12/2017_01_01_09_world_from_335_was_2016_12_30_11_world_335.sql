/*
-- Kayneth Stillwind -- http://wotlk.openwow.com/npc=3848
DELETE FROM `waypoints` WHERE `entry`=3848;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(3848, 1, 2954.25,-3215.41,169.205, 'Kayneth Stillwind '),
(3848, 2, 2966.65,-3213.95,168.914, 'Kayneth Stillwind '),
(3848, 3, 2954.23,-3215.45,169.206, 'Kayneth Stillwind ');

-- Kayneth Stillwind SAI
SET @ENTRY := 3848;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kayneth Stillwind - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,53,0,3848,1,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Reset - Start Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,3848,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,4,40,0,100,0,2,3848,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,2,3848,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,3,3848,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Waypoint 3 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 384800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.965562,"Kayneth Stillwind - On Script - Set Orientation 0.965562"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=3848;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(3848, 0, 0, 'Putting the bottles away, %s sighs.', 16, 0, 100, 0, 0, 0, 'Kayneth Stillwind', 14108);
*/
