DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=9798 AND `type`=6;

DELETE FROM `spell_script_names` WHERE `spell_id`=63399;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(63399, 'spell_gen_tournament_pennant');
