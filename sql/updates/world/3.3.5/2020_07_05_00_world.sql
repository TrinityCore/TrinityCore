-- https://www.youtube.com/watch?v=JCNeC9Re4go
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4485 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4485,2,0,1,46,0,100,0,4485,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Caverns of Time) - On Trigger - Store Targetlist"),
(4485,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,20201,0,0,0,0,0,0,0,"Areatrigger (Caverns of Time) - On Link - Send Target 1 (Sa'at)"),
(4485,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,20201,0,0,0,0,0,0,0,"Areatrigger (Caverns of Time) - On Link - Set Data 0 1 (Sa'at)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4485;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4485,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20201 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2020100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20201,0,0,0,38,0,100,1,0,1,0,0,0,80,2020100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sa'at - On Data Set 0 1 - Run Script (No Repeat)"),
(20201,0,1,3,62,0,100,0,8088,0,0,0,0,11,34975,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sa'at - On Gossip Option 0 Selected - Cast 'Conjure Chrono-Beacon'"),
(20201,0,2,3,62,0,100,0,8088,1,0,0,0,11,34975,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sa'at - On Gossip Option 1 Selected - Cast 'Conjure Chrono-Beacon'"),
(20201,0,3,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sa'at - On Link - Close Gossip"),

(2020100,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sa'at - On Script - Say Line 0"),
(2020100,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sa'at - On Script - Set Orientation Stored Target"),
(2020100,9,2,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sa'at - On Script - Set Orientation Home Position");
