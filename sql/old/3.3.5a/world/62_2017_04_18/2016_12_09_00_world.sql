-- [Q] Captain Vimes -- http://www.wowhead.com/quest=1220
-- [Q] Suspicious Hoofprints -- http://wotlk.openwow.com/quest=1284
-- Captain Garran Vimes SAI
SET @ENTRY := 4944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,1220,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Garran Vimes - On Quest 'Captain Vimes' Finished - Store Targetlist"),
(@ENTRY,0,1,0,61,0,100,0,1220,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Quest 'Captain Vimes' Finished - Run Script"),
(@ENTRY,0,2,3,20,0,100,0,1284,0,0,0,64,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Garran Vimes - On Quest 'Suspicious Hoofprints' Finished - Store Targetlist"),
(@ENTRY,0,3,0,61,0,100,0,1284,0,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Quest 'Suspicious Hoofprints' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 494400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,50,21128,10,0,0,0,0,8,0,0,0,-3735.3483,-4554.6777,28.5526,3.55917,"Captain Garran Vimes - On Script - Summon Gameobject 'Orc Spy Report'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.93417,"Captain Garran Vimes - On Script - Set Orientation 1,93417"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Set Orientation Player"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,85,6245,2,0,0,0,0,12,1,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Invoker Cast 'Force Target - Salute'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,11,6245,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Cast 'Force Target - Salute'"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.151920,"Captain Garran Vimes - On Script - Set Orientation 1,151920");

-- Actionlist SAI
SET @ENTRY := 494401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,10,10,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,5088,5,0,0,0,0,8,0,0,0,-3717.0373,-4523.4580,25.83386,5.15678,"On Script - Summon Creature 'Falgran Hastil'"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,4948,50,0,0,0,0,0,"On Script - Say Line 0");

-- Falgran Hastil SAI
SET @ENTRY := 5088;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,53,0,@ENTRY*100+00,0,0,0,0,1,0,0,0,0,0,0,0,"Falgran Hastil - On Just Created - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,4,@ENTRY*100+00,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Falgran Hastil - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,4,@ENTRY*100+01,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Falgran Hastil - On Waypoint 4 Reached - Despawn In 1000 ms");

-- Actionlist SAI
SET @ENTRY := 508800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,4944,50,0,0,0,0,0,"On Script - Set Orientation Closest Creature 'Captain Garran Vimes'"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Kneel"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Stand"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,11,6245,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Force Target - Salute'"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,53,1,508801,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=508800;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(508800, 1, -3714.99, -4527.66, 25.8339, 'Falgran Hastil - Path 1'),
(508800, 2, -3712.47, -4533.24, 25.8339, 'Falgran Hastil - Path 1'),
(508800, 3, -3716.93, -4541.17, 25.8339, 'Falgran Hastil - Path 1'),
(508800, 4, -3724.09, -4545.34, 25.8339, 'Falgran Hastil - Path 1');
-- 
DELETE FROM `waypoints` WHERE `entry`=508801;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(508801, 1, -3716.93, -4541.17, 25.8339, 'Falgran Hastil - Path 2'),
(508801, 2, -3712.47, -4533.24, 25.8339, 'Falgran Hastil - Path 2'),
(508801, 3, -3714.99, -4527.66, 25.8339, 'Falgran Hastil - Path 2'),
(508801, 4, -3718.48, -4522.41, 25.8338, 'Falgran Hastil - Path 2');

DELETE FROM `creature_text` WHERE `entry` IN (4944, 4948, 5088);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(4944, 0, 0, '%s places the scroll on the table, and reads...', 16, 0, 100, 0, 0, 0, 1671, 'Captain Garran Vimes'),
(4944, 1, 0, 'By the Light!  This cursed spy was a good one! I''m glad he''s dead.', 12, 0, 100, 5, 0, 0, 1672, 'Captain Garran Vimes'),
(4944, 2, 0, 'Thank you for this report, $n.  It is now clear that we must tighten our patrols near Theramore.', 12, 0, 100, 0, 0, 0, 1673, 'Captain Garran Vimes'),
(4944, 3, 0, 'Tesoran! I need someone--Falgran Hastil, preferably--to take care of $n''s lead on the prints near the Shady Rest Inn.', 12, 0, 100, 1, 0, 0, 1753, 'Captain Garran Vimes'),
(4948, 0, 0, 'Right away, sir.', 12, 0, 100, 1, 0, 0, 1754, 'Adjutant Tesoran'),
(5088, 0, 0, 'Falgran Hastil reporting, sir. I will find where the hoofprints lead and report back to you.', 12, 0, 100, 1, 0, 0, 1752, 'Falgran Hastil');
