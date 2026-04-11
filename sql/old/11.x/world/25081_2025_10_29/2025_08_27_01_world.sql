SET @CGUID := 10006800;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -985.72393798828125, -300.829864501953125, 587.9571533203125, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+1, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1021.5, -26.390625, 604.66278076171875, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+2, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1090.54345703125, -314.33160400390625, 545.29779052734375, 3.321784257888793945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+3, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -922.59552001953125, -152.708328247070312, 578.98486328125, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+4, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1084.7535400390625, -89.8645858764648437, 572.44976806640625, 5.273345947265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+5, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1132.5242919921875, -208.288192749023437, 541.6324462890625, 0.032789904624223709, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+6, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -961.57464599609375, -195.61285400390625, 579.1346435546875, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+7, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1012.90631103515625, -280.020843505859375, 571.17218017578125, 4.153622150421142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+8, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -947.0242919921875, -114.348960876464843, 579.48211669921875, 4.318619728088378906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+9, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1001.02777099609375, -114.355903625488281, 578.96759033203125, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+10, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -938.0694580078125, -387.961822509765625, 584.05157470703125, 5.246965408325195312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+11, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1025.829833984375, -27.5069446563720703, 605.0408935546875, 0.366814762353897094, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+12, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -671.55206298828125, -24.729166030883789, 573.5850830078125, 4.917977333068847656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+13, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -836.703125, -520.4375, 559.8048095703125, 2.331850051879882812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+14, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -986.75347900390625, -302.583343505859375, 583.3087158203125, 5.312401294708251953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+15, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1102.673583984375, -128.572921752929687, 551.49664306640625, 1.591742634773254394, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+16, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -604.27081298828125, -153.213546752929687, 569.2000732421875, 4.646534442901611328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+17, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -856.58856201171875, -8.11458301544189453, 606.260986328125, 2.773082494735717773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+18, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -746.63543701171875, -293.595489501953125, 605.6898193359375, 5.424788475036621093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+19, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -863.26739501953125, -494.611114501953125, 544.398193359375, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+20, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -960.98614501953125, -178.760421752929687, 556.8223876953125, 4.649509429931640625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+21, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1154.2117919921875, -293.8819580078125, 563.06463623046875, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+22, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1212.0416259765625, -221.279510498046875, 561.572998046875, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+23, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1189.657958984375, -325.197906494140625, 555.11859130859375, 0.815861523151397705, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+24, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1240.045166015625, -258.22222900390625, 558.78314208984375, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+25, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1253.501708984375, -235.829864501953125, 548.94256591796875, 1.442155003547668457, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+26, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1262.689208984375, -338.185760498046875, 570.073486328125, 3.609539747238159179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+27, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1212.7535400390625, -400.145843505859375, 546.506591796875, 4.727573394775390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+28, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1325.7603759765625, -279.251739501953125, 627.464599609375, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+29, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1292.9444580078125, -349.4132080078125, 576.95648193359375, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+30, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1340.826416015625, -271.661468505859375, 667.1143798828125, 4.341050148010253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+31, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1305.642333984375, -355.5069580078125, 574.152099609375, 3.572952747344970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+32, 187789, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1267.88720703125, -424.60589599609375, 629.0003662109375, 0.250967770814895629, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Energy (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 370569 - Visual)
(@CGUID+33, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1263.5416259765625, -475.677093505859375, 669.15679931640625, 0.186678007245063781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+34, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1469.548583984375, -243.986114501953125, 662.19708251953125, 0.153756007552146911, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+35, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1519.3385009765625, -488.291656494140625, 597.048828125, 2.205742835998535156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748), -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)
(@CGUID+36, 238316, 2738, 15781, 15781, '0', 25751, 0, 0, 0, -1635.3177490234375, -469.295135498046875, 588.330078125, 4.813906192779541015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748); -- Pamphlet Dump Bunny (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1 (Auras: 1220532 - Dump Area Trigger)

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (38366,39682,39686));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(38366, 0, 62748),
(39682, 0, 62748),
(39686, 0, 62748);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (37944,37948,36385));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(37944, 0, 39682, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 10500, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- Spell: 1237088 (Nullgaze Surge)
(37948, 0, 39686, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 70000, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 62748), -- Spell: 1237123 (Resonant Focus)
(36385, 0, 38366, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 62748); -- Spell: 1220532 (Dump Area Trigger)

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'SmartAreaTriggerAI' WHERE `Id` = 36385;

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE (`AreaTriggerCreatePropertiesId`=37944 AND `IsCustom`=0 AND `Idx`=0) OR (`AreaTriggerCreatePropertiesId`=37944 AND `IsCustom`=0 AND `Idx`=1) OR (`AreaTriggerCreatePropertiesId`=37944 AND `IsCustom`=0 AND `Idx`=2) OR (`AreaTriggerCreatePropertiesId`=37944 AND `IsCustom`=0 AND `Idx`=3);
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(37944, 0, 0, 0, 1.5, NULL, NULL, 62748), -- Spell: 1237088 (Nullgaze Surge)
(37944, 0, 1, 0, -1.5, NULL, NULL, 62748), -- Spell: 1237088 (Nullgaze Surge)
(37944, 0, 2, 50, -1.5, NULL, NULL, 62748), -- Spell: 1237088 (Nullgaze Surge)
(37944, 0, 3, 50, 1.5, NULL, NULL, 62748); -- Spell: 1237088 (Nullgaze Surge)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (238316 /*238316 (Pamphlet Dump Bunny) - Dump Area Trigger*/, 187789 /*187789 (Energy) - Visual*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(238316, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1220532'), -- 238316 (Pamphlet Dump Bunny) - Dump Area Trigger
(187789, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '370569'); -- 187789 (Energy) - Visual

-- Template
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=238316; -- Pamphlet Dump Bunny
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000, `flags_extra` = 128 WHERE `entry`=187789; -- Energy

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` = 238316);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(238316, 0, 10, 0.5, 1, 317291, 0x60000010, 117440518, 0); -- Pamphlet Dump Bunny

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2798, `StaticFlags1`=0x30000100, `VerifiedBuild`=62748 WHERE (`Entry`=238316 AND `DifficultyID`=0); -- 238316 (Pamphlet Dump Bunny) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=62748 WHERE (`Entry`=187789 AND `DifficultyID`=0); -- 187789 (Energy) - Sessile, Floating

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=28316;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28316, 77849, 0, 62748);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28316 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28316, 102228, 10006795, 0, 0, 0, 0, 0, 62748); -- Full: 0x2042595640E26300004D9A00002BFCA0 Creature/0 R4246/S19866 Map: 2738 (K'aresh) Entry: 231820 (Ve'nari) Low: 2882720

DELETE FROM `conversation_line_template` WHERE `Id`=77849;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(77849, 0, 0, 0, 0, 62748);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 25751;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25751, 'Cosmetic - See Rings in Tazavesh');

DELETE FROM `phase_area` WHERE `PhaseId` = 25751;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15781, 25751, 'Cosmetic - See Rings in Tazavesh');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25751 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25751, 0, 0, 0, 47, 0, 87340, 2, 0, 1, 'Apply Phase 25751 if Quest 87340 is not complete');

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID` IN (87339 /*Ongoing Activities*/, 87338 /*Day One Orientation*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(87339, 1, 0, 0, 0, 0, 0, 0, 0, 'Should you wish to help out the custodians, there is always data to be collected, plants to be watered, and soil to flatten.', 62748), -- Ongoing Activities
(87338, 1, 0, 0, 0, 0, 0, 0, 0, 'You are unharmed. Excellent. This means we may proceed faster.', 62748); -- Day One Orientation

DELETE FROM `quest_details` WHERE `ID`=87340;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(87340, 1, 0, 0, 0, 0, 0, 0, 0, 62748); -- Junk Mail

DELETE FROM `quest_request_items` WHERE `ID`=87340;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(87340, 0, 1, 0, 0, 'Have you distributed the fliers?', 62748); -- Junk Mail

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=87339; -- Ongoing Activities

UPDATE `quest_description_conditional` SET `VerifiedBuild`=62748 WHERE (`QuestId`=32470 AND `PlayerConditionId`=924 AND `QuestgiverCreatureId`=16908 AND `locale`='enUS') OR (`QuestId`=32470 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=16926 AND `locale`='enUS');

DELETE FROM `creature_queststarter` WHERE (`id`=231820 AND `quest`=87340);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87340, 62748); -- Junk Mail offered by Ve'nari

DELETE FROM `creature_questender` WHERE (`id`=231820 AND `quest`=87340);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87340, 62748); -- Junk Mail ended by Ve'nari

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 457932;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(457932, NULL, NULL, NULL, 1, 1);

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2723333 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734997 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723275 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734993 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723315 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734996 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723316 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723317 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734994 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723318 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723319 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723320 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734995 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2734992 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723326 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723329 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723330 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723331 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723327 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723328 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723324 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723332 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723325 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723323 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/, 2723322 /*Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2723333, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734997, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723275, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734993, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723315, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734996, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723316, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723317, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734994, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723318, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723319, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723320, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734995, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2734992, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723326, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723329, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723330, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723331, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723327, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723328, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723324, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723332, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723325, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723323, 2738, 25751, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)
(2723322, 2738, 25751, 0, 0, 62748); -- Map: 2738 (K'aresh) - Phase: 25751 (Cosmetic - See Rings in Tazavesh)

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+2,@CGUID+4,@CGUID+5,@CGUID+7,@CGUID+8,@CGUID+10,@CGUID+11,@CGUID+12,@CGUID+13,@CGUID+14,@CGUID+15,@CGUID+16,@CGUID+17,@CGUID+18,@CGUID+20,@CGUID+23,@CGUID+25,@CGUID+26,@CGUID+27,@CGUID+30,@CGUID+31,@CGUID+33,@CGUID+34,@CGUID+35,@CGUID+36));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(2723333, 0, @CGUID+2, 457932), -- Pamphlet Dump Bunny
(2734997, 0, @CGUID+4, 457932), -- Pamphlet Dump Bunny
(2723275, 0, @CGUID+5, 457932), -- Pamphlet Dump Bunny
(2734993, 0, @CGUID+7, 457932), -- Pamphlet Dump Bunny
(2723315, 0, @CGUID+8, 457932), -- Pamphlet Dump Bunny
(2734996, 0, @CGUID+10, 457932), -- Pamphlet Dump Bunny
(2723316, 0, @CGUID+11, 457932), -- Pamphlet Dump Bunny
(2723317, 0, @CGUID+12, 457932), -- Pamphlet Dump Bunny
(2734994, 0, @CGUID+13, 457932), -- Pamphlet Dump Bunny
(2723318, 0, @CGUID+14, 457932), -- Pamphlet Dump Bunny
(2723319, 0, @CGUID+15, 457932), -- Pamphlet Dump Bunny
(2723320, 0, @CGUID+16, 457932), -- Pamphlet Dump Bunny
(2734995, 0, @CGUID+17, 457932), -- Pamphlet Dump Bunny
(2734992, 0, @CGUID+18, 457932), -- Pamphlet Dump Bunny
(2723326, 0, @CGUID+20, 457932), -- Pamphlet Dump Bunny
(2723329, 0, @CGUID+23, 457932), -- Pamphlet Dump Bunny
(2723330, 0, @CGUID+25, 457932), -- Pamphlet Dump Bunny
(2723331, 0, @CGUID+26, 457932), -- Pamphlet Dump Bunny
(2723327, 0, @CGUID+27, 457932), -- Pamphlet Dump Bunny
(2723328, 0, @CGUID+30, 457932), -- Pamphlet Dump Bunny
(2723324, 0, @CGUID+31, 457932), -- Pamphlet Dump Bunny
(2723332, 0, @CGUID+33, 457932), -- Pamphlet Dump Bunny
(2723325, 0, @CGUID+34, 457932), -- Pamphlet Dump Bunny
(2723323, 0, @CGUID+35, 457932), -- Pamphlet Dump Bunny
(2723322, 0, @CGUID+36, 457932); -- Pamphlet Dump Bunny

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId` IN (2723333,2734997,2723275,2734993,2723315,2734996,2723316,2723317,2734994,2723318,2723319,2723320,2734995,2734992,2723326,2723329,2723330,2723331,2723327,2723328,2723324,2723332,2723325,2723323,2723322) AND `QuestObjectiveId`=457932);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2723333, 457932, 62748),
(2734997, 457932, 62748),
(2723275, 457932, 62748),
(2734993, 457932, 62748),
(2723315, 457932, 62748),
(2734996, 457932, 62748),
(2723316, 457932, 62748),
(2723317, 457932, 62748),
(2734994, 457932, 62748),
(2723318, 457932, 62748),
(2723319, 457932, 62748),
(2723320, 457932, 62748),
(2734995, 457932, 62748),
(2734992, 457932, 62748),
(2723326, 457932, 62748),
(2723329, 457932, 62748),
(2723330, 457932, 62748),
(2723331, 457932, 62748),
(2723327, 457932, 62748),
(2723328, 457932, 62748),
(2723324, 457932, 62748),
(2723332, 457932, 62748),
(2723325, 457932, 62748),
(2723323, 457932, 62748),
(2723322, 457932, 62748);

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+2,@CGUID+4,@CGUID+5,@CGUID+7,@CGUID+8,@CGUID+10,@CGUID+11,@CGUID+12,@CGUID+13,@CGUID+14,@CGUID+15,@CGUID+16,@CGUID+17,@CGUID+18,@CGUID+20,@CGUID+23,@CGUID+25,@CGUID+26,@CGUID+27,@CGUID+30,@CGUID+31,@CGUID+33,@CGUID+34,@CGUID+35,@CGUID+36));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, @CGUID+2, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+18, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+18, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+18, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+20, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+20, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+20, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+23, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+23, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+23, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+25, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+25, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+25, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+26, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+26, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+26, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+27, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+27, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+27, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+30, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+30, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+30, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+31, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+31, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+31, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+33, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+33, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+33, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+34, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+34, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+34, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+35, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+35, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+35, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+36, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+36, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+36, 2, 0, NULL, NULL, NULL, NULL);

-- Ve'nari smart ai
SET @ENTRY := 231820;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 87339, 0, 0, 0, 0, 143, 28311, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Ongoing Activities (87339) - Player who accepted quest: Start conversation (28311) Actors<> (first line 77832)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 87340, 0, 0, 0, 0, 143, 28316, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Junk Mail (87340) - Player who accepted quest: Start conversation (28316) Actors<> (first line 77849)', '');

-- Areatrigger ai
SET @ENTRY := 38366;
DELETE FROM `smart_scripts` WHERE `source_type` = 11 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 11, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 238317, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On trigger - reward Credit 238317 to Invoker'),
(@ENTRY, 11, 1, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 1230718, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On trigger - invoker: cast Spell 1230718');
