-- A slimy Situation
-- Kelnir Leafsong SAI
SET @ENTRY := 47696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,28207,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kelnir Leafsong - On Quest 'A Slimy Situation' Finished - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,28207,0,0,0,45,1,1,0,0,0,0,10,361152,47692,0,0,0,0,0,"Kelnir Leafsong - On Quest 'A Slimy Situation' Finished - Set Data 1 1");

DELETE FROM `creature_addon` WHERE `guid`=361152;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(361152,0,0,8,1,0, '');

-- Altsoba Ragetotem SAI
SET @ENTRY := 47692;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Altsoba Ragetotem - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 4769200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,5000,5000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Altsoba Ragetotem - On Script - Play Emote 7"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Altsoba Ragetotem - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Altsoba Ragetotem - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,11,89282,0,0,0,0,0,1,0,0,0,0,0,0,0,"Altsoba Ragetotem - On Script - Cast 'Vomit Slime'");

-- Purged Bloodvenom SAI
SET @ENTRY := 48019;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Purged Bloodvenom - On Just Summoned - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,2,48019,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Purged Bloodvenom - On Waypoint 2 Reached - Despawn In 2000 ms");

-- Actionlist SAI
SET @ENTRY := 4801900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,53,1,48019,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=48019;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(48019, 1, 5181.72, -705.112, 335.698, 'Purged Bloodvenom'),
(48019, 2, 5166.87, -680.257, 331.131, 'Purged Bloodvenom');

DELETE FROM `creature_text` WHERE `entry` IN (47696, 47692);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(47696, 0, 0, 'Open wide, Mr. Tauren! Here comes the hippogryph into the roost!', 12, 0, 100, 0, 0, 0, 48256, 0, 'Kelnir Leafsong'),
(47692, 0, 0, 'Urrrrrrgh...', 12, 0, 100, 0, 0, 0, 48254, 0, 'Altsoba Ragetotem'),
(47692, 1, 0, 'HLORRHGH!', 14, 0, 100, 0, 0, 0, 48255, 0, 'Altsoba Ragetotem');
