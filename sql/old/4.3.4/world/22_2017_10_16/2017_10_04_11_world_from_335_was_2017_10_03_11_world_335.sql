/*
-- Quest "Pamela's Doll" Completion Event
DELETE FROM `creature_text` WHERE `CreatureID`=10926 AND `GroupID` IN (4, 5);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10926,4,0,"Hurray!  My doll!",12,0,100,0,0,0,6416,0,"Pamela"),
(10926,5,0,"You'll keep the bad people away, won't you?",12,0,100,1,0,0,6417,0,"Pamela");

DELETE FROM `smart_scripts` WHERE `entryorguid`=10926 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1092600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10926,0,0,0,20,0,100,0,5149,0,0,0,80,1092600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pamela - On Quest \'Pamela\'s Doll\' Finished - Run Script"),
(1092600,9,0,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pamela - On Script - Say Line 4"),
(1092600,9,1,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pamela - On Script - Say Line 5");
*/
