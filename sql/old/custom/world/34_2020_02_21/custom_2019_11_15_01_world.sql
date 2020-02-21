DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_magmaw_eject_passenger';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78643, 'spell_magmaw_eject_passenger');

DELETE FROM `conditions` WHERE `SourceEntry`= 78643 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 78643, 0, 0, 31, 0, 3, 41789, 0, 0, 0, '', 'Eject Passenger - Target Magmaw''s Pincer'),
(13, 1, 78643, 0, 1, 31, 0, 3, 41620, 0, 0, 0, '', 'Eject Passenger - Target Magmaw''s Pincer');
