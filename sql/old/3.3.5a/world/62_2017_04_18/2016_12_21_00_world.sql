-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN (13,17) AND `SourceEntry`=30218;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 30218, 0, 0, 31, 1, 3, 17274, 0, 0, 0, 0, '', 'Fireball only target Temper''s Target');

DELETE FROM `gameobject_addon` WHERE `guid`=30031;
