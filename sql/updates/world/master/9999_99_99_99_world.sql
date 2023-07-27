DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divine_hymn', 'spell_pri_divine_hymn_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(64844, 'spell_pri_divine_hymn_heal');
