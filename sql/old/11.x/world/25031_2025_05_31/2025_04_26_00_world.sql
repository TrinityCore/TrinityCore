-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (49242 /*Quill or Be Quilled*/, 48165 /*Harmful If Swallowed*/, 48170 /*Once Bitten, Twice Shy*/, 48113 /*A Pungent Solution*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(49242, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Quill or Be Quilled
(48165, 1, 0, 0, 0, 0, 0, 0, 0, 60490), -- Harmful If Swallowed
(48170, 1, 0, 0, 0, 0, 0, 0, 0, 60490), -- Once Bitten, Twice Shy
(48113, 1, 0, 0, 0, 0, 0, 0, 0, 60490); -- A Pungent Solution

DELETE FROM `creature_queststarter` WHERE (`id`=128494 AND `quest`=49242) OR (`id`=125380 AND `quest` IN (48165,48170,48113));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(128494, 49242, 60490), -- Quill or Be Quilled offered by Adela Hawthorne
(125380, 48165, 60490), -- Harmful If Swallowed offered by Lucille Waycrest
(125380, 48170, 60490), -- Once Bitten, Twice Shy offered by Lucille Waycrest
(125380, 48113, 60490); -- A Pungent Solution offered by Lucille Waycrest

DELETE FROM `creature_questender` WHERE (`id`=128494 AND `quest`=49242) OR (`id`=125380 AND `quest` IN (48113,48170,48165));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(128494, 49242, 60490), -- Quill or Be Quilled ended by Adela Hawthorne
(125380, 48113, 60490), -- A Pungent Solution ended by Lucille Waycrest
(125380, 48170, 60490), -- Once Bitten, Twice Shy ended by Lucille Waycrest
(125380, 48165, 60490); -- Harmful If Swallowed ended by Lucille Waycrest

DELETE FROM `quest_template_addon` WHERE `ID` IN (49242, 48113, 48170, 48165);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(49242, 0, 0, 0, 48111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Quill or Be Quilled
(48113, 0, 0, 0, 48111, 48198, -48113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- A Pungent Solution
(48170, 0, 0, 0, 48111, 48198, -48113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Once Bitten, Twice Shy
(48165, 0, 0, 0, 48111, 48198, -48113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Harmful If Swallowed
