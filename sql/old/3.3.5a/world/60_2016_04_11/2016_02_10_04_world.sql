-- Honor among thieves
DELETE FROM `spell_script_names` WHERE `scriptname` = 'spell_rog_honor_among_thieves';
DELETE FROM `spell_script_names` WHERE `scriptname` = 'spell_rog_honor_among_thieves_proc';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-51698, 'spell_rog_honor_among_thieves'),
(52916, 'spell_rog_honor_among_thieves_proc');
