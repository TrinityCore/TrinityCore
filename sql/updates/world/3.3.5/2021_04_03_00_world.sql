-- Harbinger of Horror https://www.youtube.com/watch?v=RwVs6nKQIws
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32278;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32278;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32278, 0, 0, 0, 60, 0, 100, 0, 0, 0, 30000, 30000, 0, 11, 18100, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Harbinger of Horror - On Update - Cast 'Frost Armor'"),
(32278, 0, 1, 0, 0, 0, 100, 0, 0, 6000, 6000, 10000, 0, 11, 61747, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Harbinger of Horror - In Combat - Cast 'Frostbolt'"),
(32278, 0, 2, 0, 0, 0, 100, 0, 10000, 20000, 20000, 40000, 0, 11, 12096, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, "Harbinger of Horror - In Combat - Cast 'Fear'"),
(32278, 0, 3, 0, 0, 0, 100, 0, 15000, 20000, 20000, 20000, 0, 11, 18099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Harbinger of Horror - In Combat - Cast 'Chill Nova'"),
(32278, 0, 4, 0, 0, 0, 100, 0, 8000, 10000, 20000, 20000, 0, 11, 60924, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Harbinger of Horror - In Combat - Cast 'Lich Slap'");

-- Fallen Spiderlord
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 31780 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31780, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 0, 11, 60802, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Fallen Spiderlord - In Combat - Cast 'Mandible Crush'");

-- Cruel Overseer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31853;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 31853;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31853, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 14000, 18000, 0, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Cruel Overseer - In Combat - Cast 'Blackhand'"),
(31853, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 0, 11, 49639, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Cruel Overseer - In Combat - Cast 'Crush'");

-- Scourge Death Knight
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32486;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32486;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32486, 0, 0, 0, 0, 0, 100, 0, 7000, 9000, 9000, 11000, 0, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Death Knight - In Combat - Cast 'Cleave'"),
(32486, 0, 1, 0, 0, 0, 100, 0, 8000, 10000, 14000, 18000, 0, 11, 22644, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Death Knight - In Combat - Cast 'Blood Leech'"),
(32486, 0, 2, 0, 0, 0, 100, 0, 16600, 17300, 28500, 34000, 0, 11, 55209, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Scourge Death Knight - In Combat - Cast 'Death Coil'");

-- Glacial Bonelord
UPDATE `smart_scripts` SET `action_param2` = 0, `target_type` = 2 WHERE `entryorguid` = 31754 AND `source_type` = 0 AND `id` IN (0,1);

-- Umbral Brute
UPDATE `smart_scripts` SET `target_type` = 2 WHERE `entryorguid` = 30922 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_param1` = 10966 WHERE `entryorguid` = 30922 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `entryorguid` = 30922 AND `source_type` = 0 AND `id` IN (0,1,2);

-- Ravaged Ghoul
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32502;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 32502;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32502, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 9000, 16000, 0, 11, 60872, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Ravaged Ghoul - In Combat - Cast 'Ravenous Claw'"),
(32502, 0, 1, 0, 0, 0, 100, 0, 8000, 13000, 15000, 25000, 0, 11, 60873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Ravaged Ghoul - In Combat - Cast 'Festering Bite'");

-- Death Knight Master
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29738;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 29738;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29738, 0, 0, 0, 60, 0, 100, 0, 0, 0, 30000, 30000, 0, 11, 50689, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Death Knight Master - On Update - Cast 'Blood Presence'"),
(29738, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 15000, 15000, 0, 11, 50688, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Death Knight Master - In Combat - Cast 'Plague Strike'");

-- Morbid Carcass
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29719;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 29719;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29719, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 0, 11, 40504, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Morbid Carcass - In Combat - Cast 'Cleave'"),
(29719, 0, 1, 0, 0, 0, 100, 0, 5000, 15000, 5000, 15000, 0, 11, 50335, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Morbid Carcass - In Combat - Cast 'Scourge Hook'");

-- Rabid Cannibal
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29722;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 29722;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29722, 0, 0, 0, 0, 0, 100, 0, 6000, 8000, 12000, 15000, 0, 11, 30639, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Rabid Cannibal - In Combat - Cast 'Carnivorous Bite'");
