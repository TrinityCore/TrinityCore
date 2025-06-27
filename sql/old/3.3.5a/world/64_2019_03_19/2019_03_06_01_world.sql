-- 
DELETE FROM `creature_template_addon` WHERE `entry`=25494;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (25494,"45655");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45656;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45656, 0, 0, 31, 0, 3, 25490, 0, 0, 0, 0, '', ''),
(13, 1, 45656, 0, 1, 31, 0, 3, 25492, 0, 0, 0, 0, '', ''),
(13, 1, 45656, 0, 2, 31, 0, 3, 25493, 0, 0, 0, 0, '', '');
UPDATE `creature` SET `position_x`=4023.2124, `position_y`= 3604.93457, `position_z`= 106.49082 WHERE `guid`=109772; 
UPDATE `creature` SET `position_x`=4125.8779, `position_y`=3638.740723, `position_z`= 93.987534 WHERE `guid`=85215; 
