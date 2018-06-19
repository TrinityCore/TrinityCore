-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `faction` = 35, `type` = 10 WHERE (entry = 123560);

-- Creating a new SmartAI script for [Creature] ENTRY 123560 (name: Erratic Power Conduit)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 123560;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 123560);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(123560, 0, 0, 0, 8, 0, 100, 0, 247414, 0, 0, 0, 33, 123560, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');
