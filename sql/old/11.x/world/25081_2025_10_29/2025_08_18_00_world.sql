SET @CGUID := 10006788;
SET @OGUID := 10001681;

SET @NPCTEXTID := 600116;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 235348, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1398.40625, -1134.265625, -3.10432958602905273, 6.232280731201171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Spell Target Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+1, 235348, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1212.74658203125, -1059.65283203125, -35.1666679382324218, 5.506845474243164062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Spell Target Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+2, 235348, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1596.8663330078125, -1097.329833984375, -37.508331298828125, 3.536682605743408203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Spell Target Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+3, 235348, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1626.265625, -716.84722900390625, -22.1847000122070312, 2.226778268814086914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Spell Target Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+4, 235348, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1701.390625, -913.97918701171875, -75.6153335571289062, 0.731668353080749511, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Spell Target Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+5, 23837, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1310.90625, -1106.076416015625, -103.963172912597656, 1.595203638076782226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- ELM General Purpose Bunny (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+6, 230736, 2738, 15336, 15792, '0', 25369, 0, 0, 0, 1328.7691650390625, -1034.5399169921875, -97.0651092529296875, 4.694455146789550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Om'talad (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+7, 231820, 2738, 15336, 15792, '0', 25631, 0, 0, 0, 1329.8680419921875, -1041.6041259765625, -97.0377960205078125, 2.250078201293945312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493); -- Ve'nari (Area: The Oasis - Difficulty: 0) CreateObject2 (Auras: 467288 - Create Area Trigger [DNT])

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 516700, 2738, 15336, 15792, '0', 0, 0, 1281.8992919921875, -900.0555419921875, -119.790077209472656, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+1, 516700, 2738, 15336, 15792, '0', 0, 0, 1385.109375, -881.046875, -134.505523681640625, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+2, 516700, 2738, 15336, 15792, '0', 0, 0, 1336.2535400390625, -909.34552001953125, -119.464439392089843, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+3, 516700, 2738, 15336, 15792, '0', 0, 0, 1315.0538330078125, -895.3819580078125, -123.878517150878906, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+4, 516700, 2738, 15336, 15792, '0', 0, 0, 1294.41845703125, -854.38714599609375, -125.943008422851562, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+5, 516700, 2738, 15336, 15792, '0', 0, 0, 1382.439208984375, -859.00347900390625, -136.134963989257812, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+6, 516700, 2738, 15336, 15792, '0', 0, 0, 1255.28125, -892.125, -118.884857177734375, 0, 0, 0, 0, 1, 120, 255, 1, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+7, 516700, 2738, 15336, 15792, '0', 0, 0, 1253.8958740234375, -806.623291015625, -130.790115356445312, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+8, 516700, 2738, 15336, 15792, '0', 0, 0, 1359.7135009765625, -826.58160400390625, -138.333450317382812, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+9, 516700, 2738, 15336, 15792, '0', 0, 0, 1360.1041259765625, -804.28472900390625, -140.951812744140625, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+10, 516700, 2738, 15336, 15792, '0', 0, 0, 1414.7117919921875, -823.920166015625, -139.044769287109375, 0, 0, 0, 0, 1, 120, 255, 0, 62493), -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+11, 516700, 2738, 15336, 15792, '0', 0, 0, 1440.1319580078125, -832.04168701171875, -139.218246459960937, 0, 0, 0, 0, 1, 120, 255, 0, 62493); -- Oasis Animal Leavings (Area: The Oasis - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000 WHERE `entry`=238239; -- Cartel Om Custodian
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry`=235348; -- [DNT] Spell Target Bunny
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=231820; -- Ve'nari
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=230736; -- Om'talad

DELETE FROM `gameobject_template` WHERE `entry`=516700;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(516700, 3, 9572, 'Oasis Animal Leavings', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130838, 0, 0, 0, 0, 3007, 62493); -- Oasis Animal Leavings

UPDATE `gameobject_template` SET `VerifiedBuild`=62493 WHERE `entry` IN (523491, 494777, 503267, 523512, 548694, 548689, 504210, 548690, 506585);

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=516700 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(516700, 0, 236416, 62493); -- Oasis Animal Leavings

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=235348;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(235348, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 235348 ([DNT] Spell Target Bunny)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (516700 /*Oasis Animal Leavings*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(516700, 0, 0x204004, 0, 0); -- Oasis Animal Leavings

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (238239,235348,231820,230736));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(238239, 0, 10, 1, 1, 317213, 0x0, 0, 0), -- Cartel Om Custodian
(235348, 0, 10, 1, 1, 314079, 0x400, 0, 0), -- [DNT] Spell Target Bunny
(231820, 0, 10, 50, 1, 283161, 0x0, 32768, 0), -- Ve'nari
(230736, 0, 10, 1, 1, 282040, 0x0, 32768, 0); -- Om'talad

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=238239 AND `DifficultyID`=0); -- 238239 (Cartel Om Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3010, `StaticFlags1`=0x20000000, `VerifiedBuild`=62493 WHERE (`Entry`=235348 AND `DifficultyID`=0); -- 235348 ([DNT] Spell Target Bunny) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=227709 AND `DifficultyID`=0); -- 227709 (Kaheti Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3007, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=231820 AND `DifficultyID`=0); -- 231820 (Ve'nari) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=230736 AND `DifficultyID`=0); -- 230736 (Om'talad) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=28310;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28310, 77831, 0, 62493);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28310 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28310, 104996, 10006787, 0, 0, 0, 0, 0, 62493); -- Full: 0x203AE55640E8A0400057E6000021B129 Creature/0 R3769/S22502 Map: 2738 (K'aresh) Entry: 238209 (Cartel Om Custodian) Low: 2208041

DELETE FROM `conversation_line_template` WHERE `Id`=77831;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(77831, 0, 0, 0, 0, 62493);

-- Phase
UPDATE `creature` SET `phaseId` = 25633 WHERE `guid` = 10006787;

DELETE FROM `phase_name` WHERE `ID` IN (25633,25369,25631);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25633, 'Cosmetic - See Cartel Om Custodian in The Oasis'),
(25369, 'Cosmetic - See Om''talad in The Oasis'),
(25631, 'Cosmetic - See Ve''nari in The Oasis');

DELETE FROM `phase_area` WHERE `PhaseId` IN (25633,25369,25631);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15336, 25633, 'See Cartel Om Custodian in The Oasis'),
(15336, 25369, 'See Om''talad in The Oasis'),
(15336, 25631, 'See Ve''nari in The Oasis');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (25633,25369,25631) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25633, 0, 0, 0, 47, 0, 87337, 2|64, 0, 1, 'Apply Phase 25628 if Quest 87337 is not complete | rewarded'),
(26, 25369, 0, 0, 0, 47, 0, 87337, 2|64, 0, 0, 'Apply Phase 25628 if Quest 87337 is complete | rewarded'),
(26, 25631, 0, 0, 0, 47, 0, 87337, 2|64, 0, 0, 'Apply Phase 25628 if Quest 87337 is complete | rewarded');

-- Gamobject loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 130838;
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(130838, 0, 236416, 100, 1, 1, 0, 1, 1, 'Oasis Animal Leavings');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 238239;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(238239, 0, 0, 'Please stop! I didn\'t realize who you were! Ve\'nari has arrived. She\'s waiting for you.', 12, 0, 100, 1, 0, 0, 0, 5, 'Cartel Om Custodian to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=238239 AND `MenuID`=38089) OR (`CreatureID`=231820 AND `MenuID`=37437) OR (`CreatureID`=230736 AND `MenuID`=37186);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(238239, 38089, 62493), -- Cartel Om Custodian
(231820, 37437, 62493), -- Ve'nari
(230736, 37186, 62493); -- Om'talad

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 281555, 0, 0, 0, 0, 0, 0, 0, 62493), -- 238239 (Cartel Om Custodian)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 277014, 0, 0, 0, 0, 0, 0, 0, 62493), -- 230736 (Om'talad)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 278432, 0, 0, 0, 0, 0, 0, 0, 62493); -- 231820 (Ve'nari)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38089 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37186 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=37437 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38089, @NPCTEXTID+0, 62493), -- 238239 (Cartel Om Custodian)
(37186, @NPCTEXTID+1, 62493), -- 230736 (Om'talad)
(37437, @NPCTEXTID+2, 62493); -- 231820 (Ve'nari)

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=231820 AND `quest`=87337);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87337, 62493); -- Custodian Duties ended by Ve'nari

DELETE FROM `quest_offer_reward` WHERE `ID`=87337;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(87337, 1, 0, 0, 0, 0, 0, 0, 0, 'I apologize for the task my custodian gave you. Good help is difficult to find.', 62493); -- Custodian Duties

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (457891,457878);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(457891, NULL, 1219736, NULL, 0, 0),
(457878, NULL, 1219735, NULL, 1, 0);

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2722672 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722673 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722675 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722674 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722670 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722671 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722676 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722677 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722680 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722679 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722678 /*Map: 2738 (K'aresh) - Phase: 0*/, 2834475 /*Map: 2738 (K'aresh) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2722672, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722673, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722675, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722674, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722670, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722671, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722676, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722677, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722680, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722679, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2722678, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2834475, 2738, 0, 0, 0, 62493); -- Map: 2738 (K'aresh) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId` IN (2722672,2722673,2722675,2722674,2722670,2722671,2722676,2722677,2722680,2722679,2722678,2834475) AND `QuestObjectiveId`=457891);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2722672, 457891, 62493),
(2722673, 457891, 62493),
(2722675, 457891, 62493),
(2722674, 457891, 62493),
(2722670, 457891, 62493),
(2722671, 457891, 62493),
(2722676, 457891, 62493),
(2722677, 457891, 62493),
(2722680, 457891, 62493),
(2722679, 457891, 62493),
(2722678, 457891, 62493),
(2834475, 457891, 62493);

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(2722672, 1, @OGUID+0, 457891), -- Oasis Animal Leavings
(2722673, 1, @OGUID+1, 457891), -- Oasis Animal Leavings
(2722675, 1, @OGUID+2, 457891), -- Oasis Animal Leavings
(2722674, 1, @OGUID+3, 457891), -- Oasis Animal Leavings
(2722670, 1, @OGUID+4, 457891), -- Oasis Animal Leavings
(2722671, 1, @OGUID+5, 457891), -- Oasis Animal Leavings
(2722676, 1, @OGUID+6, 457891), -- Oasis Animal Leavings
(2722677, 1, @OGUID+7, 457891), -- Oasis Animal Leavings
(2722680, 1, @OGUID+8, 457891), -- Oasis Animal Leavings
(2722679, 1, @OGUID+9, 457891), -- Oasis Animal Leavings
(2722678, 1, @OGUID+10, 457891), -- Oasis Animal Leavings
(2834475, 1, @OGUID+11, 457891); -- Oasis Animal Leavings

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+0, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+2, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+2, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+2, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+3, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+3, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+3, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+4, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+4, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+4, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+5, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+5, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+5, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+6, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+6, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+6, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+7, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+7, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+7, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+8, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+8, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+8, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+9, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+9, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+9, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+10, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+10, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+10, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+11, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+11, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+11, 2, 0, NULL, NULL, NULL, NULL);

-- Cartel Om Custodian smart ai
SET @ENTRY := 238209;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 87337, 0, 0, 0, 0, 143, 28310, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Custodian Duties (87337) - Player who accepted quest: Start conversation 28310', '');

-- Cartel Om Custodian smart ai
SET @ENTRY := 238239;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Despawn in 120 s', '');
