-- Tirisfal Glade Quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (24982,24983,24988,24989,24990,24991,24993,24999,25003,25004,25029,25031,25038);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`BreadcrumbForQuestId`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(24982,0,0,0,0,0,0,24983,0,0,0,0,0,0,0,0,0,0,''), -- The New Forsaken
(24988,0,0,0,24983,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- The Chill of Death
(24989,0,0,0,24988,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Return to the Magistrate
(24990,0,0,0,24976,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Darkhound Pounding
(24991,0,0,0,24996,0,0,0,0,0,0,0,0,0,0,0,0,0,''), -- Garren's Haunt
(24999,0,0,0,24994,25031,-24995,0,0,0,0,0,0,0,0,0,0,0,''), -- Planting the Seed of Fear
(25004,0,0,0,25003,25005,-25004,0,0,0,0,0,0,0,0,0,0,0,''), -- The Mills Overrun
(25029,0,0,0,25003,25005,-25004,0,0,0,0,0,0,0,0,0,0,0,''), -- Deaths in the Family
(25031,0,0,0,0,0,0,25003,0,0,0,0,0,0,0,0,0,0,''), -- Head for the Mills
(25038,0,0,0,24976,0,0,0,0,0,0,0,0,0,0,0,0,0,''); -- Gordo's Task
-- Have You Seen Anything Weird Out There?
UPDATE `quest_template_addon` SET `PrevQuestID`=25040 WHERE `ID`=25039;
-- Off the Scales ExclusiveGroup (Includes Planting the Seed of Fear)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-24995 WHERE `ID`=24995;
UPDATE `quest_template_addon` SET `NextQuestID`=25031 WHERE `ID`=24995;
