-- Quest Template Addon
DELETE FROM `quest_template_addon` WHERE `ID` IN (35176, 35174, 35166, 34646, 34692, 36624, 34778, 33075);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(35176, 0, 0, 0, 34586, 34587, -35176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Keeping it Together
(35174, 0, 0, 0, 34586, 34587, -35176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Pale Moonlight
(35166, 0, 0, 0, 34586, 34587, -35176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ship Salvage
(34646, 0, 0, 0, 34587, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Qiana Moonshadow
(34692, 0, 0, 0, 34646, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Delegating on Draenor
(36624, 0, 0, 0, 34692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ashran Appearence
(34778, 0, 0, 0, 34692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Migrant Workers
(33075, 0, 0, 0, 34692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- A Heroes Welcome

-- Sidequests
DELETE FROM `quest_template_addon` WHERE `ID` IN (35343, 36310, 36262);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(35343, 0, 0, 0, 35342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Young Alchemist
(36310, 0, 0, 0, 36308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Arakkoan Enchanter
(36262, 0, 0, 0, 36236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Amekka, Master Tailor
