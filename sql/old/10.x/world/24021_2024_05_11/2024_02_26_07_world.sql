-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (25986,25987,25792);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,25792,0,0,47,0,313,64,0,'',0,0,0,'','Pushing Foward available if quest Forced to Watch From Afar is rewarded'),
(19,0,25792,0,0,47,0,25667,64,0,'',0,0,0,'','Pushing Foward available if quest Culling the Wendigos is rewarded');
-- Dun Morogh Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (313,314,384,412,432,25667,25668,25724,25840,25905,25978,25979,25986);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(313,0,0,0,25724,412,-313,0,0,0,0,0,0,0,0,0,0,0,''), -- Forced to Watch From Afar
(314,0,0,0,25932,25933,-314,0,0,0,0,0,0,0,0,0,0,0,''), -- Protecting the Herd
(412,0,0,0,0,25838,-412,0,0,0,0,0,0,0,0,0,0,0,''), -- Operation Recombobulation
(432,0,0,0,0,25986,-432,0,0,0,0,0,0,0,0,0,0,0,''), -- Those Blasted Troggs
(25667,0,0,0,25724,412,-313,0,0,0,0,0,0,0,0,0,0,0,''), -- Culling the Wendigos
(25668,0,0,0,25724,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Pilfered Supplies
(25840,0,0,0,25839,25882,-25840,0,0,0,0,0,0,0,0,0,0,0,''), -- Eliminate the Resistance
(25905,0,0,0,25932,25933,-314,0,0,0,0,0,0,0,0,0,0,0,''), -- Rams on the Lam
(25978,0,0,0,0,25997,-25978,0,0,0,0,0,0,0,0,0,0,0,''), -- Entombed In Ice
(25979,0,0,0,0,25997,-25978,0,0,0,0,0,0,0,0,0,0,0,''), -- Dealing With the Surge
(25986,0,0,0,0,0,0,25978,0,0,0,0,0,0,0,0,0,0,''); -- Trouble at the Lake
-- On to Kharanos
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=25724 WHERE `ID`=26373;
-- Pushing Foward (Exclusive Group contains Operation Recombobulation)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-412 WHERE `ID`=25792;
UPDATE `quest_template_addon` SET `NextQuestID`=25838 WHERE `ID`=25792;
-- Strike From Above (Exclusive Group contains Eliminate the Resistance)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-25840 WHERE `ID`=25841;
UPDATE `quest_template_addon` SET `NextQuestID`=25882 WHERE `ID`=25841;
-- A Hand at the Ranch
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=25882;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=25932 WHERE `ID`=25882;
-- The Public Servant and Priceless Treasures Exclusive Group (Also includes Those Blasted Troggs)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-432 WHERE `ID` IN (432,433,25937);
UPDATE `quest_template_addon` SET `NextQuestID`=25986 WHERE `ID` IN (432,433,25937);
-- Seize the Ambassador
UPDATE `quest_template_addon` SET `PrevQuestID`=26112 WHERE `ID`=26118;
