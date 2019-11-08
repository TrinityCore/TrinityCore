DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dru_stampeding_roar',
'spell_dru_feral_swiftness_clear');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77761, 'spell_dru_stampeding_roar'),
(77764, 'spell_dru_stampeding_roar'),
(97985, 'spell_dru_feral_swiftness_clear'),
(97993, 'spell_dru_feral_swiftness_clear');
