-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24459;
DELETE FROM `creature_template_addon` WHERE `entry`=24459;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(24459, "28429");
DELETE FROM `smart_scripts` WHERE `entryorguid`=24459 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24459, 0, 0, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chillmere Coastrunner - Between 0-15% Health - Flee For Assist (No Repeat)");
