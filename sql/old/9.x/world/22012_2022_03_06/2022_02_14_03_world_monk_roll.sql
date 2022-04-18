DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_monk_roll';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_monk_roll_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(109132, 'spell_monk_roll'),
(107427, 'spell_monk_roll_aura'),
(109131, 'spell_monk_roll_aura');
