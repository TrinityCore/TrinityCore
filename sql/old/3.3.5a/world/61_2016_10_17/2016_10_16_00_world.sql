--
DELETE FROM `conditions` WHERE `SourceGroup`=9754;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9754, 13397, 0, 0, 8, 0, 12716, 0, 0, 0, 0, 0, "", "Show gossip text 13397 for Noth the Plaguebringer if quest The Plaguebringer's Request is rewarded");

DELETE FROM `creature_questender` WHERE `quest`=12717;
