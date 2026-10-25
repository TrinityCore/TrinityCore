DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_fel_rush', 'spell_dh_fel_rush_aura', 'spell_dh_fel_rush_knockback');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(195072, 'spell_dh_fel_rush'),
(197923, 'spell_dh_fel_rush_aura'),
(197922, 'spell_dh_fel_rush_aura'),
(346123, 'spell_dh_fel_rush_knockback');
