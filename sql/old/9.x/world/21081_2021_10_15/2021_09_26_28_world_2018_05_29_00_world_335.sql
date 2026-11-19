-- Lucius
DELETE FROM `creature_text` WHERE `CreatureID`=6966;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6966,0,0,"Oh! I almost forgot! I slipped you a set of thieven' tools. You'll need those where you're going.",12,0,100,0,0,0,3562,0,"Lucius");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6966;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6966 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6966,0,0,0,19,0,100,0,2282,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lucius - On Quest 'Alther's Mill' Taken - Say Line 0");
