SET @CGUID := 10006926;
SET @NPCTEXTID := 600166;

SET @ATID := 179;
SET @ATIDSPAWN := 275;
SET @ATCP := 170;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 231042, 2552, 14717, 15943, '0', 25024, 0, 0, 1, 2595.580810546875, -779.9930419921875, 31.42588424682617187, 3.701775312423706054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65299), -- Vereesa Windrunner (Area: Oztan Isle - Difficulty: 0) CreateObject1 (Auras: 470255 - Pained by Vision)
(@CGUID+1, 231039, 2552, 14717, 15943, '0', 25024, 0, 0, 1, 2593.96435546875, -781.06768798828125, 31.55034828186035156, 0.586996912956237792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65299); -- Arator (Area: Oztan Isle - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231039; -- Arator
UPDATE `creature_template` SET `faction`=534, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=231042; -- Vereesa Windrunner

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (231039 /*231039 (Arator)*/, 231042 /*231042 (Vereesa Windrunner) - Pained by Vision*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(231039, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, ''), -- 231039 (Arator)
(231042, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, '470255'); -- 231042 (Vereesa Windrunner) - Pained by Vision

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2552, '0', 2593.595703, -777.102539, 31.316559, 4.957289, 0, 25024, 0, 'SmartAreaTriggerAI', 'Isle of Dorn - trigger conversation for Vereesa Windrunner', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, '', 0); 

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 25024;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25024, 'Cosmetic - See Arator and Vereesa Windrunner at Oztan Isle');

DELETE FROM `phase_area` WHERE `PhaseId` = 25024;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 25024, 'See Arator and Vereesa Windrunner at Oztan Isle');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25024 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25024, 0, 0, 0, 47, 0, 92405, 2|8|64, 0, 0, 'Apply Phase 25024 if Quest 92405 is taken|complete|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27486;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27486, 75362, 0, 65299);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27486 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27486, 102971, (@CGUID+0), 0, 0, 0, 0, 0, 65299); -- Full: 0x2042653F00E1A080000020000066FE86 Creature/0 R4249/S32 Map: 2552 (Khaz Algar (Surface)) Entry: 231042 (Vereesa Windrunner) Low: 6749830

DELETE FROM `conversation_line_template` WHERE `Id`=75362;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(75362, 0, 0, 0, 0, 65299);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=231042 AND `MenuID`=37102) OR (`CreatureID`=231039 AND `MenuID`=37093);;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(231042, 37102, 65299), -- Vereesa Windrunner
(231039, 37093, 65299); -- Arator

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 276438, 0, 0, 0, 0, 0, 0, 0, 65299), -- 231042 (Vereesa Windrunner)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 276403, 0, 0, 0, 0, 0, 0, 0, 65299); -- 231039 (Arator)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37102 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37093 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37102, @NPCTEXTID+0, 65299), -- 231042 (Vereesa Windrunner)
(37093, @NPCTEXTID+1, 65299); -- 231039 (Arator)

-- Quest
UPDATE `quest_offer_reward` SET `RewardText`='My aunt has been having terrible visions and they are getting worse.', `VerifiedBuild`=65299 WHERE `ID`=92405; -- Meet Arator

DELETE FROM `creature_queststarter` WHERE (`id`=231039 AND `quest`=84996);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(231039, 84996, 65299); -- Vereesa's Tale offered by Arator

DELETE FROM `creature_questender` WHERE (`id`=231039 AND `quest`=92405);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231039, 92405, 65299); -- Meet Arator ended by Arator

DELETE FROM `quest_template_addon` WHERE `ID` IN (84996);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(84996, 0, 0, 0, 92405, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Vereesa's Tale

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (231042,233374,231039));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(231042, 0, 10, 15, 1, 282363, 0x0, 16384, 0), -- Vereesa Windrunner
(233374, 0, 10, 0.800000011920928955, 1, 284960, 0x0, 0, 0), -- Dalaran Custodian
(231039, 0, 10, 30, 1, 282360, 0x0, 32768, 0); -- Arator

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=231039 AND `DifficultyID`=0); -- 231039 (Arator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=231042 AND `DifficultyID`=0); -- 231042 (Vereesa Windrunner) - CanSwim

-- Serverside AT smart ai
DELETE FROM `smart_scripts` WHERE (`entryorguid` = @ATID+0 AND `source_type` = 12);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 27486, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - invoker: start conversation 27486');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 28 AND `SourceGroup` = (@ATID+0) AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, (@ATID+0), 1, 0, 0, 47, 0, 92405, 2, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 92405 is complete');
