DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (5066,5090,5091,5093,5094,5095,10373,10374);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 5066, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5066, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 5090, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5090, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 5091, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5091, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 5093, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5093, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 5094, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5094, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 5095, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 5095, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 10373, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 10373, 0, 0, 14, 0, 5092, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(19, 0, 10374, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)'),
(20, 0, 10374, 0, 0, 14, 0, 5096, 0, 0, 0, 0, 0, '', 'Call to Arms: The Plaguelands (Breadcrumb)');

UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE  `ID` IN (5066,5090,5091,5093,5094,5095,10373,10374);
