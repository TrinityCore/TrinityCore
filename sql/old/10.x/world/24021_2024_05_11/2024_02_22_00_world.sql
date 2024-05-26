-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=14461;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,14461,0,0,47,0,14455,64,0,'',0,0,0,'','Feed of Evil available if quest Stop the Thorncallers is rewarded'),
(19,0,14461,0,0,47,0,14456,64,0,'',0,0,0,'','Feed of Evil available if quest Rite of Courage is rewarded');
-- Camp Narache Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (14449,14455,14456,14460);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES 
(14455,0,0,0,14458,14459,-14455,0,0,0,0,0,0,0,0,0,0,0,''), -- Stop the Thorncallers
(14456,0,0,0,14458,14459,-14455,0,0,0,0,0,0,0,0,0,0,0,''); -- Rite of Courage
-- Unnecessary NextQuestIDs
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (14452,23733,24852,24861);
-- The Battleboars and Feed of Evil ExclusiveGroup
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-14459 WHERE `ID` IN (14459,14461);
