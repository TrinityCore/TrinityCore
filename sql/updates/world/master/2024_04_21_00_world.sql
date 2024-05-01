-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`=96733 AND `ScriptName` LIKE 'spell_gen_feign_death_%';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_feign_death_all_flags_no_uninteractible';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96733, 'spell_gen_feign_death_all_flags_no_uninteractible');
