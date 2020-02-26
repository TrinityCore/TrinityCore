-- 
DELETE FROM `creature_text` WHERE `CreatureID`=18897;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18897, 0, 0, "Welcome, welcome, to the recently appropriated and callously renamed Steamwheedle Stadium!", 12, 0, 100, 0, 0, 0, 16072, 0, "\"King\" Dond");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18897;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18897 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18897, 0, 0, 0, 10, 0, 100, 0, 1, 5, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"King\" Dond - OOC LoS - Say Line 0");
