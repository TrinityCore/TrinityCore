-- by razorr

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 131402;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 131402);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(131402, 0, 0, 0, 4, 0, 100, 3102, 0, 0, 0, 0, '', 11, 265533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underrot Tick - On Update IC - Cast \'265533\' (All difficulties)');



UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 130909;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 130909);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(130909, 0, 0, 0, 4, 0, 100, 3102, 0, 0, 0, 0, '', 11, 265540, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fetid Maggot - On Update IC - Cast \'265540\' (All difficulties)');



UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 131492;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 131492);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(131492, 0, 0, 0, 0, 0, 100, 3102, 5000, 10000, 25000, 30000, '', 11, 265091, 0, 0, 0, 0, 0, 26, 50, 0, 0, 0, 0, 0, 0, 'Devout Blood Priest - On Damaged Between 76000-150000 - Cast \'265091\' (All difficulties)');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 133685;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 133685);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(133685, 0, 0, 0, 0, 0, 100, 3102, 3000, 6000, 10000, 15000, '', 11, 265568, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Befouled Spirit - On Update IC - Cast \'265568\' (All difficulties)');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 133852;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 133852);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(133852, 0, 0, 0, 0, 0, 100, 3102, 2000, 2000, 8000, 8000, '', 11, 265668, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Rot - On Update IC - Cast \'265668\' (All difficulties)');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 133870;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 133870);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(133870, 0, 0, 0, 0, 0, 100, 3102, 6000, 10000, 20000, 25000, '', 11, 278961, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Diseased Lasher - On Update IC - Cast \'278961\' (All difficulties)');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 134284;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 134284);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(134284, 0, 0, 0, 0, 0, 100, 3102, 3000, 6000, 17000, 20000, '', 11, 272183, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Deathspeaker - On Update IC - Cast \'272183\' (All difficulties)'),
(134284, 0, 1, 0, 0, 0, 100, 3102, 0, 1500, 15000, 15000, '', 11, 266209, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Deathspeaker - On Update IC - Cast \'266209\' (All difficulties)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 133912;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 133912);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(133912, 0, 0, 0, 0, 0, 100, 3102, 5000, 10000, 15000, 20000, '', 11, 265523, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodsworn Defiler - On Update IC - Cast \'265523\' (All difficulties)'),
(133912, 0, 1, 0, 0, 0, 100, 3102, 0, 2500, 12000, 12000, '', 11, 265433, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodsworn Defiler - On Update IC - Cast \'265423\' (All difficulties)');


-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 138281;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 138281);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(138281, 0, 0, 0, 4, 0, 100, 3102, 5000, 5000, 20000, 20000, '', 11, 272592, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Faceless Corruptor - On Update IC - Cast \'272609\' (All difficulties)'),
(138281, 0, 1, 0, 0, 0, 100, 3102, 7000, 10000, 15000, 20000, '', 11, 272609, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Faceless Corruptor - On Update IC - Cast \'272609\' (All difficulties)');
