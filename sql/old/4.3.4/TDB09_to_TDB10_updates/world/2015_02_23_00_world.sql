-- Wild Vortex SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45912;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45912 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45912, 0, 0, 0, 0, 0, 100, 0, 1600, 1600, 2500, 2500, 11, 88032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - In Combat - Cast 'Lightning Bolt'"),
(45912, 0, 1, 0, 8, 0, 10, 0, 0, 0, 5000, 10000, 11, 88010, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - On SpellHit - Cast 'Cyclone'"),
(45912, 0, 2, 0, 13, 0, 50, 0, 5000, 10000, 0, 0, 11, 88029, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - On Target SpellCast - Cast 'Wind Shock'");

-- Gust Soldier SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45477;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45477 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45477, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 87930, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - On Aggro - Cast 'Charge'"),
(45477, 0, 1, 0, 0, 0, 100, 0, 8000, 12000, 8000, 12000, 11, 87923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Wind Blast'"),
(45477, 0, 2, 0, 0, 0, 100, 0, 20000, 25000, 20000, 25000, 11, 87933, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Air Nova'");

-- Armored Mistral SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45915;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45915 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45915, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 88057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - On Aggro - Cast 'Rising Winds'"),
(45915, 0, 1, 0, 0, 0, 100, 0, 10000, 12000, 8000, 12000, 11, 88061, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Gale Strike'"),
(45915, 0, 2, 0, 0, 0, 100, 0, 12000, 15000, 12000, 15000, 11, 88055, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Storm Surge'");

-- Cloud Prince SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45917;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45917 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45917, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 88081, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - On Aggro - Cast 'Whipping Winds'"),
(45917, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 11, 88073, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Starfall'"),
(45917, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 10000, 15000, 11, 88075, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Typhoon'");

-- Whipping Wind SAI 
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 47238;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 47238 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(47238, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1500, 1500, 11, 88080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Whipping Wind - In Combat - Cast 'Lightning Bolt'");

-- Turbulent Squall
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45924;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45924 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45924, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 20000, 11, 88175, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Asphyxiate'"),
(45924, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 5000, 15000, 11, 88170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Cloudburst'"),
(45924, 0, 2, 0, 0, 0, 100, 0, 5000, 20000, 20000, 25000, 11, 88171, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Hurricane'");

-- Empyrean Assassin
DELETE FROM `creature_template_addon` WHERE `entry` = 45922;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45922, 0, 0, 0, 1, 0, '88184');

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45922;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45922 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45922, 0, 0, 0, 0, 0, 100, 0, 20000, 20000, 20000, 20000, 11, 88182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Empyrean Assassin - In Combat - Cast 'Vapor Form'");

-- Executor of the Caliph SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45928;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45928 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45928, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 11, 78660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Devastate'"),
(45928, 0, 1, 0, 0, 0, 100, 0, 15000, 18000, 15000, 18000, 11, 87759, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Shockwave'"),
(45928, 0, 2, 0, 0, 0, 100, 0, 20000, 25000, 20000, 25000, 11, 87761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Rally'");

-- Minister of Air SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45930;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45930 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45930, 0, 0, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 87762, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Minister of Air - In Combat - Cast 'Lightning Lash'"),
(45930, 0, 1, 0, 0, 0, 100, 0, 12000, 18000, 12000, 18000, 11, 87768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Minister of Air - In Combat - Cast 'Lightning Nova'");

-- Servant of Asaad SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45926;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45926 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45926, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 11, 87771, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Crusader Strike'"),
(45926, 0, 1, 0, 0, 0, 100, 0, 14000, 14000, 12000, 12000, 11, 58127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Divine Storm'"),
(45926, 0, 2, 0, 0, 0, 100, 0, 32000, 35000, 32000, 35000, 11, 87772, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Hand of Protection'");

-- Temple Adept SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45935;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45935 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45935, 0, 0, 0, 0, 0, 100, 0, 500, 1000, 4000, 6000, 11, 88959, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Holy Smite'"),
(45935, 0, 1, 0, 0, 0, 100, 0, 3000, 5000, 8000, 10000, 11, 87779, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Greater Heal'"),
(45935, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 12000, 12000, 11, 87780, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Desperate Speed'");
