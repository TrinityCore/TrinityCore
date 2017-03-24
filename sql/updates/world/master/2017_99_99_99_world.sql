DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_whirlwind','spell_warr_trauma');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1680, 'spell_warr_whirlwind'),
(215538, 'spell_warr_trauma');
