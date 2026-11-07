DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_marrowrend_apply_bone_shield';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_deaths_caress_apply_bone_shield';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(195182, 'spell_dk_marrowrend_apply_bone_shield'),
(195292, 'spell_dk_deaths_caress_apply_bone_shield');
