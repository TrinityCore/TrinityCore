-- Spellscripts for "Toss your Luck!"
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_titanium_seal_of_dalaran_toss','spell_item_titanium_seal_of_dalaran_catch');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60458, 'spell_item_titanium_seal_of_dalaran_toss'),
(60476, 'spell_item_titanium_seal_of_dalaran_catch');
