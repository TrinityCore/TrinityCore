--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_submerged','spell_xt002_submerged');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37751,'spell_gen_submerged');
