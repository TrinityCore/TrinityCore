-- Quest "Ferry Pass" ID: 52128
DELETE FROM `creature_queststarter` WHERE (`id`=122370 AND `quest`=52128) OR (`id`=121235 AND `quest`=47186) OR (`id`=121235 AND `quest`=47189);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(122370, 52128, 53040), -- Ferry Pass offered by Cyrus Crestfall
(121235, 47186, 53040), -- Sanctum of the Sages offered by Taelia
(121235, 47189, 53040); -- A Nation Divided offered by Taelia

DELETE FROM `creature_questender` WHERE (`id`=122370 AND `quest`=52128) OR (`id`=121235 AND `quest`=47186) OR (`id`=121235 AND `quest`=47189);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(122370, 52128, 53040), -- Ferry Pass ended by Cyrus Crestfall
(121235, 47186, 53040), -- Sanctum of the Sages ended by Taelia
(121235, 47189, 53040); -- A Nation Divided ended by Taelia

DELETE FROM `quest_template_addon` WHERE `ID` IN (52128, 47186);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(52128, 0, 0, 0, 46729, 47189, -52128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(47186, 0, 0, 0, 46729, 47189, -52128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
