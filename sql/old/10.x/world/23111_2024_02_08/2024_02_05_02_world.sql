DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_dark_indulgence', 'spell_pri_schism');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(8092, 'spell_pri_dark_indulgence'),
(8092, 'spell_pri_schism');
