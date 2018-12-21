UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 48097;

DELETE FROM `conditions` WHERE `SourceEntry`= 85017 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 85017, 0, 0, 31, 0, 3, 48097, 0, 0, 0, '', 'Slipstream - Target Wind Tunnel Landing Zone'),
(13, 1, 85017, 0, 1, 31, 0, 3, 45504, 0, 0, 0, '', 'Slipstream - Target Slipstream Landing Zone');
