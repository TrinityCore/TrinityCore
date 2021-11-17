--
-- Chemist Fuely
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2501;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2501,3194,0,0,8,0,4642,0,0,1,0,0,"","Show gossip text 3194 if quest 'Melding of Influences' is not rewarded"),
(14,2501,3194,0,0,27,0,48,3,0,0,0,0,"","Show gossip text 3194 if player is level 48 or higher");
