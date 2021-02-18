-- Add thrash spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_thrash';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(77758, 'spell_dru_thrash');
