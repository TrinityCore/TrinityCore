-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=18266 AND `SourceEntry`=31799;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 18266, 31799, 0, 0, 9, 0, 10916, 0, 0, 0, 0, 0, "", "Show item 'Fei Fei Doggy Treat' from vendor 'Warrant Officer Tracy Proudwell' if player has quest 'Digging for Prayer Beads' taken");
