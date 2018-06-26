/*
-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (4975,4964);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,4975,0,0,8,0,4963,0,0,0,0,0,"","Quest 'The Completed Orb of Noh'Orahil' can only be taken if quest 'Shard of an Infernal' is rewarded"),
(19,0,4964,0,0,8,0,4962,0,0,0,0,0,"","Quest 'The Completed Orb of Dar'Orahil' can only be taken if quest 'Shard of a Felhound' is rewarded");
*/
