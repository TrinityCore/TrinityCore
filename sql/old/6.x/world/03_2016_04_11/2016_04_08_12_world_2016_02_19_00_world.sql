UPDATE `quest_template_addon` SET `PrevQuestID` =0 WHERE `ID` IN(24536,24655);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`IN(24805,24804) AND `ConditionTypeOrReference`=14 AND `ConditionValue1` IN(24536,24655);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 24805, 0, 0, 14, 0, 24536, 0, 0, 0, 0, 0, '', 'Uncommon Scents is optional BreadCrumb Quest'),
(20, 0, 24805, 0, 0, 14, 0, 24536, 0, 0, 0, 0, 0, '', 'Uncommon Scents is optional BreadCrumb Quest'),
(19, 0, 24804, 0, 0, 14, 0, 24655, 0, 0, 0, 0, 0, '', 'Uncommon Scents is optional BreadCrumb Quest'),
(20, 0, 24804, 0, 0, 14, 0, 24655, 0, 0, 0, 0, 0, '', 'Uncommon Scents is optional BreadCrumb Quest');
