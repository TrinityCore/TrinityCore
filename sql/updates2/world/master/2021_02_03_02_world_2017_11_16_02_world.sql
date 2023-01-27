-- 
SET @ENTRY := 24972;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,44997,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - On Spellhit 'Converting Sentry' - Despawn Instant"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,13000,20000,86,35856,1,2,0,0,0,2,0,0,0,0,0,0,0,"Erratic Sentry - In Combat - Cross Cast 'stunn'"),
(@ENTRY,0,2,0,0,0,100,0,5500,6700,11200,16700,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Erratic Sentry - In Combat - Cast 'Crystal Strike'"),
(@ENTRY,0,3,0,0,0,100,0,8000,12000,8000,12000,11,35892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - In Combat - Cast 'Suppression'"),
(@ENTRY,0,4,5,2,0,100,1,0,50,0,0,11,45014,1,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - Between 0-50% Health - Cast 'Capacitor Overload' (No Repeat)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - Between 0-50% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,75,44986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - Between 0-50% Health - add aura Broken Capacitor"),
(@ENTRY,0,7,8,2,0,100,0,95,99,2000,2000,28,44994,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - Between 95% - 100% health - Remove aura 'Self repair'"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,28,44986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erratic Sentry - Between 95% - 100% health - Remove aura 'Broken Capacitor'");

DELETE FROM `creature_text` WHERE `CreatureID`=24972;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24972, 0, 0, "Core overload detected. System malfunction detected...", 12, 0, 100, 0, 0, 0, 24008, 0, "Erratic Sentry" );
