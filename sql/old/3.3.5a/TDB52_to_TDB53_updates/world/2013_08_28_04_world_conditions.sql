DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup` IN (23980,31674,23954,31673);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,23954,43228,0,0,1,0,57940,0,0,0,0,0,'','Can loot Stone Keeper''s Shard only with aura Essence of Wintergrasp'),
(1,31673,43228,0,0,1,0,57940,0,0,0,0,0,'','Can loot Stone Keeper''s Shard only with aura Essence of Wintergrasp');
