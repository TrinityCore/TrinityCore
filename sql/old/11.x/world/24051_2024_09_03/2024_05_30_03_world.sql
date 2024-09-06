DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_sanctuary_trigger', 'spell_pri_sanctuary_absorb');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(585, 'spell_pri_sanctuary_trigger'),
(208771, 'spell_pri_sanctuary_absorb');
