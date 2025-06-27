DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=12932;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 12932, 0, 0, 8, 0, 9977, 0, 0, 1, 0, 0, '', 'Quest "The Amphitheater of Anguish: Yggdras!" non-champion version can only be taken if "The Ring of Blood: The Final Challenge" is not rewarded');
