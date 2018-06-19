-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98366;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98521;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98370;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98368;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98538;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98677;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98681;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98792;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 98810;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 102788;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 102781;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 102095;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98366);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98366, 0, 0, 0, 0, 0, 100, 0, 1500, 3000, 4000, 6000, 11, 200084, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Retainer - In Combat - Cast \'200084\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98521);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98521, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 13000, 15000, 11, 194966, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, ''),
(98521, 0, 1, 0, 0, 0, 100, 0, 2500, 3500, 4000, 5000, 11, 196883, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98370);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98370, 0, 0, 0, 0, 0, 100, 0, 2500, 3000, 4000, 6000, 11, 199663, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, ''),
(98370, 0, 1, 0, 0, 0, 100, 0, 2500, 3500, 6000, 8000, 11, 225573, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98368);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98368, 0, 0, 0, 0, 0, 100, 0, 4000, 5000, 17000, 18000, 11, 200099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Protector - In Combat - Cast \'200099\''),
(98368, 0, 1, 0, 0, 0, 100, 0, 4100, 5100, 17100, 18100, 11, 200105, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Protector - In Combat - Cast \'200105\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98538);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98538, 0, 0, 0, 0, 0, 100, 0, 1700, 2000, 3700, 4700, 11, 225732, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Velandras Ravencrest - In Combat - Cast \'225732\''),
(98538, 0, 1, 0, 0, 0, 100, 0, 1500, 2500, 3000, 4000, 11, 196916, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Lady Velandras Ravencrest - In Combat - Cast \'196916\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98677);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98677, 0, 0, 0, 0, 0, 100, 0, 0, 1000, 32000, 34000, 11, 223971, 0, 0, 0, 0, 0, 17, 0, 15, 0, 0, 0, 0, 0, 'Rook Spinner - In Combat - Cast \'223971\''),
(98677, 0, 1, 0, 0, 0, 100, 0, 0, 0, 17000, 18000, 11, 225909, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 'Rook Spiderling - In Combat - Cast \'225909\''),
(98677, 0, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 225917, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rook Spiderling - In Combat - Cast \'225917\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98681);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98681, 0, 0, 0, 0, 0, 100, 0, 0, 1000, 32000, 34000, 11, 223971, 0, 0, 0, 0, 0, 17, 0, 15, 0, 0, 0, 0, 0, 'Rook Spinner - In Combat - Cast \'223971\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98792);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98792, 0, 0, 0, 0, 0, 100, 0, 0, 3000, 5000, 8000, 11, 200784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wyrmtongue Scavenger - In Combat - Cast \'200784\''),
(98792, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 8000, 10000, 11, 200913, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Wyrmtongue Scavenger - In Combat - Cast \'200913\''),
(98792, 0, 2, 0, 0, 0, 100, 0, 2500, 3500, 5000, 7000, 11, 201176, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Wyrmtongue Scavenger - In Combat - Cast \'201176\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 98810);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98810, 0, 0, 0, 0, 0, 100, 0, 1500, 2000, 5000, 7000, 11, 201139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrathguard Bladelord - In Combat - Cast \'201139\''),
(98810, 0, 1, 0, 0, 0, 100, 0, 1700, 2200, 5200, 7200, 11, 201141, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Wrathguard Bladelord - In Combat - Cast \'201141\''),
(98810, 0, 2, 0, 0, 0, 100, 0, 10000, 12000, 123000, 125000, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrathguard Bladelord - In Combat - Cast \'8599\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 102788);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(102788, 0, 0, 0, 0, 0, 100, 0, 2500, 3500, 12000, 14000, 11, 203163, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Felspite Dominator - In Combat - Cast \'203163\''),
(102788, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 21000, 23000, 11, 227913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Felspite Dominator - In Combat - Cast \'227913\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 102781);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(102781, 0, 0, 0, 0, 0, 100, 0, 3000, 4000, 31000, 32000, 11, 215377, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Fel Bat Pup - In Combat - Cast \'215377\'');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 102095);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(102095, 0, 0, 0, 0, 0, 100, 0, 2000, 5000, 9000, 11000, '', 11, 214001, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Risen Lancer - In Combat - Cast \'214001\''),
(102095, 0, 1, 0, 0, 0, 100, 0, 8000, 10000, 12000, 14000, '', 11, 214002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Lancer - In Combat - Cast \'214002\'');
