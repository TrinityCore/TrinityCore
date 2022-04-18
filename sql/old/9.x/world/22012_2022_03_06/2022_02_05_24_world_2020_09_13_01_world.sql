-- Scourged Footman
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25981;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25981 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25981, 0, 0, 0, 0, 0, 100, 0, 9000, 16000, 23000, 29000, 0, 11, 33735, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Scourged Footman - In Combat - Cast \'Blade Flurry\''),
(25981, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 11000, 14000, 0, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Scourged Footman - In Combat - Cast \'Mortal Strike\'');

-- Skadir Mariner
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25523;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25523 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25523, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 9000, 13000, 0, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Mariner - In Combat - Cast \'Uppercut\''),
(25523, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 18000, 24000, 0, 11, 13730, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Mariner - In Combat - Cast \'Demoralizing Shout\'');

-- Skadir Raider
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25522;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25522 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25522, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Raider - On Aggro - Say Line 0'),
(25522, 0, 1, 0, 0, 0, 100, 0, 5000, 9000, 7000, 9000, 0, 11, 43413, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Raider - In Combat - Cast \'Throw Spear\''),
(25522, 0, 2, 0, 0, 0, 100, 0, 8000, 12000, 30000, 40000, 0, 11, 43414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Raider - In Combat - Cast \'Freezing Trap\'');

-- Skadir Runecaster
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25520;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25520 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25520, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 0, 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Runecaster - In Combat CMC - Cast \'Lightning Bolt\''),
(25520, 0, 1, 0, 0, 0, 100, 0, 4000, 9000, 120000, 120000, 0, 11, 49871, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Skadir Runecaster - In Combat - Cast \'Rune of Retribution\'');

-- Den Vermin
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24567;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24567 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24567, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 7000, 12000, 0, 11, 3391, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Den Vermin - In Combat - Cast \'Thrash\'');

-- Ghostly Sage
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25351;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25351 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25351, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 0, 11, 9739, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Sage - In Combat CMC - Cast \'Wrath\''),
(25351, 0, 1, 0, 0, 0, 100, 0, 8900, 9700, 14500, 19900, 0, 11, 15798, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Sage - In Combat - Cast \'Moonfire\'');

-- Beryl Sorcerer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25316;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25316 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25316, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 0, 11, 9672, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Beryl Sorcerer - In Combat CMC - Cast \'Frostbolt\''),
(25316, 0, 1, 0, 2, 0, 100, 1, 0, 50, 0, 0, 0, 11, 50648, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Beryl Sorcerer - Between 0-50% Health - Cast \'Blink\' (No Repeat)');

-- Gamel the Cruel
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26449;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26449 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26449, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 14000, 17000, 0, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Gamel the Cruel - In Combat - Cast \'Mortal Strike\'');

-- Heigarr the Horrible
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26266;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26266 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26266, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 13000, 13000, 0, 11, 40504, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Heigarr the Horrible - In Combat - Cast \'Cleave\''),
(26266, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 18000, 22000, 0, 11, 32588, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Heigarr the Horrible - In Combat - Cast \'Concussion Blow\'');

-- En'kilah Ghoul
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25393;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25393 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25393, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 17000, 21000, 0, 11, 38056, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'En\'kilah Ghoul - In Combat - Cast \'Flesh Rip\'');

-- Gorloc Steam Belcher
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25687;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25687 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25687, 0, 0, 0, 0, 0, 100, 0, 3000, 6000, 11000, 16000, 0, 11, 50538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Gorloc Steam Belcher - In Combat - Cast \'Belch Blast\'');

-- Gorloc Waddler
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25685;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25685 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25685, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15800, 18300, 0, 11, 50522, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Gorloc Waddler - In Combat - Cast \'Gorloc Stomp\'');

-- Festering Ghoul
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25660;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25660 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25660, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 15000, 19000, 0, 11, 50361, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Festering Ghoul - In Combat - Cast \'Rot Armor\'');

-- Plagued Magnataur
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25615;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25615 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25615, 0, 0, 0, 0, 0, 100, 0, 500, 1000, 60000, 60000, 0, 11, 50366, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Plagued Magnataur - In Combat - Cast \'Plague Cloud\'');

-- Tundra Crawler
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25454;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25454 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25454, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 18000, 21000, 0, 11, 50293, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Tundra Crawler - In Combat - Cast \'Corrosive Poison\'');
