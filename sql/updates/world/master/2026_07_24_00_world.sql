-- Questchains
DELETE FROM `quest_template_addon` WHERE `ID` IN (25357,25546,25545,25564,25558);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(25357, 0, 0, 0, 25405, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Buy Us Some Time
(25546, 0, 0, 0, 25405, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Traveling on Our Stomachs
(25545, 0, 0, 0, 0, 25547, -25545, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- To Arms!
(25564, 0, 0, 0, 0, 25547, -25545, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Stormwind Elite Aquatic and Land Forces
(25558, 0, 0, 0, 25547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- All or Nothing

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (25545));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 25545, 0, 0, 8, 0, 25357, 0, 0, '', 0, 'Player has quest Buy Us Some Time (25357) rewarded'),
(19, 0, 25545, 0, 0, 8, 0, 25546, 0, 0, '', 0, 'Player has quest Traveling on Our Stomachs (25546) rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (25564));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 25564, 0, 0, 8, 0, 25357, 0, 0, '', 0, 'Player has quest Buy Us Some Time (25357) rewarded'),
(19, 0, 25564, 0, 0, 8, 0, 25546, 0, 0, '', 0, 'Player has quest Traveling on Our Stomachs (25546) rewarded');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=25545;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25545, 0, 0, 0, 0, 0, 0, 0, 0, 68887); -- To Arms!

UPDATE `quest_details` SET `Emote2`=0, `VerifiedBuild`=68887 WHERE `ID`=25546; -- Traveling on Our Stomachs
UPDATE `quest_details` SET `Emote2`=0, `VerifiedBuild`=68887 WHERE `ID`=25357; -- Buy Us Some Time

DELETE FROM `quest_details` WHERE `ID` IN (25547 /*On Our Own Terms*/, 25467 /*Kliklak's Craw*/, 25564 /*Stormwind Elite Aquatic and Land Forces*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25547, 396, 5, 396, 0, 0, 1000, 1000, 0, 68887), -- On Our Own Terms
(25467, 0, 0, 0, 0, 0, 0, 0, 0, 68887), -- Kliklak's Craw
(25564, 0, 0, 0, 0, 0, 0, 0, 0, 68887); -- Stormwind Elite Aquatic and Land Forces
