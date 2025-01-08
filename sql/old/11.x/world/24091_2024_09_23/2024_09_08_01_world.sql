DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_deaths_embrace';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_deaths_embrace_dots';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_deaths_embrace_drain_life';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(324540, 'spell_warl_deaths_embrace'),
(980, 'spell_warl_deaths_embrace_dots'),
(146739, 'spell_warl_deaths_embrace_dots'),
(316099, 'spell_warl_deaths_embrace_dots'),
(234153, 'spell_warl_deaths_embrace_drain_life');
