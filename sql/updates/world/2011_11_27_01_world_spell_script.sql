DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_damage_reduction_aura' AND `spell_id`=50720;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_vigilance';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50720,'spell_warr_vigilance'); -- Vigilance