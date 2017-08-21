-- 
-- Actionlist SAI
SET @ENTRY := 2384300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,54000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 381"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,50,186418,45,0,0,0,0,8,0,0,0,-2954.89,-3883.94,32.9969,2.60053,"Mordant Grimsby - On Script - Summon Gameobject Mordant's Gift"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,4792,20,0,0,0,0,0,"Mordant Grimsby - On Script - Set Orientation Closest Creature Swamp Eye Jarl"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 0"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 0"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 1"),
(@ENTRY,9,7,0,0,0,100,0,5000,5000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 2"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,1,0,5000,0,0,0,0,19,4792,20,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 0"),
(@ENTRY,9,9,0,0,0,100,0,5000,5000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 3"),
(@ENTRY,9,10,0,0,0,100,0,6000,6000,0,0,1,1,5000,0,0,0,0,19,4792,20,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 1"),
(@ENTRY,9,11,0,0,0,100,0,5000,5000,0,0,1,4,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 4"),
(@ENTRY,9,12,0,0,0,100,0,8000,8000,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 381");
