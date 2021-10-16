-- Sky Terror
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28246;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 28246);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28246, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 0, 11, 31273, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Terror - In Combat - Cast 'Screech'");

-- Carrion Eater
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28022;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 28022);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28022, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 9000, 16000, 0, 11, 54387, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Carrion Eater - In Combat - Cast 'Ravenous Claw'");

-- Drakkari Native
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29211;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 29211);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29211, 0, 0, 0, 2, 0, 100, 0, 0, 30, 30000, 35000, 0, 11, 51307, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Drakkari Native - In Combat - Cast 'Unwavering Will'");

-- Hath'ar Skimmer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28258;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 28258);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28258, 0, 0, 0, 0, 0, 100, 0, 3000, 6000, 6000, 12000, 0, 11, 54487, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Hath'ar Skimmer - In Combat - Cast 'Jump Attack'");

-- Decomposed Ghoul
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31812;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 31812);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31812, 0, 0, 0, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 15716, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Decomposed Ghoul - Between 0-30% Health - Cast 'Enrage'"),
(31812, 0, 1, 0, 0, 0, 100, 0, 3000, 12000, 3000, 12000, 0, 11, 12097, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Decomposed Ghoul - In Combat - Cast 'Pierce Armor'");

-- Frostskull Magus
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31813;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 31813);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31813, 0, 0, 0, 0, 0, 100, 0, 0, 6000, 6000, 10000, 0, 11, 20297, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Frostskull Magus - In Combat - Cast 'Frostbolt'");

-- Myst Leecher
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 17523;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17523);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17523, 0, 0, 0, 0, 0, 100, 0, 3000, 9000, 10000, 18000, 0, 11, 31288, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Myst Leecher - In Combat - Cast 'Leech Poison'");

-- Skoll (Oops ,seems this rare in wotlk had just pounce)
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 35189) AND (`source_type` = 0) AND (`id` IN (1));

-- Loque'nahak (Oops ,same)
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 32517) AND (`source_type` = 0) AND (`id` IN (1));
