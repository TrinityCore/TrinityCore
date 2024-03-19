-- Disable Deprecated Versions of Quests
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (9303,9305);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES 
(1,9303,0,'','','Deprecated Quest: Inoculation'),
(1,9305,0,'','','Deprecated Quest: Spare Parts');
-- Volatile Mutations Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=10302;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,10302,0,0,47,0,9280,64,0,'',0,0,0,'','Volatile Mutations available if quest Replenishing the Healing Crystals RaceMask 1024 is rewarded'),
(19,0,10302,0,1,47,0,9369,64,0,'',0,0,0,'','Volatile Mutations available if quest Replenishing the Healing Crystals RaceMask 18446744073709551615 is rewarded');
-- Ammen Vale Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (9312,37445);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) 
VALUES (37445,0,0,0,0,9312,-9311,0,0,0,0,0,0,0,0,0,0,0,''); -- Spare Parts
-- Unnecessary SpecialFlags
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID` IN (9279,9280,9283,9293,9294,9303,9309,9311,9369,9371,9409,9798,9799,10302,10303,10304);
-- Replenishing the Healing Crystals
UPDATE `quest_template_addon` SET `NextQuestID`=9409 WHERE `ID` IN (9280,9369);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0 WHERE `ID` IN (9280,9369);
-- Vindicator Aldar
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=37444 WHERE `ID`=10304;
-- The Missing Scout
UPDATE `quest_template_addon` SET `PrevQuestID`=37444 WHERE `ID`=9309;
-- Blood Elf Spy
UPDATE `quest_template_addon` SET `NextQuestID`=9312 WHERE `ID`=9311;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-9311 WHERE `ID`=9311;
