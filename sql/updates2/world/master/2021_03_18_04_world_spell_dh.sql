UPDATE `areatrigger_template` SET `ScriptName` = 'at_dh_sigil_of_flame' WHERE `Id` = 10727;
DELETE FROM `spell_script_names` WHERE spell_id IN (204022, 178740, 258920, 258922);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(258920, "spell_dh_immolation_aura"),
(258922, "spell_dh_immolation_damage");
