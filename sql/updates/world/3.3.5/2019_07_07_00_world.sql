--
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_urom_frostbomb";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51103, "spell_urom_frostbomb");

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (51110, 51121);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(51110, 51110, 59377),
(51121, 51121, 59376);
