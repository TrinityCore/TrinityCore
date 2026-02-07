DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_execute', 'spell_warr_execute_refund_rage');
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_execute_damage') AND `spell_id` IN (317483);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(163201, 'spell_warr_execute'),
(281000, 'spell_warr_execute'),
(330334, 'spell_warr_execute'),
(317349, 'spell_warr_execute'),
(317483, 'spell_warr_execute_damage'),
(260798, 'spell_warr_execute_refund_rage');
