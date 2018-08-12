/*
-- 
DELETE FROM `quest_template_addon` WHERE `ID`=1268;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(1268,0,0,0,0,1276,-1323,0,0,0,0,0,0,0,0,0,0); -- Quest "Suspicious Hoofprints"

UPDATE `quest_template_addon` SET `ExclusiveGroup`=-1323, `NextQuestID`=1276 WHERE `ID` IN (1323,1273); -- Quests "The Black Shield (Part 4)" / "Questioning Reethe"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1276; -- Quest "The Black Shield (Part 5)"
UPDATE `quest_template_addon` SET `PrevQuestID`=1276 WHERE `ID`=11204; -- Quest "Return to Krog"
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-11201, `NextQuestID`=11203 WHERE `ID` IN (11201,11200); -- Quests "The Grimtotem Plot" / "More than Coincidence"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=11203; -- Quest "Seek Out Tabetha"
*/
