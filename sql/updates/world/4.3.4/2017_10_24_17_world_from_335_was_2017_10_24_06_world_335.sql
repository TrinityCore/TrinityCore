/*
-- Sara Balloo
DELETE FROM `creature_text` WHERE `CreatureID`=2695;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2695,0,0,"%s reads Sully's letter page by page.",16,0,100,0,0,0,792,0,"Sara Balloo"),
(2695,1,0,"This isn't fair!  My dearest Sully!  Come back to me!  No, $n!  Why did you bring me such news!",12,7,100,18,0,0,793,0,"Sara Balloo");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2695;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2695 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=269500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2695,0,0,0,20,0,100,0,637,0,0,0,80,269500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sara Balloo - On Quest 'Sully Balloo's Letter' finished - Run Script"),
(269500,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sara Balloo - On Script - Say Line 0"),
(269500,9,1,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sara Balloo - On Script - Say Line 1");
*/
