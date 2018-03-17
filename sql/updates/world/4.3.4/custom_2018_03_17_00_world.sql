DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_warl_drain_life',
'spell_warl_drain_life_heal');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(689, 'spell_warl_drain_life'),
(89420, 'spell_warl_drain_life'),
(89653, 'spell_warl_drain_life_heal');
