/*
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_eclipse';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(-48516, 'spell_dru_eclipse');

UPDATE `spell_proc_event` SET `Cooldown`=0 WHERE `entry`=-48516; -- set cooldown to 0, handled by a script
*/
