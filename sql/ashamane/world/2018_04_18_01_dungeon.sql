DELETE FROM spell_custom_attr WHERE entry = 200345;
INSERT INTO spell_custom_attr VALUES (200345, 1048576);

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98243;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98691;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98280;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98275;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 101839;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98706;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 102094;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 102095;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98243);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98243, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 8500, 10000, 11, 200261, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98691);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98691, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 8000, 11000, 11, 200291, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98280);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98280, 0, 0, 0, 0, 0, 100, 0, 3500, 5000, 7500, 8500, 11, 200248, 0, 0, 0, 0, 0, 17, 0, 50000, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98275);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98275, 0, 0, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 11, 193633, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, ''),
(98275, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 8000, 10000, 11, 200343, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, ''),
(98275, 0, 2, 1, 0, 0, 100, 0, 10000, 10000, 13000, 15000, 11, 200345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 101839);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(101839, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 15000, 17000, 11, 225962, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, ''),
(101839, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 14000, 17000, 11, 225963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98706);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98706, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 8500, 10000, 11, 200261, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 102094);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(102094, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 8000, 10000, 11, 214003, 0, 0, 0, 0, 0, 17, 0, 10, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 102095);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(102095, 0, 0, 0, 0, 0, 100, 0, 2000, 5000, 7000, 10000, 11, 214001, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, ''),
(102095, 0, 1, 0, 0, 0, 100, 0, 8000, 10000, 12000, 14000, 11, 214002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
