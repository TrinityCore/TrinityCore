DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_monk_renewing_mist', 'spell_monk_renewing_mist_periodic_heal', 'spell_monk_renewing_mist_target_selector');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(115151,'spell_monk_renewing_mist'),
(119611,'spell_monk_renewing_mist_periodic_heal'),
(119607,'spell_monk_renewing_mist_target_selector');
