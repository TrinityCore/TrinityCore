-- Westbrook Garrison Needs Help
DELETE FROM `quest_template_addon` WHERE `ID`=239;
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(239,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,'');
-- Cloth and Leather Armor and The Jasperlode Mine
UPDATE `quest_template_addon` SET `NextQuestID`=239 WHERE `ID` IN (59,76);
-- Young Lovers
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=106;
-- A Visit With Maybell
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=106 WHERE `ID`=26150;
