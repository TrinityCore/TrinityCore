SET @NPCTEXTID := 560019;

-- Playerchoice
DELETE FROM `playerchoice` WHERE `ChoiceId`=248;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `CloseSoundKitId`, `Duration`, `Question`, `PendingChoiceText`, `InfiniteRange`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `ShowChoicesAsList`, `ForceDontShowChoicesAsList`, `VerifiedBuild`) VALUES
(248, 0, 0, 0, NULL, 'Which weapon should we pursue first?', '', 0, 0, 0, 0, 0, 61609);

UPDATE `playerchoice` SET `ScriptName` = 'playerchoice_a_weapon_you_can_hold_priest' WHERE `ChoiceId` = 248;

DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=248 AND `ResponseId` IN (534,533,532));
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(248, 534, 2, 1389392, 0, 0, 0, 0, 0, 'Discipline', '', '', 'Select', 'Obsessed with cleansing undead from Azeroth, the fanatical Scarlet Crusade tried to create a second Ashbringer in the form of a staff. However, due to treachery from within, the ritual failed in a great fiery explosion. The damaged staff\'s power proved nearly uncontrollable.\n\nFearing its destructive power, the elite magi of the Kirin Tor hid it away from the hands of men.', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61609),
(248, 533, 1, 1389394, 0, 0, 0, 0, 0, 'Shadow', '', '', 'Select', 'An ancient dagger of the Old Gods has resurfaced in a bid to restore the Twilight\'s Hammer to power. They are performing an unholy ritual nearby that must be stopped.\n\nThe Blade of the Black Empire is a powerful void-attuned sacrificial dagger that has been used in horrific rites to the Old Gods since time immemorial. It enhances its owners with powerful shadow energy.', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61609),
(248, 532, 0, 1389393, 0, 0, 0, 0, 0, 'Holy', '', '', 'Select', 'The Draenei had to flee from many worlds as the Legion chased after them across the heavens. It is upon one of these worlds where a valiant few remained with the radiant jewel of healing, T\'uure, to face the Legion and allow their friends to escape.\n\nA rumor is spreading that a soldier in Dalaran has seen the lost crystal in possession of the Legion. If this is true it must be retrieved!', 'CONFIRM_ARTIFACT_CHOICE', 0, 0, 61609);

DELETE FROM `playerchoice_response_reward` WHERE (`ChoiceId`=248 AND `ResponseId` IN (534,533,532));
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `VerifiedBuild`) VALUES
(248, 534, 0, 0, 0, 0, 0, 0, 0, 0, 61609),
(248, 533, 0, 0, 0, 0, 0, 0, 0, 0, 61609),
(248, 532, 0, 0, 0, 0, 0, 0, 0, 0, 61609);

DELETE FROM `playerchoice_response_reward_item` WHERE (`ChoiceId`=248 AND `ResponseId`=534 AND `Index`=0) OR (`ChoiceId`=248 AND `ResponseId`=533 AND `Index`=0) OR (`ChoiceId`=248 AND `ResponseId`=532 AND `Index`=0);
INSERT INTO `playerchoice_response_reward_item` (`ChoiceId`, `ResponseId`, `Index`, `ItemId`, `BonusListIDs`, `Quantity`, `VerifiedBuild`) VALUES
(248, 534, 0, 128868, '', 1, 61609),
(248, 533, 0, 128827, '', 1, 61609),
(248, 532, 0, 128825, '', 1, 61609);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 36) AND (`SourceGroup` = 248) AND (`SourceEntry` IN (532,533,534));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(36, 248, 532, 0, 0, 47, 0, 40708, 64, 0, '', 1, 'Show Playerchoice (248), ResponseId (532) if Quest 40708 is not in state rewarded'),
(36, 248, 533, 0, 0, 47, 0, 40707, 64, 0, '', 1, 'Show Playerchoice (248), ResponseId (533) if Quest 40707 is not in state rewarded'),
(36, 248, 534, 0, 0, 47, 0, 40709, 64, 0, '', 1, 'Show Playerchoice (248), ResponseId (534) if Quest 40709 is not in state rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=101314 AND `MenuID`=19157);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(101314, 19157, 61609); -- Alonsus Faol

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 103664, 0, 0, 0, 0, 0, 0, 0, 61609); -- 101314 (Alonsus Faol)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19157 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19157, @NPCTEXTID+0, 61609); -- 101314 (Alonsus Faol)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=19157 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(19157, 45110, 0, 0, 'I would like to review weapons we might pursue.', 101848, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61609); -- OptionBroadcastTextID: 101848 - 102658 - 103166 - 103645

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19157));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19157, 0, 0, 0, 47, 0, 40706, 8, 0, '', 0, 'Player for which gossip text is shown has A Legend You Can Hold (40706) in state incomplete');

-- Quest
DELETE FROM `quest_template` WHERE `ID` IN (40708,40707,40709);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `FlagsEx3`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `ResetByScheduler`, `VerifiedBuild`) VALUES
(40708, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'A Legend You Can Hold: Choose Holy weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0),
(40707, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'A Legend You Can Hold: Choose Shadow weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0),
(40709, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'A Legend You Can Hold: Choose Discipline weapon', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0);

DELETE FROM `creature_queststarter` WHERE (`id`=101314 AND `quest`=40706);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(101314, 40706, 61609); -- A Legend You Can Hold offered by Alonsus Faol

DELETE FROM `quest_template_addon` WHERE `ID` = 40706;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(40706, 0, 0, 0, 40705, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `quest_template_addon` SET `ScriptName` = 'quest_a_legend_you_can_hold' WHERE `ID` = 40706;

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=18 AND `QuestLineId`=218);
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(18, 218, 61609);

-- Alonsus Faol smart ai
SET @ENTRY := 101314;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 40706, 0, 0, 0, 0, 85, 199700, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest A Legend You Can Hold (40706) - Player who accepted quest: Cast spell 199700 on self', ''),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 19157, 0, 0, 0, 0, 85, 199700, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19157 selected - Gossip player: Cast spell 199700 on self', '');
