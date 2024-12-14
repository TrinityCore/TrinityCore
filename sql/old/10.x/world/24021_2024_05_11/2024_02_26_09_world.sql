-- Mulgore Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (749,773,14438,26179,26180);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(773,0,0,0,20441,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Rite of Wisdom
(26179,0,0,0,751,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- The Venture Company
(26180,0,0,0,751,0,0,0,0,0,0,0,0,0,0,0,0,0,''); -- Supervisor Fizsprocket
-- Unneeded NextQuestIDs
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (6361,6362,6363,20441,24440,24441,24456,24457,24459,24523,24524,24550);
-- Winterhoof Cleansing
UPDATE `quest_template_addon` SET `PrevQuestID`=20440 WHERE `ID`=24440;
-- Morin Cloudstalker
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=749 WHERE `ID`=24459;
-- Wildmane Totem
UPDATE `quest_template_addon` SET `PrevQuestID`=24456 WHERE `ID`=24523;
-- Journey Into Thunder Bluff
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=24540 WHERE `ID`=24550;
-- War Dance
UPDATE `quest_template_addon` SET `PrevQuestID`=24524 WHERE `ID`=24540;
