DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_seal_of_righteousness';
DELETE FROM `spell_script_names` WHERE `spell_id`=21084 AND `ScriptName`='spell_pal_seals';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(-20154,'spell_pal_seal_of_righteousness'),
(-20154,'spell_pal_seals');
