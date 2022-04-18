-- Argent Skytalon
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN(30228);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(30228, 1, 0, 2, 0, 0, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=30228 AND `ConditionTypeOrReference`=23;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(16,0,30228,0,0,23,0,4501,0,0,0,0,0,'','Argent Skytalon Dismount player when not in intended zone'),
(16,0,30228,0,1,23,0,4506,0,0,0,0,0,'','Argent Skytalon Dismount player when not in intended zone'),
(16,0,30228,0,2,23,0,4504,0,0,0,0,0,'','Argent Skytalon Dismount player when not in intended zone'),
(16,0,30228,0,3,23,0,4505,0,0,0,0,0,'','Argent Skytalon Dismount player when not in intended zone'),
(16,0,30228,0,4,23,0,4580,0,0,0,0,0,'','Argent Skytalon Dismount player when not in intended zone');
