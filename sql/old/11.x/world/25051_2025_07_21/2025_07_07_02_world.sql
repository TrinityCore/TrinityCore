SET @CGUID := 6005170;

SET @ATID := 159;
SET @ATCP := 154;
SET @ATIDSPAWN := 253;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 104381, 1220, 7502, 7506, '0', 6360, 0, 0, 1, -861.123291015625, 4285.7412109375, 746.36865234375, 2.934702396392822265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Grif Wildheart (Area: Krasus' Landing - Difficulty: 0) CreateObject1
(@CGUID+1, 106235, 1220, 7502, 7506, '0', 6055, 0, 0, 0, -867.9774169921875, 4287.26416015625, 745.5020751953125, 6.050843715667724609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Huey (Area: Krasus' Landing - Difficulty: 0) CreateObject1

-- Serverside ATs
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1220, '0', -861.123, 4285.741, 746.3686, 2.934702, 0, 0, 0, 'SmartAreaTriggerAI', 'Dalaran / Krasus Landing - Trigger conversation for Grif (Quest: "A Beastly Expedition")', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, '', 0);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=106235 AND `DifficultyID`=0); -- 106235 (Huey) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=104381 AND `DifficultyID`=0); -- 104381 (Grif Wildheart) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureId` = 102478;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102478, 0, 0, 'Speak to me again when you return to Dalaran. We have much to discuss.', 12, 0, 100, 1, 0, 64291, 105574, 5, 'Emmarel Shadewarden to Player');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=104381 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(104381, 1, 0, 0, 0, 0, 0, 0, 2552, 0, 0, 61609); -- Grif Wildheart

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=2001;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(2001, 4216, 0, 61609);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=2001 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(2001, 52715, @CGUID+0, 0, 0, 0, 0, 0, 61609); -- Full: 0x203098988065EF40007B0600006B8411 Creature/0 R3110/S31494 Map: 1220 (Broken Isles) Entry: 104381 (Grif Wildheart) Low: 7046161

DELETE FROM `conversation_line_template` WHERE `Id`=4216;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(4216, 0, 0, 0, 0, 61609);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (6360,6055,6363);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6360, 'Cosmetic - See Grif Wildheart at Krasus Landing'),
(6055, 'Cosmetic - See Huey at Krasus Landing'),
(6363, 'Cosmetic - See Grif Wildheart at Shields Rest Island');

DELETE FROM `phase_area` WHERE `PhaseId` IN (6360,6055);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7505, 6360, 'See Grif Wildheart at Krasus Landing'),
(7505, 6055, 'See Huey at Krasus Landing');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (6360,6055) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 6360, 0, 0, 0, 47, 0, 41541, 2|8|64, 0, 0, 'Apply Phase 6360 if Quest 41541 is in progress | complete | rewarded'),
(26, 6055, 0, 0, 0, 47, 0, 41541, 2|8|64, 0, 0, 'Apply Phase 6055 if Quest 41541 is in progress | complete | rewarded');

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (41574 /*Stolen Thunder*/, 41541 /*A Beastly Expedition*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(41574, 1, 1, 0, 0, 0, 0, 0, 0, 61609), -- Stolen Thunder
(41541, 1, 1, 0, 0, 0, 0, 0, 0, 61609); -- A Beastly Expedition

DELETE FROM `quest_offer_reward` WHERE `ID`=41541;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(41541, 1, 1, 0, 0, 0, 0, 0, 0, 'There you are! I knew you\'d be bitin\' to find Titanstrike.$B$BDon\'t mind ol\' Huey here. The city of mages is no place for a gryphon.', 61609); -- A Beastly Expedition

DELETE FROM `creature_queststarter` WHERE (`id`=104381 AND `quest`=41574) OR (`id`=102478 AND `quest`=41541);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(104381, 41574, 61609), -- Stolen Thunder offered by Grif Wildheart
(102478, 41541, 61609); -- A Beastly Expedition offered by Emmarel Shadewarden

DELETE FROM `quest_template_addon` WHERE `ID` IN (41541,41574);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(41541, 0, 0, 0, 40618, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- A Beastly Expedition
(41574, 0, 0, 0, 41541, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Stolen Thunder

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (41541));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 41541, 0, 0, 47, 0, 40621, 64, 0, '', 0, 'Player has Weapons of Legend: Choose Beast Mastery weapon (40621) in state rewarded');

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (249526 /*Hay*/, 259998 /*Battle Map*/, 259999 /*Map of the Eastern Plaguelands*/, 260000 /*Table Small*/, 259997 /*[DND] Large Map*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(249526, 5, 33450, 'Hay', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 61609), -- Hay
(259998, 5, 26338, 'Battle Map', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 61609), -- Battle Map
(259999, 5, 222, 'Map of the Eastern Plaguelands', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 61609), -- Map of the Eastern Plaguelands
(260000, 5, 15420, 'Table Small', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 61609), -- Table Small
(259997, 5, 222, '[DND] Large Map', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 61609); -- [DND] Large Map

-- Emmarel Shadewarden smart ai (followup, updated)
SET @ENTRY := 102478;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19115, 0, 0, 0, 0, 85, 198430, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19115 selected - Gossip player: Cast spell 198430 on self', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40618, 0, 0, 0, 0, 85, 198430, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Weapons of Legend (40618) - Player who accepted quest: Cast spell 198430 on self', ''),
(@ENTRY, 0, 2, 0, 19, 0, 100, 0, 41541, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest A Beastly Expedition (41541) - Player who accepted quest: Talk 0 to invoker', '');

-- Serverside ATs smart ai
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ATID+0 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 2001, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - start conversation 2001 - to Invoker');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 28 AND `SourceGroup` = (@ATID+0) AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 41541, 2, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 41541 is complete');
