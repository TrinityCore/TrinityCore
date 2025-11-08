-- Add pre quest for Loyal Companions quest
DELETE FROM `quest_template_addon` WHERE `ID`=12865;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(12865, 0, 0, 0, 12863, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
