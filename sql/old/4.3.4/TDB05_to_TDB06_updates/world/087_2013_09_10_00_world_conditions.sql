DELETE FROM `conditions` WHERE `SourceEntry` = 55983;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 55983, 0, 0, 31, 1, 3, 29974, 0, 0, 0, 0, '', 'Blow Hodir''s Horn can hit Niffelem Forefather'),
(17, 0, 55983, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Blow Hodir''s Horn can only hit dead Niffelem Forefather'),
(17, 0, 55983, 0, 1, 31, 1, 3, 30144, 0, 0, 0, 0, '', 'Blow Hodir''s Horn can hit Restless Frostborn Ghost'),
(17, 0, 55983, 0, 1, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Blow Hodir''s Horn can only hit dead Restless Frostborn Ghost'),
(17, 0, 55983, 0, 2, 31, 1, 3, 30135, 0, 0, 0, 0, '', 'Blow Hodir''s Horn can hit Restless Frostborn Warrior'),
(17, 0, 55983, 0, 2, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Blow Hodir''s Horn can only hit dead Restless Frostborn Warrior');
