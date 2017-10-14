/*
-- Quest "Skull Rock" Completion Event
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3208;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3208 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=320800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3208,0,0,0,20,0,100,0,827,0,0,0,80,320800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Margoz - On Quest 'Skull Rock' Finished - Run Script"),
(320800,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Margoz - On Script - Remove Npc Flag Questgiver"),
(320800,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Margoz - On Script - Say Line 0"),
(320800,9,2,0,0,0,100,0,0,0,0,0,11,5017,0,0,0,0,0,1,0,0,0,0,0,0,0,"Margoz - On Script - Cast 'Divining Trance'"),
(320800,9,3,0,0,0,100,0,4500,4500,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Margoz - On Script - Say Line 1"),
(320800,9,4,0,0,0,100,0,0,0,0,0,11,40108,1,0,0,0,0,1,0,0,0,0,0,0,0,"Margoz - On Script - Cast 'Cosmetic - Legion Ring Fel Impact'"),
(320800,9,5,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Margoz - On Script - Say Line 2"),
(320800,9,6,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Margoz - On Script - Say Line 3"),
(320800,9,7,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Margoz - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=3208;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3208,0,0,"%s enters a trance...",16,0,100,0,0,0,986,0,"Margoz"),
(3208,1,0,"%s is burned by unleashed magic!",16,0,100,0,0,0,987,0,"Margoz"),
(3208,2,0,"Argh!",12,1,100,34,0,0,989,0,"Margoz"),
(3208,3,0,"$n, unlocking the secret of these collars is beyond my skills...",12,1,100,274,0,0,988,0,"Margoz");
*/
