--
DELETE FROM `quest_template_addon` WHERE `ID` IN (26150, 46);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(26150,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0),
(46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); 

DELETE FROM `creature_loot_template` WHERE `Entry`=13159 AND `Item`=1307;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(13159,1307,0,100,0,1,0,1,1,NULL);
