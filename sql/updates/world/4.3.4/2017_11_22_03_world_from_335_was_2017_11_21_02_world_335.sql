/*
-- 
-- Kirge Sternhorn
DELETE FROM `creature_text` WHERE `CreatureID`=3418;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3418,0,0,"To reach The Crossroads, $n, follow the road east then north.",12,1,100,1,0,0,1364,0,"Kirge Sternhorn");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3418;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3418 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3418,0,0,0,19,0,100,0,854,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kirge Sternhorn - On Quest 'Journey to the Crossroads' Taken - Say Line 0");
*/
