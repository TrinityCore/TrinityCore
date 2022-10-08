delete from spell_script_names where spell_id = 51640;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(51640, 'spell_gen_taunt_flag_targeting');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 51640;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ScriptName`, `Comment`) VALUES 
(13, 1, 51640, 0, 0, 31, 0, 4, 0, 0, 0, '', NULL);