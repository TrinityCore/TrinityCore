DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_sanctuary', 'spell_pri_sanctuary_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(585, 'spell_pri_sanctuary'),
(208772, 'spell_pri_sanctuary_aura');
