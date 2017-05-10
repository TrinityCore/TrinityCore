DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_running_wild';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_two_forms';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_darkflight';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(87840,'spell_gen_running_wild'),
(68996,'spell_gen_two_forms'),
(68992,'spell_gen_darkflight');
