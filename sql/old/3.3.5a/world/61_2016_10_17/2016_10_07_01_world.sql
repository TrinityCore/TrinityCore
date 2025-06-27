DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_argent_dawn_commission','spell_warr_victorious','spell_dk_rune_strike_proc','spell_pet_charge');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(17670, 'spell_item_argent_dawn_commission'),
(32216, 'spell_warr_victorious'),
(56817, 'spell_dk_rune_strike_proc'),
(57627, 'spell_pet_charge');
