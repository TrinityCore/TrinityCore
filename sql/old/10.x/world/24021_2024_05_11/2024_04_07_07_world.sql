-- Mind Devourer
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_mind_devourer', 'spell_pri_mind_devourer_buff');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8092, 'spell_pri_mind_devourer'),
(335467, 'spell_pri_mind_devourer_buff');
