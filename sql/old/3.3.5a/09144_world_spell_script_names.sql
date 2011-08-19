DELETE FROM `spell_script_names` WHERE `spell_id`=21977 AND `ScriptName`='spell_warr_warriors_wrath';
DELETE FROM `spell_script_names` WHERE `spell_id`=12975 AND `ScriptName`='spell_warr_last_stand';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(12975,'spell_warr_last_stand'),
(21977,'spell_warr_warriors_wrath');
