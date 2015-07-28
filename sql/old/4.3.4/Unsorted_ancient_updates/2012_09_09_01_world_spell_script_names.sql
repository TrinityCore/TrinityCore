DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_improved_spell_reflection', 'spell_warr_vigilance', 'spell_warr_charge', 'spell_warr_slam', 'spell_warr_execute', 'spell_warr_overpower');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES 
(100,'spell_warr_charge'),
(1464,'spell_warr_slam'),
(5308,'spell_warr_execute');
