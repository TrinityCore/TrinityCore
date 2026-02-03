DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_thrash');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77758, 'spell_dru_thrash'),
(106830, 'spell_dru_thrash');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_dru_thrash_bear_bleed' WHERE `spell_id` = 192090 AND `ScriptName` = 'spell_dru_thrash_aura';
