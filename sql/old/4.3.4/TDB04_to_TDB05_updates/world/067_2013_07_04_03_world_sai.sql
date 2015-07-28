-- Quest: Standards and Practices (9910) / Ignore LOS for trigger spell
SET @SPELL  := 32205; -- Place Mag'har Battle Standard

DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` = @SPELL;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, @SPELL, 64, '', '', 'Ignore LOS for Place Mag''har Battle Standard');

-- Quest: Hand of Iruxos (5381) / Attack Closest Player - Demon Spirit
SET @ENTRY	:= 11876; -- Demon Spirit

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Demon Spirit - Just Summoned - Attack Closest Player');
