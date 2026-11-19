--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_take_sputum_sample' WHERE `ScriptName` = 'spell_q12683_take_sputum_sample';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sholazar_sputum_collected';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(52306,'spell_sholazar_sputum_collected');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_song_of_cleansing' WHERE `ScriptName` = 'spell_q12735_song_of_cleansing';
