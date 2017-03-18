-- 
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `id` IN (415, 618, 8554);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 19 AND `SourceEntry`= 619;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19, 0, 619, 0, 0, 9, 0, 618, 0, 0, 0, 0, 0, '', "Enticing Negolash"),
(19, 0, 619, 0, 1, 9, 0, 8554, 0, 0, 0, 0, 0, '', "Enticing Negolash");
UPDATE `quest_template_addon` SET `PrevQuestID`=12294, `NextQuestID`=12225, `ExclusiveGroup`=-12222 WHERE `id` IN (12222);
UPDATE `quest_template_addon` SET `PrevQuestID`=12294, `NextQuestID`=12225, `ExclusiveGroup`=-12222 WHERE `id` IN (12223);
