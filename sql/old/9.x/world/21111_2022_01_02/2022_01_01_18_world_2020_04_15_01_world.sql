-- 
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN(13147,13160,13146,13161,13162,13163,13164);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 13161, 0, 0, 8, 0, 13146, 0, 0, 0, 0, 0, '', 'Accepting The Rider of the Unholy requires Generosity Abounds to be rewarded'),
(19, 0, 13161, 0, 0, 8, 0, 13160, 0, 0, 0, 0, 0, '', 'Accepting The Rider of the Unholy requires Stunning View to be rewarded'),
(19, 0, 13161, 0, 0, 8, 0, 13147, 0, 0, 0, 0, 0, '', 'Accepting The Rider of the Unholy requires Matchmaker to be rewarded'),
(19, 0, 13162, 0, 0, 8, 0, 13146, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Frost requires Generosity Abounds to be rewarded'),
(19, 0, 13162, 0, 0, 8, 0, 13160, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Frost requires Stunning View to be rewarded'),
(19, 0, 13162, 0, 0, 8, 0, 13147, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Frost requires Matchmaker to be rewarded'),
(19, 0, 13163, 0, 0, 8, 0, 13146, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Blood requires Generosity Abounds to be rewarded'),
(19, 0, 13163, 0, 0, 8, 0, 13160, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Blood requires Stunning View to be rewarded'),
(19, 0, 13163, 0, 0, 8, 0, 13147, 0, 0, 0, 0, 0, '', 'Accepting The Rider of Blood requires Matchmaker to be rewarded');

UPDATE `quest_template_addon` SET `ExclusiveGroup`=-13146,`NextQuestID`=13161 WHERE  `ID` IN(13146,13147,13160);
UPDATE `quest_template_addon` SET `PrevQuestID`=13146,`ExclusiveGroup`=-13161 WHERE  `ID` IN(13161,13162,13163);

DELETE FROM `quest_template_addon` WHERE `ID`=13164;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(13164, 0, 0, 0, 13161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
