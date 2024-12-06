-- Use Dash only when in Cat Form
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry` IN (1850, 9821, 33357);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 1850, 0, 0, 1, 0, 768, 0, 0, 0, 172, 32, '', 'Use Dash Rank1 only when in Cat Form'),
(17, 0, 9821, 0, 0, 1, 0, 768, 0, 0, 0, 172, 32, '', 'Use Dash Rank2 only when in Cat Form'),
(17, 0, 33357, 0, 0, 1, 0, 768, 0, 0, 0, 172, 32, '', 'Use Dash Rank3 only when in Cat Form');
