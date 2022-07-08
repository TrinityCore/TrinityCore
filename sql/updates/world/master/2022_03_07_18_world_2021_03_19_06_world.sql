-- Frostbrood Spawn
DELETE FROM `smart_scripts` WHERE `entryorguid` = 31702 AND `source_type` = 0 AND `id` = 7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31702, 0, 7, 0, 0, 0, 100, 0, 0, 5000, 5000, 15000, 11, 60667, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Spawn - In Combat - Cast 'Frost Breath'");

-- Frostbrood Matriarch
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32492;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32492 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32492, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 5000, 15000, 11, 60667, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Matriarch - In Combat - Cast 'Frost Breath'");

-- Frostbrood Sentry & Ahunite Coldwave
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32767;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32767 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32767, 0, 0, 0, 0, 0, 100, 0, 0, 2000, 6000, 8000, 0, 11, 46406, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Sentry - In Combat - Cast 'Bitter Blast'");

UPDATE `smart_scripts` SET `event_param1` = 0, `event_param2` = 2000 WHERE `entryorguid` = 25756 AND `source_type` = 0 AND `id` = 0;

-- Savage Proto-Drake
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31265;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 31265 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31265, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 0, 11, 51219, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Savage Proto-Drake - In Combat - Cast 'Flame Breath'"),
(31265, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 15000, 25000, 0, 11, 41572, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Savage Proto-Drake - In Combat - Cast 'Wing Buffet'");

-- Skoll
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 35189;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35189 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35189, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 12000, 15000, 0, 11, 61184, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Skoll - In Combat - Cast 'Pounce'"),
(35189, 0, 1, 0, 0, 0, 100, 0, 5000, 9000, 8000, 13000, 0, 11, 61186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Skoll - In Combat - Cast 'Frozen Bite'");

-- Loque'nahak
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32517 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32517, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 12000, 15000, 0, 11, 61184, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Loque'nahak - In Combat - Cast 'Pounce'"),
(32517, 0, 1, 0, 0, 0, 100, 0, 5000, 9000, 8000, 13000, 0, 11, 61186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Loque'nahak - In Combat - Cast 'Frozen Bite'");
