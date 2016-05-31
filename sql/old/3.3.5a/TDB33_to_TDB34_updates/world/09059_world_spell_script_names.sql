DELETE FROM `spell_script_names` WHERE `spell_id`=53271 AND `ScriptName`='spell_hun_masters_call';
DELETE FROM `spell_script_names` WHERE `spell_id`=53478 AND `ScriptName`='spell_hun_last_stand_pet';
DELETE FROM `spell_script_names` WHERE `spell_id`=23989 AND `ScriptName`='spell_hun_readiness';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53271,'spell_hun_masters_call'),
(53478,'spell_hun_last_stand_pet'),
(23989,'spell_hun_readiness');
