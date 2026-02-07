DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_execute', 'spell_warr_execute_refund_rage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(163201, 'spell_warr_execute'),
(281000, 'spell_warr_execute'),
(260798, 'spell_warr_execute_refund_rage');
