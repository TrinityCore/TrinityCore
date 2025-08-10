-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (25190,25193,25194);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,25190,0,0,47,0,25188,8,0,'',0,0,0,'','Raggarans Rage available if quest Watershed Patrol is in progress'),
(19,0,25193,0,0,47,0,25188,8,0,'',0,0,0,'','Lost but Not Forgotten available if quest Watershed Patrol is in progress'),
(19,0,25194,0,0,47,0,25188,8,0,'',0,0,0,'','Unbidden Visitors available if quest Watershed Patrol is in progress');
-- Durotar Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (835,25167,25169,25171,25173,25176,25178,25179,25206,25257,25258,25259);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(25169,0,0,0,25167,25171,-25168,0,0,0,0,0,0,0,0,0,0,0,''), -- The War of Northwatch Aggression
(25173,0,0,0,25171,25178,-25173,0,0,0,0,0,0,0,0,0,0,0,''), -- From Bad to Worse
(25176,0,0,0,25171,25178,-25173,0,0,0,0,0,0,0,0,0,0,0,''), -- Exploiting the Situation
(25179,0,0,0,25173,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Loss Reduction
(25206,0,0,0,25205,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Ignoring the Warnings
(25257,0,0,0,25256,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Ghislania
(25258,0,0,0,25256,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Griswold Hanniston
(25259,0,0,0,25256,0,0,0,0,0,0,0,0,0,0,0,0,0,''); -- Gaur Icehorn
-- Purge the Valley Exclusive Group (Contains The War of Northwatch Aggression)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-25168 WHERE `ID`=25168;
UPDATE `quest_template_addon` SET `NextQuestID`=25169 WHERE `ID`=25168;
-- Thonk
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=25187 WHERE `ID`=25227;
-- Lost in the Floods
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=25187;
-- Arnak Fireblade
UPDATE `quest_template_addon` SET `PrevQuestID`=25262 WHERE `ID`=25263;
