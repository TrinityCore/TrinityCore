-- Editing the SmartAI script of [Creature] ENTRY 128286 (name: Cursed Raider)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 128286;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 128286);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(128286, 0, 0, 0, 8, 0, 100, 0, 254830, 0, 0, 0, '', 33, 128446, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, ''),
(128286, 0, 1, 0, 8, 0, 100, 0, 254830, 0, 0, 0, '', 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');