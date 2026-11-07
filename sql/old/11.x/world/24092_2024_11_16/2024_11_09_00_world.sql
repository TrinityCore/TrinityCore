DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_airborne_irritant','spell_rog_airborne_irritant_target_selection');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(2094, 'spell_rog_airborne_irritant'),
(427773, 'spell_rog_airborne_irritant_target_selection');
