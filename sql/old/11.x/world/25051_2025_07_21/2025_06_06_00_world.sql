DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_monk_burst_of_life', 'spell_monk_burst_of_life_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(116849, 'spell_monk_burst_of_life'),
(399230, 'spell_monk_burst_of_life_heal');
