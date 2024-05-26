-- Teldrassil Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (487, 932, 937, 938, 2438, 2499, 13945);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(487,0,0,0,483,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- The Road to Darnassus
(932,0,0,0,489,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Twisted Hatred
(2499,0,0,0,923,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Oakenscowl
(13945,0,0,0,476,0,0,0,0,0,0,0,0,0,0,0,0,0,''); -- Resident Danger 
-- Ursal the Mauler
UPDATE `quest_template_addon` SET `PrevQuestID`=483 WHERE `ID`=486;
-- Timberling Seeds
UPDATE `quest_template_addon` SET `PrevQuestID`=997 WHERE `ID`=918;
-- Teldrassil: The Refusal of the Aspects
UPDATE `quest_template_addon` SET `PrevQuestID`=28731 WHERE `ID`=929;
-- Denalan's Earth
UPDATE `quest_template_addon` SET `PrevQuestID`=486 WHERE `ID`=997;
-- Dolanaar Delivery
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID`=2159;
-- Teldrassil: The Burden of the Kaldorei
UPDATE `quest_template_addon` SET `PrevQuestID`=918 WHERE `ID`=7383;
-- Nature's Reprisal
UPDATE `quest_template_addon` SET `PrevQuestID`=489 WHERE `ID`=13946;
