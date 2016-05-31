UPDATE `conditions` SET `ErrorType`=97,`ErrorTextId`=0 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=56765;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56765;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,56765,0,0,31,0,3,30446,0,0,0,'','Plant Chieftain''s Totem - Frostfloe Rift');
