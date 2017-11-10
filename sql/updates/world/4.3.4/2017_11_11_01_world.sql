-- Jin'thala
SET @ENTRY := 37951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,24750,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,2,3,19,0,100,0,24758,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,4,5,19,0,100,0,24770,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,6,7,19,0,100,0,24776,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,8,9,19,0,100,0,24782,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,10,11,19,0,100,0,24607,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,12,13,19,0,100,0,24764,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,14,15,19,0,100,0,26272,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'");