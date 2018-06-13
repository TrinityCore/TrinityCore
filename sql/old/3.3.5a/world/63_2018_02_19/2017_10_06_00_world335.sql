UPDATE `quest_template_addon` SET `PrevQuestID` =0 WHERE `ID`IN(10899,10902,10897);
UPDATE `quest_template_addon` SET `NextQuestID` =0 WHERE `ID`IN(10907,10906,10905);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =19 AND `SourceEntry`IN(10907,10906,10905) AND `ConditionTypeOrReference`=14 AND `ConditionValue1`IN(10899,10902,10897);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 10907, 0, 0, 14, 0, 10899, 0, 0, 0, 0, 0, '', 'Master of Transmutation 1/2 is Optional BreadCrumb Quest'),
(19, 0, 10906, 0, 0, 14, 0, 10902, 0, 0, 0, 0, 0, '', 'Master of Elixirs 1/2 is Optional BreadCrumb Quest'),
(19, 0, 10905, 0, 0, 14, 0, 10897, 0, 0, 0, 0, 0, '', 'Master of Potions 1/2 is Optional BreadCrumb Quest');
