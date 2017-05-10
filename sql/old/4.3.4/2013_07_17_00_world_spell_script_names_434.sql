DELETE FROM `spell_script_names` WHERE `spell_id` IN (29834,29838,29841,29842,42770,42771);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
-- Warrior
(29834,'spell_warr_second_wind_proc'),
(29838,'spell_warr_second_wind_proc'),
(29841,'spell_warr_second_wind_trigger'),
(29842,'spell_warr_second_wind_trigger'),
-- Utgarde Keep
(42770,'spell_uk_second_wind_proc');
