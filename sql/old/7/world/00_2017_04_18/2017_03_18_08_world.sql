DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_charge_effect','spell_warr_charge_drop_fire_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(198337, 'spell_warr_charge_effect'),
(218104, 'spell_warr_charge_effect'),
(126661, 'spell_warr_charge_drop_fire_periodic');
