-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25294;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25294 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25294, 0, 0, 1, 0, 0, 100, 0, 3000, 10000, 30000, 40000, 0, 11, 50284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Nerub'ar Web Lord - In Combat - Cast 'Blinding Swarm'"),
(25294, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nerub'ar Web Lord - In Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=25294;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25294, 0, 0, "The %s directs the blinding swarm directly in front of it.", 16, 0, 100, 0, 0, 0, 27381, 0, "Nerub'ar Web Lord");
