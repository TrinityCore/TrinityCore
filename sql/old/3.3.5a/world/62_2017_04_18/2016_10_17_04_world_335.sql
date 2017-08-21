DELETE FROM `spell_proc` WHERE `SpellId`=-18213;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_drain_soul','spell_warl_improved_drain_soul');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-1120, 'spell_warl_drain_soul');
