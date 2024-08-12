DELETE FROM `spell_script_names` WHERE `spell_id` IN (324540, 980, 146739, 316099) AND `ScriptName`='spell_warl_deaths_embrace';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(324540, 'spell_warl_deaths_embrace'),
(980, 'spell_warl_deaths_embrace'),
(146739, 'spell_warl_deaths_embrace'),
(316099, 'spell_warl_deaths_embrace');

DELETE FROM `spell_script_names` WHERE `spell_id`=234153 AND `ScriptName`='spell_warl_drain_life';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(234153, 'spell_warl_drain_life');
