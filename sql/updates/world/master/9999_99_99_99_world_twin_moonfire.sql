DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_twin_moonfire', 'spell_dru_twin_moons_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8921, 'spell_dru_twin_moonfire'),
(281847, 'spell_dru_twin_moons_effect');
