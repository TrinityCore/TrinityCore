-- Add stampeding roar spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_stampeding_roar';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(106898, 'spell_dru_stampeding_roar');
