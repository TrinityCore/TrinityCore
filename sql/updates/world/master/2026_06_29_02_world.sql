--
DELETE FROM `spell_scripts` WHERE `id` IN (65797,66166,74083);
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_cast_caster_to_target' AND `spell_id` IN (65797,74083);
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_cancel_aura' AND `spell_id` IN (66166);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(65797,'spell_gen_cast_caster_to_target'),
(66166,'spell_gen_cancel_aura'),
(74083,'spell_gen_cast_caster_to_target');
