-- Scourge Soulbinder
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32284;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32284;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32284, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2500, 3000, 0, 11, 60814, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Soulbinder - In Combat CMC - Cast 'Frost Blast'"),
(32284, 0, 1, 0, 0, 0, 100, 0, 9000, 14000, 14000, 20000, 0, 11, 22744, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Soulbinder - In Combat - Cast 'Chains of Ice'"),
(32284, 0, 2, 0, 0, 0, 100, 0, 12600, 25200, 16700, 32300, 0, 11, 17620, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Soulbinder - In Combat - Cast 'Drain Life'");

-- Pustulent Colossus
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32482;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32482;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32482, 0, 0, 0, 0, 0, 100, 0, 10000, 15000, 10000, 15000, 0, 11, 28405, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Pustulent Colossus - In Combat - Cast 'Knockback'"),
(32482, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 0, 11, 63546, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Pustulent Colossus - In Combat - Cast 'Stomp'");

-- Corp'rethar Guardian https://www.youtube.com/watch?v=RwVs6nKQIws
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32280;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32280;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32280, 0, 0, 0, 0, 0, 100, 0, 10000, 10000, 20000, 25000, 0, 11, 54378, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Corp'rethar Guardian - In Combat - Cast 'Mortal Wound'"),
(32280, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 20000, 25000, 0, 11, 60927, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Corp'rethar Guardian - In Combat - Cast 'Infected Bite'");

-- Bone Sentinel
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32299;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32299;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32299, 0, 0, 0, 0, 0, 100, 0, 7000, 9000, 9000, 11000, 0, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Bone Sentinel - In Combat - Cast 'Mortal Strike'");

-- Bone Guard
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32479;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32479;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32479, 0, 0, 0, 0, 0, 100, 0, 7000, 9000, 9000, 11000, 0, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Bone Guard - In Combat - Cast 'Mortal Strike'");

-- Frostbrood Skytalon
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31137;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 31137 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31137, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 5000, 15000, 11, 60667, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Skytalon - In Combat - Cast 'Frost Breath'");

-- Necrotic Webspinner
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31747;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 31747;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31747, 0, 0, 0, 0, 0, 100, 0, 2000, 6000, 12000, 16000, 0, 11, 744, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Necrotic Webspinner - In Combat - Cast 'Poison'"),
(31747, 0, 1, 0, 0, 0, 100, 0, 1000, 3000, 10000, 15000, 0, 11, 745, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Necrotic Webspinner - In Combat - Cast 'Web'");
