DELETE FROM `spell_script_names` WHERE `spell_id` IN (42489,42485,42492);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42489, 'spell_ooze_zap'),
(42485, 'spell_ooze_zap_channel_end'),
(42492, 'spell_energize_aoe');
