/*
-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2501;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2501, 250100) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2501, 0, 0, 0, 20, 0, 100, 0, 609, 0, 0, 0, 80, 250100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley - On Quest 'Voodoo Dues' Rewarded - Run Script"),
(250100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley - On Script - Remove Questgiver Flag"),
(250100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley - On Script - Say Line 0"),
(250100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley - On Script - Say Line 1"),
(250100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley - On Script - Add Questgiver Flag");

DELETE FROM `creature_text` WHERE `CreatureID`=2501;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2501, 0, 0, "%s tries opening Maury's Clubbed Foot...", 16, 0, 100, 0, 0, 0, 744, 0, "\"Sea Wolf\" MacKinley"),
(2501, 1, 0, "Bah!  $n,  this foot won't budge!", 12, 0, 100, 0, 0, 0, 0, 0, "\"Sea Wolf\" MacKinley");
*/
