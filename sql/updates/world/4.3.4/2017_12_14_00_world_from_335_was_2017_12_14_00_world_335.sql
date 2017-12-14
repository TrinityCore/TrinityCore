/*
-- Dran Droffers & Malton Droffers
DELETE FROM `creature_text` WHERE `CreatureID` IN (6986,6987);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6986,0,0,"Now we just need to figure out how to get this thing working again.",12,0,100,1,0,0,3077,0,"Dran Droffers"),
(6986,1,0,"Boy, you couldn't fix a sandwich without someone tellin' ya how to do it.",12,0,100,274,0,0,3080,0,"Dran Droffers"),
(6986,2,0,"Malton, you dummy!",14,0,100,5,0,0,3081,0,"Dran Droffers"),
(6987,0,0,"Maybe I can fix it, pop.  Lemme take a look at it.",12,0,100,1,0,0,3078,0,"Malton Droffers"),
(6987,1,0,"Sandwich?  What?  You makin' a sandwich for me, pop?",12,0,100,6,0,0,3079,0,"Malton Droffers");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6986;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6986 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=698600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6986,0,0,0,20,0,100,0,2340,0,0,0,80,698600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dran Droffers - On Quest 'Deliver the Gems' Finished - Run Script"),
(698600,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dran Droffers - On Script - Say Line 0"),
(698600,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,6987,0,0,0,0,0,0,"Dran Droffers - On Script - Say Line 0 (Malton Droffers)"),
(698600,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dran Droffers - On Script - Say Line 1"),
(698600,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,6987,0,0,0,0,0,0,"Dran Droffers - On Script - Say Line 1 (Malton Droffers)"),
(698600,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dran Droffers - On Script - Say Line 2");
*/
