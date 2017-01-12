/*
-- [Q] Nugget Slugs -- http://wotlk.openwow.com/quest=3922
-- Actionlist SAI
SET @ENTRY := 931600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wenikee Boltbucket - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,70,7,0,0,0,0,0,14,6579,162024,0,0,0,0,0,"Wenikee Boltbucket - On Script - Respawn Closest Gameobject 'Samophlange'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.725311,"Wenikee Boltbucket - On Script - Set Orientation 0.725311"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wenikee Boltbucket - On Script - Set Emote State 173"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wenikee Boltbucket - On Script - Set Emote State 0"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,11,13727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wenikee Boltbucket - On Script - Cast 'Break Samophlange'"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.72271,"Wenikee Boltbucket - On Script - Set Orientation 2.72271"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wenikee Boltbucket - On Script - Say Line 1");
*/
