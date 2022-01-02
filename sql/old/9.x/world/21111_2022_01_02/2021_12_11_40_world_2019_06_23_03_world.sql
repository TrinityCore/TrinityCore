-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (23740, 29710);
DELETE FROM `smart_scripts` WHERE `entryorguid`=26472 AND `source_type`=0 AND `id`=7;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23740, 29710) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26472, 0, 7, 0, 0, 0, 100, 0, 5000, 7000, 8000, 12000, 0, 11, 29577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Highland Mustang - In Combat - Cast 'Hoof Strike'"),
(23740, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 8000, 12000, 0, 11, 29577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Frosthorn Ram - In Combat - Cast 'Hoof Strike'"),
(29710, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 8000, 12000, 0, 11, 29577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Onslaught Destrier - In Combat - Cast 'Hoof Strike'");
