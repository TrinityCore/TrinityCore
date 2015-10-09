UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=13308;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry`=13308;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 13308, 0, 0, 8, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Rewarded or'),
(20, 0, 13308, 0, 0, 8, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Rewarded or'),
(19, 0, 13308, 0, 1, 9, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Taken or'),
(20, 0, 13308, 0, 1, 9, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Taken or'),
(19, 0, 13308, 0, 2, 28, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Complete or'),
(20, 0, 13308, 0, 2, 28, 0, 13224, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires Orgrims Hammer Complete or'),
(19, 0, 13308, 0, 3, 8, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Rewarded or'),
(20, 0, 13308, 0, 3, 8, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Rewarded or'),
(19, 0, 13308, 0, 4, 9, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Taken or'),
(20, 0, 13308, 0, 4, 9, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Taken or'),
(19, 0, 13308, 0, 5, 28, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Complete or'),
(20, 0, 13308, 0, 5, 28, 0, 13225, 0, 0, 0, 0, 0, '', 'Mind Tricks Requires The Skybreaker Complete or');
