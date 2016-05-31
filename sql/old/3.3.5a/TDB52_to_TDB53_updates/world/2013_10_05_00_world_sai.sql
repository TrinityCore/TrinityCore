DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48188;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48188, 0, 0, 31, 0, 3, 27349, 0, 0, 0, 0, '', 'Flask of Blight Targets Scarlet Onslaught Prisoner');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=48188;

INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 48188, 64, '', '', 'Ignore LOS on Flask of Blight');
