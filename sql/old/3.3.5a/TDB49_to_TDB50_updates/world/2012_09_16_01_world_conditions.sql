DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=34379;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10,34379,50452,0,0,19,0,8,0,0,0,0,'', 'Wodin''s Lucky Necklace only 25 heroic'),
(10,34379,50453,0,0,19,0,8,0,0,0,0,'', 'Ring of Rotting Sinew only 25 heroic');
