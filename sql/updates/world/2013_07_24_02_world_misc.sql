-- Veil Skith: Darkstone of Terokk (10839) quest workaround by nelegalno
-- SAI should be removed once Rod of Purification (38729) spell is fixed
UPDATE `creature` SET `position_x` = -2512.73 , `position_y` = 5417.61 , `position_z` = 11.2102 WHERE `guid` = 78342;

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` = 22288;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22288 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22288, 0, 0, 0, 8, 0, 100, 0, 38736, 0, 0, 0, 26, 10839, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Darkstone of Terokk - on spellhit - cast quest credit");
