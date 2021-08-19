--
-- Add script and waypoints to Draenei Artificer
SET @ENTRY := 17228;
SET @GUID := -82823;
SET @ACTIONLIST_0 := 8282300;
SET @ACTIONLIST_1 := 8282301;

-- Remove emote from Draenei Artificer
DELETE FROM `creature_addon` WHERE `guid`=82823;
INSERT INTO `creature_addon` (`guid`, `emote`, `bytes2`) VALUES 
(82823, 0, 4097);

-- Add weapon to Draenei Artificer
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@ENTRY AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES (@ENTRY, 2, 2530, 0, 0, 18019);

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@ENTRY, 1, -4189.97, -12460.97, 45.227, 'Draenei Artificer'),
(@ENTRY, 2, -4191.24, -12456.74, 45.444, 'Draenei Artificer'),
(@ENTRY, 3, -4192.75, -12453.75, 45.635, 'Draenei Artificer'),
(@ENTRY, 4, -4191.24, -12456.74, 45.444, 'Draenei Artificer'),
(@ENTRY, 5, -4189.97, -12460.97, 45.227, 'Draenei Artificer'),
(@ENTRY, 6, -4191.44, -12464.07, 45.340, 'Draenei Artificer');

-- Add SAI to Draenei Artificer + Actionlist 00/01
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GUID, @ACTIONLIST_0, @ACTIONLIST_1) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,40,0,100,0,3,@ENTRY,0,0,80,@ACTIONLIST_0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Waypoint 3 Reached - Run Script"),
(@GUID,0,1,0,40,0,100,0,6,@ENTRY,0,0,80,@ACTIONLIST_1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Waypoint 6 Reached - Run Script"),
(@GUID,0,2,0,1,0,100,0,0,0,130000,130000,53,0,@ENTRY,1,0,0,2,1,0,0,0,0,0,0,0,"Draenei Artificer - Out of Combat - Start Waypoint"),
(@ACTIONLIST_0,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,0,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Pause Waypoint"),
(@ACTIONLIST_0,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8356,"Draenei Artificer - On Script - Set Orientation 0,8356"),
(@ACTIONLIST_0,9,2,0,0,0,100,0,1500,1500,0,0,71,2,1,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Change Equipment"),
(@ACTIONLIST_0,9,3,0,0,0,100,0,2000,2000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 234"),
(@ACTIONLIST_0,9,4,0,0,0,100,0,55000,55000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 0"),
(@ACTIONLIST_1,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Pause Waypoint"),
(@ACTIONLIST_1,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.8398,"Draenei Artificer - On Script - Set Orientation 3,8398"),
(@ACTIONLIST_1,9,3,0,0,0,100,0,1500,1500,0,0,71,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Change Equipment"),
(@ACTIONLIST_1,9,4,0,0,0,100,0,2000,2000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 234"),
(@ACTIONLIST_1,9,5,0,0,0,100,0,55000,55000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 0");
