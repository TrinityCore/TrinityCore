DELETE FROM `spell_proc` WHERE `SpellId`= -78892;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_stampede', 'spell_dru_feral_charge', 'spell_dru_stampede_triggered');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(16979, 'spell_dru_feral_charge'),
(49376, 'spell_dru_feral_charge'),
(-81021, 'spell_dru_stampede_triggered');

DELETE FROM `spell_ranks` WHERE `first_spell_id`= 81021;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(81021, 81021, 1),
(81021, 81022, 2);
