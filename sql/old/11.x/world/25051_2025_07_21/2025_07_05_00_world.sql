SET @NPCTEXTID := 560019;

-- Playerchoice
DELETE FROM `playerchoice` WHERE `ChoiceId`=240;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `CloseSoundKitId`, `Duration`, `Question`, `PendingChoiceText`, `InfiniteRange`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `ShowChoicesAsList`, `ForceDontShowChoicesAsList`, `VerifiedBuild`) VALUES
(240, 0, 0, 0, NULL, 'Which weapon should we pursue first?', '', 0, 0, 0, 0, 0, 61559);

UPDATE `playerchoice` SET `ScriptName` = 'playerchoice_weapons_of_legend_hunter' WHERE `ChoiceId` = 240;

DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=240 AND `ResponseId` IN (506,505,504));
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(240, 506, 2, 1390107, 0, 0, 0, 0, 0, 'Marksmanship', '', '', 'Select', 'Many years ago, the ranger Alleria Windrunner wielded her family bow, Thas\'dorah, to battle the Legion. Her current whereabouts are unknown.\n\nIf Alleria could be located, her weapon would become a valuable asset in the war against the demons.', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61559),
(240, 505, 1, 1390108, 0, 0, 0, 0, 0, 'Survival', '', '', 'Select', 'The Highmountain tribe lost their greatest weapon, the ancient spear of Huln Highmountain, long ago to a magically corrupted monstrosity.\n\nThey ask you to travel to Stormheim, kill their nemesis, and reclaim the spear for the fight against the Legion.', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61559),
(240, 504, 0, 1390106, 0, 0, 0, 0, 0, 'Beast Mastery', '', '', 'Select', 'In ancient times, a vrykul warlord stole a rifle infused with the power of storms. He used the artifact\'s might to conquer his rivals on the Broken Isles.\n\nDelve into the warlord\'s tomb and recover this mighty weapon!', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61559);

DELETE FROM `playerchoice_response_reward` WHERE (`ChoiceId`=240 AND `ResponseId` IN (506,505,504));
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `VerifiedBuild`) VALUES
(240, 506, 0, 0, 0, 0, 0, 0, 0, 0, 61559),
(240, 505, 0, 0, 0, 0, 0, 0, 0, 0, 61559),
(240, 504, 0, 0, 0, 0, 0, 0, 0, 0, 61559);

DELETE FROM `playerchoice_response_reward_item` WHERE (`ChoiceId`=240 AND `ResponseId`=506 AND `Index`=0) OR (`ChoiceId`=240 AND `ResponseId`=505 AND `Index`=0) OR (`ChoiceId`=240 AND `ResponseId`=504 AND `Index`=0);
INSERT INTO `playerchoice_response_reward_item` (`ChoiceId`, `ResponseId`, `Index`, `ItemId`, `BonusListIDs`, `Quantity`, `VerifiedBuild`) VALUES
(240, 506, 0, 128826, '', 1, 61559),
(240, 505, 0, 128808, '', 1, 61559),
(240, 504, 0, 128861, '', 1, 61559);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 36) AND (`SourceGroup` = 240) AND (`SourceEntry` IN (506,505,504));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(36, 240, 506, 0, 0, 47, 0, 40620, 64, 0, '', 1, 'Show Playerchoice (240), ResponseId (506) if Quest 40621 is not in state rewarded'),
(36, 240, 505, 0, 0, 47, 0, 40619, 64, 0, '', 1, 'Show Playerchoice (240), ResponseId (505) if Quest 40619 is not in state rewarded'),
(36, 240, 504, 0, 0, 47, 0, 40621, 64, 0, '', 1, 'Show Playerchoice (240), ResponseId (504) if Quest 40621 is not in state rewarded');

-- update Phase
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 6084 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 6084, 0, 0, 0, 47, 0, 44184, 2|8|64, 0, 0, 'Apply Phase 6084 if Quest 44184 is rewarded'),
(26, 6084, 0, 0, 0, 15, 0, 4, 0, 0, 0, 'Apply Phase 6084 if player is class Hunter');

-- Gossip
UPDATE `creature_template_gossip` SET `VerifiedBuild`=61491 WHERE (`CreatureID`=102478 AND `MenuID`=19115);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 106084, 0, 0, 0, 0, 0, 0, 0, 61491); -- 102478 (Emmarel Shadewarden)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19115 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19115, @NPCTEXTID+0, 61491); -- 102478 (Emmarel Shadewarden)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=19115 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(19115, 44968, 0, 0, 'I would like to review weapons we might pursue.', 101848, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61491); -- OptionBroadcastTextID: 101848 - 102658 - 103166 - 103645

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19115));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19115, 0, 0, 0, 47, 0, 40618, 8, 0, '', 0, 'Player for which gossip text is shown has Weapons of Legend (40618) in state incomplete');

-- Quest
DELETE FROM `quest_template` WHERE `ID` IN (40621,40619,40620);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `FlagsEx3`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `ResetByScheduler`, `VerifiedBuild`) VALUES
(40621, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Weapons of Legend: Choose Beast Mastery weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0),
(40619, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Weapons of Legend: Choose Survival weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0),
(40620, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Weapons of Legend: Choose Marksmanship weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0);

DELETE FROM `quest_offer_reward` WHERE `ID`=40618;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40618, 1, 1, 0, 0, 0, 0, 0, 0, 'Now you must begin your pursuit of the artifact. It will not be easy to obtain, but a weapon this powerful seldom is.$b$bAfter you succeed, return here to me and we shall speak at greater length. There is much for us to do!', 61491); -- Weapons of Legend

DELETE FROM `quest_template_addon` WHERE `ID` = 41415;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(41415, 0, 0, 0, 40384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=627 AND `QuestLineId` IN (270,269,220,174,173,271));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(627, 270, 61491),
(627, 269, 61491),
(627, 220, 61491),
(627, 174, 61491),
(627, 173, 61491),
(627, 271, 61491);

-- Emmarel Shadewarden smart ai
SET @ENTRY := 102478;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19115, 0, 0, 0, 0, 85, 198430, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19115 selected - Gossip player: Cast spell 198430 on self', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40618, 0, 0, 0, 0, 85, 198430, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Weapons of Legend (40618) - Player who accepted quest: Cast spell 198430 on self', '');
