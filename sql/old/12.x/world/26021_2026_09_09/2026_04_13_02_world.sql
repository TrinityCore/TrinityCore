SET @CGUID := 11000751;
SET @NPCTEXTID := 610015;

SET @ATID := 186;
SET @ATIDSPAWN := 287;
SET @ATCP := 177;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245102, 2694, 15355, 15928, '0', 26891, 0, 0, 1, 1348.517333984375, 909.0867919921875, 1345.374267578125, 3.514191150665283203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Dalnir (Area: Har'mara - Difficulty: 0) CreateObject1

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2694, '0', 1348.517333984375, 909.0867919921875, 1345.374267578125, 3.514191150665283203, 0, 26891, 0, 'SmartAreaTriggerAI', 'Harmara - Trigger Conversation 30105 for Dalnir', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, '', 0); 

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245102 AND `DifficultyID`=0); -- 245102 (Dalnir) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=30105;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(30105, 83187, 0, 66838);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=30105 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(30105, 108648, (@CGUID+0), 0, 0, 0, 0, 0, 66838); -- Full: 0x203AF950C0EF5B8000762100005C1623 Creature/0 R3774/S30241 Map: 2694 (Harandar) Entry: 245102 (Dalnir) Low: 6034979

DELETE FROM `conversation_line_template` WHERE `Id`=83187;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(83187, 0, 0, 0, 0, 66838);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 26891;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26891, 'Cosmetic - See Root Temder Dalnir');

DELETE FROM `phase_area` WHERE `PhaseId` = 26891;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15928, 26891, 'See Root Temder Dalnir');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 26891 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26891, 0, 0, 0, 47, 0, 90957, 2|8|64, 0, 0, 'Apply Phase 26891 if Quest 90957 is complete|in progress|rewarded');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=245102 AND `quest`=90958);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(245102, 90958, 66838); -- Roots Above All offered by Dalnir

DELETE FROM `creature_questender` WHERE (`id`=245102 AND `quest`=90957);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(245102, 90957, 66838); -- Initiation Day ended by Dalnir

DELETE FROM `quest_offer_reward` WHERE `ID`=90957;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90957, 1, 0, 0, 0, 0, 0, 0, 0, 'The time has come to take your place among our people, and give up childish adventures. Follow my guidance and Aln\'hara bless this day.\n\nRemember, our traditions show us the way.', 66838); -- Initiation Day

UPDATE `quest_poi` SET `VerifiedBuild`=66838 WHERE (`QuestID`=90957 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90957 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90957 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=93057 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=93057 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90719 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=90719 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=90719 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=90719 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=90719 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90719 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=66838 WHERE (`QuestID`=90957 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=90957 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90957 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=90958;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90958, 1, 0, 0, 0, 0, 0, 0, 0, 66838); -- Roots Above All

DELETE FROM `quest_request_items` WHERE `ID`=90957;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(90957, 0, 1, 0, 0, 'Are the pests cleared? We should not have the day spoiled by them.', 66838); -- Initiation Day

DELETE FROM `quest_template_addon` WHERE `ID` = 90958;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(90958, 0, 0, 0, 90957, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=245102 AND `MenuID`=39722);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(245102, 39722, 66838); -- Dalnir

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 292642, 0, 0, 0, 0, 0, 0, 0, 66838), -- 245102 (Dalnir)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 294381, 0, 0, 0, 0, 0, 0, 0, 66838); -- 245102 (Dalnir)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39722 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=40031 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39722, @NPCTEXTID+0, 66838), -- 245102 (Dalnir)
(40031, @NPCTEXTID+1, 66838); -- 245102 (Dalnir)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39722 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39722, 134934, 0, 0, 'Why do we value tradition first?', 0, 0, 0, 40031, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=245102 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(245102, 1, 232649, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- Dalnir

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=139977;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(139977, 0.580512702465057373, 1.5, 0, 66838);

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 30105, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 90957, 8, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 90957 is in progress');
