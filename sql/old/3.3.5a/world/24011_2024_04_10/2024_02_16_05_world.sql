-- Gondria https://www.wowhead.com/wotlk/npc=33776/gondria#abilities
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 33776;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 33776 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(33776, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 12000, 15000, 0, 11, 61184, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Gondria - In Combat - Cast 'Pounce'"),
(33776, 0, 1, 0, 0, 0, 100, 0, 5000, 9000, 8000, 13000, 0, 11, 61186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Gondria - In Combat - Cast 'Frozen Bite'");

-- Loque'nahak added again missing frozen bite https://www.wowhead.com/wotlk/npc=32517/loquenahak#abilities
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 32517;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32517 AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32517, 0, 1, 0, 0, 0, 100, 0, 1000, 5000, 8000, 13000, 0, 11, 61186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Loque\'nahak - In Combat - Cast 'Frozen Bite'");

-- Skoll added again missing frozen bite https://www.wowhead.com/wotlk/npc=35189/skoll#abilities
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 35189;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35189 AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35189, 0, 1, 0, 0, 0, 100, 0, 1000, 5000, 8000, 13000, 0, 11, 61186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Skoll - In Combat - Cast 'Frozen Bite'");

-- Azurous rename wrong comment and correct sai order id https://www.wowhead.com/wotlk/npc=10202/azurous#abilities
UPDATE `smart_scripts` SET `id` = 0, `comment` = "Azurous - In Combat - Cast 'Frost Breath'" WHERE `entryorguid` = 10202 AND `source_type` = 0 AND `id` = 1;

-- Avruu https://www.wowhead.com/wotlk/npc=17084/avruu#abilities
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17084;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17084 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17084, 0, 0, 0, 74, 0, 100, 0, 0, 40, 15000, 18000, 30, 11, 16588, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Avruu - On Friendly Between 0-40% Health - Cast 'Dark Mending'"),
(17084, 0, 1, 0, 0, 0, 100, 0, 0, 0, 8000, 8000, 0, 11, 34112, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Avruu - In Combat - Cast 'Judgement of Darkness'");

-- Warmaul Brute https://www.wowhead.com/wotlk/npc=18065/warmaul-brute#abilities;mode:normal
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18065;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18065 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18065, 0, 0, 0, 0, 0, 100, 0, 4000, 7000, 9000, 12000, 0, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Warmaul Brute  - In Combat - Cast 'Uppercut'");

-- Warp Monstrosity https://www.wowhead.com/wotlk/npc=20516/warp-monstrosity#abilities
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20516;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20516 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20516, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 12000, 15000, 0, 11, 13901, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Warp Monstrosity - In Combat - Cast 'Arcane Bolt'"),
(20516, 0, 1, 0, 0, 0, 100, 1, 5000, 9000, 8000, 13000, 0, 11, 36577, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Warp Monstrosity - In Combat - Cast 'Warp Storm'");
