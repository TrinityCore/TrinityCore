--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=20 AND `SourceEntry`=1789;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(20, 0, 1789, 0, 9, 1783, 0, 0, 0, '', 'Show the quest if 1783 is taken');
