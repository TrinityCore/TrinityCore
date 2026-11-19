-- 
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-13119 WHERE `ID`=13119;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-13119 WHERE `ID`=13120;
UPDATE `quest_template_addon` SET `PrevQuestID`=13140, `ExclusiveGroup`=-13152 WHERE `ID`=13152;
UPDATE `quest_template_addon` SET `PrevQuestID`=13140, `ExclusiveGroup`=-13152 WHERE `ID`=13211;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=13120;
DELETE FROM `quest_template_addon` WHERE `ID` IN (13134,13140,13144,13138);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(13134, 0, 0, 0, 13119, 13140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(13140, 0, 0, 0, 13136, 0, -13140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(13138, 0, 0, 0, 13136, 0, -13140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(13144, 0, 0, 0, 13152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
