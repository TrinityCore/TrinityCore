DELETE FROM `spell_scripts` WHERE `id` IN(37751,37752);	-- Remove redundant data from spell_scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN(37751,37752);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(37751,'spell_xt002_submerged'),
(37752,'spell_xt002_stand');
