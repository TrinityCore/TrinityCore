-- 
UPDATE `quest_template_addon` SET `NextQuestID` = 0 WHERE `id` IN (10644,10633);
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `id` IN (10639,10645);
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `ExclusiveGroup` = 0 WHERE `id` IN (10634,10635,10636);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 19 AND `SourceEntry` IN (10634, 10635, 10636, 10645, 10639);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 10634, 0, 0, 8, 0, 10644, 0, 0, 0, 0, 0, '', 'Quest 10634 available if Quest 10644 OR'),
(19, 0, 10634, 0, 1, 8, 0, 10633, 0, 0, 0, 0, 0, '', 'Quest 10634 available if Quest 10633 Rewarded'),
(19, 0, 10635, 0, 0, 8, 0, 10644, 0, 0, 0, 0, 0, '', 'Quest 10635 available if Quest 10644 OR'),
(19, 0, 10635, 0, 1, 8, 0, 10633, 0, 0, 0, 0, 0, '', 'Quest 10635 available if Quest 10633 Rewarded'),
(19, 0, 10636, 0, 0, 8, 0, 10644, 0, 0, 0, 0, 0, '', 'Quest 10636 available if Quest 10644 OR'),
(19, 0, 10636, 0, 1, 8, 0, 10633, 0, 0, 0, 0, 0, '', 'Quest 10636 available if Quest 10633 Rewarded'),
(19, 0, 10645, 0, 1, 8, 0, 10634, 0, 0, 0, 0, 0, '', 'Quest 10645 available if Quest 10634 AND'),
(19, 0, 10645, 0, 1, 8, 0, 10635, 0, 0, 0, 0, 0, '', 'Quest 10645 available if Quest 10633 AND'),
(19, 0, 10645, 0, 1, 8, 0, 10636, 0, 0, 0, 0, 0, '', 'Quest 10645 available if Quest 10636 Rewarded'),
(19, 0, 10639, 0, 1, 8, 0, 10634, 0, 0, 0, 0, 0, '', 'Quest 10639 available if Quest 10634 AND'),
(19, 0, 10639, 0, 1, 8, 0, 10635, 0, 0, 0, 0, 0, '', 'Quest 10639 available if Quest 10633 AND'),
(19, 0, 10639, 0, 1, 8, 0, 10636, 0, 0, 0, 0, 0, '', 'Quest 10639 available if Quest 10636 Rewarded');
