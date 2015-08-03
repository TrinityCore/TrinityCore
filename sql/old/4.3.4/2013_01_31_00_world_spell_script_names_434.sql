DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_demon_soul', 'spell_warl_conflagrate', 'spell_warl_fel_flame');
DELETE FROM `spell_script_names` WHERE  `spell_id` IN (17962, 77799, 77801);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(17962, 'spell_warl_conflagrate'),
(77799, 'spell_warl_fel_flame'),
(77801, 'spell_warl_demon_soul');
