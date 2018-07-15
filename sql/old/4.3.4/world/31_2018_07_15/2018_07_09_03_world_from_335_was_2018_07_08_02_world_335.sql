/*
-- Apothecary Renferrel
DELETE FROM `creature_text` WHERE `CreatureID`=1937;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1937,0,0,"%s concocts a potion for $n.",16,0,100,0,0,0,885,0,"Apothecary Renferrel");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1937 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=193700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1937,0,0,0,19,0,100,0,430,0,0,0,80,193700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Renferrel - On Quest 'Return to Quinn' Taken - Run Script"),
(193700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Renferrel - On Script - Say Line 0"),
(193700,9,1,0,0,0,100,0,0,0,0,0,11,4508,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Renferrel - On Script - Cast 'Discolored Healing Potion'");
*/
