DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_enrage_rampage', 'spell_warr_enrage_bloodthirst', 'spell_warr_rampage_enrage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`)  VALUES
(184361, 'spell_warr_enrage_rampage'),
(184361, 'spell_warr_enrage_bloodthirst');
