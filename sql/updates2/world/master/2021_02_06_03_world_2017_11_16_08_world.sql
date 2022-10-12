-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=42564;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42564, 0, 0, 29, 0, 23921, 20, 0, 0, 0, 0, "", "Spell 'Ever-burning Torch' can be used within 20 yards of 'Halgrind Torch Bunny 01' OR"),
(17, 0, 42564, 0, 1, 29, 0, 23922, 20, 0, 0, 0, 0, "", "Spell 'Ever-burning Torch' can be used within 20 yards of 'Halgrind Torch Bunny 02' OR"),
(17, 0, 42564, 0, 2, 29, 0, 23923, 20, 0, 0, 0, 0, "", "Spell 'Ever-burning Torch' can be used within 20 yards of 'Halgrind Torch Bunny 03' OR"),
(17, 0, 42564, 0, 3, 29, 0, 23924, 20, 0, 0, 0, 0, "", "Spell 'Ever-burning Torch' can be used within 20 yards of 'Halgrind Torch Bunny 04'");
