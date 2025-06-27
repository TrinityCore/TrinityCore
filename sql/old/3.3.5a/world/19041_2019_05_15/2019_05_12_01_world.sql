-- 
UPDATE `creature_template` SET `unit_flags`=32768, `AIName`='SmartAI', `flags_extra`=0 WHERE `entry` IN (19762);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19762) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19762, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 15000, 17000, 11, 38233, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coilskar Defender - IC - cast spell Shield Bash"),
(19762, 0, 1, 0, 0, 0, 100, 0, 3000, 4000, 6000, 8000, 11, 38031, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Coilskar Defender - IC - cast spell Shield Block");
