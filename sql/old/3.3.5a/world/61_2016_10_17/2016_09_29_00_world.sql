--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7304;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7304, 8666, 0, 0, 8, 0, 9293, 0, 0, 0, 0, 0, "", "Show text 8666 if player has quest 'What Must Be Done...' rewarded");

UPDATE `quest_template` SET `RewardNextQuest`=9294 WHERE `ID`=9293;
