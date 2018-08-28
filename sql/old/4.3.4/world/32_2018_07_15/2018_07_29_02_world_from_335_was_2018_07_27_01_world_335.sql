/*
-- 
-- Quest "Replacement Phial"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=3375;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,3375,0,0,14,0,2200,0,0,1,0,0,"","Quest 'Replacement Phial' can only be taken if quest 'Back to Uldaman' is taken"),
(19,0,3375,0,0,28,0,2204,0,0,1,0,0,"","Quest 'Replacement Phial' can only be taken if quest 'Restoring the Necklace' is not completed"),
(19,0,3375,0,0,8,0,2204,0,0,1,0,0,"","Quest 'Replacement Phial' can only be taken if quest 'Restoring the Necklace' is not rewarded"),
(19,0,3375,0,0,2,0,7667,1,1,1,0,0,"","Quest 'Replacement Phial' can only be taken if player does not have item 'Talvash's Phial of Scrying'");

DELETE FROM `quest_template_addon` WHERE `ID`=3375;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(3375,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1);
*/
