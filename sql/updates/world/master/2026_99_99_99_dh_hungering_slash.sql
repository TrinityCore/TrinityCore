DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_hungering_slash', 'spell_dh_hungering_slash_enabler', 'spell_dh_hungering_slash_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1239123, 'spell_dh_hungering_slash'),
(1246167, 'spell_dh_hungering_slash_enabler'),
(1245412, 'spell_dh_hungering_slash_enabler'),
(1239127, 'spell_dh_hungering_slash_damage');
