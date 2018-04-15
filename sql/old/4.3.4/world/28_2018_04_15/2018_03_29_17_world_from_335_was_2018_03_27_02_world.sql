-- 
-- Fix prerequisite for quest "Feathers for Nafien"
UPDATE `quest_template_addon` SET `PrevQuestID`=8461 WHERE `ID`=8467;

-- Fix prerequisite for quest "Speak to Salfa"
DELETE FROM `quest_template_addon` WHERE `ID`=8465;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(8465,0,0,0,8461,0,0,0,0,0,0,0,0,0,0,0,0);
