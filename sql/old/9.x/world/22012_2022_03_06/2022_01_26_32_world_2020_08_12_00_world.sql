DELETE FROM `spell_script_names` WHERE `ScriptName` IN ("spell_midsummer_fling_torch_triggered", "spell_midsummer_fling_torch_catch", "spell_midsummer_fling_torch_missed", "spell_midsummer_fling_torch");
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45669, "spell_midsummer_fling_torch_triggered"),
(45671, "spell_midsummer_fling_torch_catch"),
(45676, "spell_midsummer_fling_torch_missed"),
(46747, "spell_midsummer_fling_torch");
