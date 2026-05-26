-- Add pre quest for Unwelcome Guests quest
DELETE FROM `quest_template_addon` WHERE `ID`=12876;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(12876, 0, 0, 0, 12874, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
