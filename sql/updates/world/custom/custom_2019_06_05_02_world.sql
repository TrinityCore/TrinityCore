UPDATE `spell_area` SET `quest_start`= 14321 WHERE `spell`= 68482 AND `area`= 4714;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gilneas_worgen_intro_completion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(68638, 'spell_gilneas_worgen_intro_completion');
