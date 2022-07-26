-- Forgotten Depths Slayer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30333;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30333 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30333, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 5000, 7000, 0, 11, 54185, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Slayer - In Combat - Cast 'Claw Slash'");

-- Forgotten Depths Acolyte
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30205;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30205 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30205, 0, 0, 0, 0, 0, 100, 0, 4000, 9000, 18000, 25000, 0, 11, 60781, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Acolyte - In Combat - Cast 'Curse of Mending'"),
(30205, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 7000, 14000, 0, 11, 16583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Acolyte - In Combat - Cast 'Shadow Shock'");

-- Forgotten Depths Underking
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30544;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30544 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30544, 0, 0, 0, 0, 0, 100, 0, 1500, 2000, 10000, 15000, 0, 11, 50284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Underking - In Combat - Cast 'Blinding Swarm'"),
(30544, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 0, 11, 60802, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Underking - In Combat - Cast 'Mandible Crush'");

-- Brainwashed Noble
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 596;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 596 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(596, 0, 0, 0, 60, 0, 100, 0, 0, 0, 30000, 30000, 0, 11, 12544, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Brainwashed Noble - On Update - Cast 'Frost Armor'"),
(596, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 5400, 0, 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Brainwashed Noble - In Combat CMC - Cast 'Fireball'"),
(596, 0, 2, 0, 0, 0, 100, 0, 7000, 12000, 14000, 19000, 0, 11, 228, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Brainwashed Noble - In Combat - Cast 'Polymorph: Chicken'"),
(596, 0, 3, 0, 2, 0, 100, 0, 0, 50, 35000, 35000, 0, 11, 512, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Brainwashed Noble - Between 0-50% Health - Cast 'Chains of Ice'");
-- According to https://tbc.wowhead.com/npc=596/brainwashed-noble#comments:id=2893429 it shoud be immune to sap and not sure if gouge too
UPDATE `creature_template` SET `mechanic_immune_mask` = 536870912 WHERE `entry` = 596;

-- Marisa du'Paige
-- Set polymorph chance 100
UPDATE `smart_scripts` SET `event_chance` = 100 WHERE `entryorguid` = 599 AND `source_type` = 0 AND `id` = 1;
-- According to https://tbc.wowhead.com/npc=599/marisa-dupaige#comments:id=2893432 she shoud be immune to : stun, fear, and polymorph effects.
UPDATE `creature_template` SET `mechanic_immune_mask` = 67600 WHERE `entry` = 599;

-- Mottled Screecher call for help at 30% according to https://www.wowhead.com/npc=1021/mottled-screecher#comments:id=113929
-- https://youtu.be/n7xUYhVrTpQ?t=9 and vmangos
UPDATE `smart_scripts` SET `event_param2` = 30, `comment` = "Mottled Screecher - Between 0-30% Health - Call For Help (No Repeat)" WHERE `entryorguid` = 1021 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `comment` = "Mottled Screecher - Between 0-30% Health - Say Line 0 (No Repeat)" WHERE `entryorguid` = 1021 AND `source_type` = 0 AND `id` = 1;

-- Carrion Fleshstripper
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30206;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30206 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30206, 0, 0, 0, 0, 0, 100, 0, 2000, 6000, 12000, 16000, 0, 11, 35201, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Carrion Fleshstripper - In Combat - Cast 'Paralytic Poison'");

-- Frostbrood Destroyer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30575;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30575 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30575, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 0, 11, 57477, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Destroyer - In Combat - Cast 'Freezing Breath'"),
(30575, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 15000, 25000, 0, 11, 53363, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Frostbrood Destroyer - In Combat - Cast 'Wing Buffet'");

-- Crusader of Virtue
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30189;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30189 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30189, 0, 0, 0, 2, 0, 100, 0, 0, 50, 5000, 12000, 0, 11, 58053, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Crusader of Virtue - Between 0-50% Health - Cast 'Holy Light'");

-- Set Arch Mage Xintor respawntime 1 min 12 sec according to https://tbc.wowhead.com/npc=16977/arch-mage-xintor#comments
UPDATE `creature` SET `spawntimesecs` = 72 WHERE `id` = 16977 AND `guid` = 86049;

-- Lieutenant Commander Thalvos respawntime 20 sec according to https://tbc.wowhead.com/npc=16978/lieutenant-commander-thalvos#comments:id=2808941
UPDATE `creature` SET `spawntimesecs` = 20 WHERE `id` = 16978 AND `guid` = 59381;
