UPDATE `achievement_criteria_data` SET `type`=6, `value1`=4395 WHERE `criteria_id`=6937;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ("spell_midsummer_juggle_torch", "spell_midsummer_torch_catch");
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45819, "spell_midsummer_juggle_torch"),
(45644, "spell_midsummer_torch_catch");
