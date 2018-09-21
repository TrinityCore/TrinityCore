-- Condition for source Quest accept condition type Quest not taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=28652 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 28652, 0, 0, 14, 0, 24960, 0, 0, 0, 0, 0, '', 'Show quest Caretaker Caice if quest The Wakening has not been taken.');

UPDATE `quest_template_addon` SET `PrevQuestID`=28608 WHERE `ID`=24960;
