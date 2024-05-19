SET @CGUID := 400000000;
SET @OGUID := 400000000;

-- Instance
DELETE FROM `instance_template` WHERE `map`=996;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(996, 870, 'instance_terrace_of_endless_spring');

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0, 36737, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1012.140625, -3137.46875, 27.18474960327148437, 4.667953014373779296, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Invisible Stalker (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+1, 60999, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1017.8853759765625, -2758.34033203125, 38.65444564819335937, 4.713076591491699218, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Sha of Fear (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1 (Auras: 72242 - Zero Energy + Zero Regen)
(@CGUID+2, 63025, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1018.43231201171875, -2784.43408203125, 49.42926788330078125, 1.549839019775390625, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Tsulong (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1 (Auras: 122452 - Energy Drain & 50% HP)
(@CGUID+3, 60957, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1017.97222900390625, -2938.677001953125, 19.43973541259765625, 4.690663814544677734, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Minion of Fear Controller (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@CGUID+4, 63420, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1017.798583984375, -3049.114501953125, 12.90686225891113281, 4.695063591003417968, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- SLG Generic MoP (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1 (Auras: 125630 - Sha Corruption Fountain, 125666 - Sha Corruption Fountain)
(@CGUID+5, 65736, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1214.8004150390625, -2824.819580078125, 41.24303054809570312, 3.507344245910644531, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Return to the Terrace (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1 (Auras: 120216 - Pure Light Visual)
(@CGUID+6, 64846, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1036.10595703125, -3136.928955078125, 27.33580589294433593, 5.415483474731445312, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Springtender Ashani (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+7, 60583, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 1, -1017.87152099609375, -3058.725830078125, 12.90685176849365234, 1.501029491424560546, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Protector Kaolan (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1 (Auras: 118221 - Sha Mask, 93105 - Invisibility and Stealth Detection)
(@CGUID+8, 66100, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1053.421875, -3031.8212890625, 12.65243434906005859, 5.87439727783203125, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'protectors_intro_trash', 54736), -- Apparition of Terror (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+9, 64368, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -982.19268798828125, -3032.257080078125, 12.65242290496826171, 3.54566812515258789, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'protectors_intro_trash', 54736), -- Apparition of Fear (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+10, 60585, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 1, -1009.9375, -3045.015625, 12.90686798095703125, 3.827046632766723632, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736), -- Elder Regail (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1 (Auras: 118221 - Sha Mask)
(@CGUID+11, 66100, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -982.420166015625, -3066.154541015625, 12.65248298645019531, 2.69788980484008789, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'protectors_intro_trash', 54736), -- Apparition of Terror (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+12, 64368, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 0, -1052.701416015625, -3068.12158203125, 12.65246486663818359, 0.577366411685943603, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'protectors_intro_trash', 54736), -- Apparition of Fear (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@CGUID+13, 60586, 996, 6067, 6515, '5,6,3,4,7', 0, 0, 0, 1, -1025.782958984375, -3044.84375, 12.90687084197998046, 5.698800563812255859, 604800, 0, 0, 100, 0, NULL, NULL, NULL, NULL, NULL, 54736); -- Elder Asani (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1 (Auras: 118221 - Sha Mask)

DELETE FROM `creature_template_addon` WHERE `entry` IN (60621, 60646, 65736, 63420, 60957, 63025, 60999, 60586, 60585, 64368, 66100, 60906, 60886, 60583);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(60621, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '117217'), -- 60621 (Corrupted Waters) - Corrupted Waters
(60646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 60646 (Cleansing Waters)
(65736, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '120216'), -- 65736 (Return to the Terrace) - Pure Light Visual
(63420, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '125630 125666'), -- 63420 (SLG Generic MoP) - Sha Corruption Fountain, Sha Corruption Fountain
(60957, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 60957 (Minion of Fear Controller)
(63025, 0, 0, 0, 3, 0, 1, 0, 0, 3235, 0, 0, 4, '122452'), -- 63025 (Tsulong) - Energy Drain & 50% HP
(60999, 0, 0, 0, 0, 0, 1, 0, 0, 2425, 0, 0, 5, '72242'), -- 60999 (Sha of Fear) - Zero Energy + Zero Regen
(60586, 0, 0, 0, 0, 0, 1, 0, 0, 2635, 0, 0, 3, '118221'), -- 60586 (Elder Asani) - Sha Mask
(60585, 0, 0, 0, 0, 0, 1, 0, 0, 2635, 0, 0, 3, '118221'), -- 60585 (Elder Regail) - Sha Mask
(64368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 64368 (Apparition of Fear)
(66100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 66100 (Apparition of Terror)
(60906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '117989'), -- 60906 (Fissure) - Defiled Ground
(60886, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '117943'), -- 60886 (Coalesced Corruption) - Expelled Corruption
(60583, 0, 0, 0, 0, 0, 1, 0, 0, 2635, 0, 0, 3, '118221 93105'); -- 60583 (Protector Kaolan) - Sha Mask, Invisibility and Stealth Detection

DELETE FROM `creature_template_difficulty` WHERE (`Entry`=60621 AND `DifficultyID`=3);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(60621, 3, 4, 5.5, 1, 58739, 1024, 0); -- Corrupted Waters

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=3 AND `Entry` IN (60621,60646,60886,65736,63420,60906,60957));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(60621, 3, 2, 2, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54736), -- Corrupted Waters
(60646, 3, 3, 3, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54736), -- Cleansing Waters
(60886, 3, 3, 3, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Coalesced Corruption
(65736, 3, 0, 0, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54736), -- Return to the Terrace
(63420, 3, 0, 0, 657, 536871168, 0, 0, 0, 0, 0, 0, 0, 54736), -- SLG Generic MoP
(60906, 3, 3, 3, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54762), -- Fissure
(60957, 3, 3, 3, 1034, 536871168, 0, 0, 0, 0, 0, 0, 0, 54736); -- Minion of Fear Controller

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1034, `StaticFlags1`=536870912, `StaticFlags2`=0, `VerifiedBuild`=54736 WHERE (`Entry`=63025 AND `DifficultyID`=3); -- Tsulong
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1034, `StaticFlags1`=536871168, `StaticFlags2`=0, `VerifiedBuild`=54736 WHERE (`Entry`=60999 AND `DifficultyID`=3); -- Sha of Fear
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `VerifiedBuild`=54736 WHERE (`Entry`=36737 AND `DifficultyID`=3); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1034, `StaticFlags2`=0, `VerifiedBuild`=54736 WHERE (`Entry`=60586 AND `DifficultyID`=3); -- Elder Asani
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1034, `StaticFlags2`=0, `VerifiedBuild`=54736 WHERE (`Entry`=60585 AND `DifficultyID`=3); -- Elder Regail
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1034, `StaticFlags1`=268435456, `VerifiedBuild`=54736 WHERE (`Entry`=64368 AND `DifficultyID`=3); -- Apparition of Fear
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1034, `StaticFlags1`=268435456, `VerifiedBuild`=54736 WHERE (`Entry`=66100 AND `DifficultyID`=3); -- Apparition of Terror
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1034, `StaticFlags2`=0, `VerifiedBuild`=54736 WHERE (`Entry`=60583 AND `DifficultyID`=3); -- Protector Kaolan
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1034, `StaticFlags1`=268435456, `VerifiedBuild`=54736 WHERE (`Entry`=64846 AND `DifficultyID`=3); -- Springtender Ashani

UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=60906; -- Fissure
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=60886; -- Coalesced Corruption
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2099200, `unit_flags3`=524289 WHERE `entry`=60621; -- Corrupted Waters
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2099200, `unit_flags3`=524289 WHERE `entry`=60646; -- Cleansing Waters
UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags2`=67110912, `unit_flags3`=16777217 WHERE `entry`=65736; -- Return to the Terrace
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=60957; -- Minion of Fear Controller
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=0, `unit_flags3`=335544320 WHERE `entry`=63025; -- Tsulong
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=60999; -- Sha of Fear
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=36737; -- Invisible Stalker
UPDATE `creature_template` SET `unit_flags2`=2048, `AIName`='SmartAI' WHERE `entry`=64368; -- Apparition of Fear
UPDATE `creature_template` SET `unit_flags2`=2048, `AIName`='SmartAI' WHERE `entry`=66100; -- Apparition of Terror
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=64846; -- Springtender Ashani
UPDATE `creature_template` SET `ScriptName`='boss_protector_kaolan' WHERE `entry`=60583;
UPDATE `creature_template` SET `ScriptName`='boss_elder_regail' WHERE `entry`=60585;
UPDATE `creature_template` SET `ScriptName`='boss_elder_asani' WHERE `entry`=60586;

UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=4, `VerifiedBuild`=54736 WHERE `DisplayID`=41538;
UPDATE `creature_model_info` SET `BoundingRadius`=11.44631576538085937, `CombatReach`=11, `VerifiedBuild`=54736 WHERE `DisplayID`=42533;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=24.5, `VerifiedBuild`=54736 WHERE `DisplayID`=45065;
UPDATE `creature_model_info` SET `BoundingRadius`=1.468938589096069335, `CombatReach`=4.125, `VerifiedBuild`=54736 WHERE `DisplayID` IN (41504, 41502);
UPDATE `creature_model_info` SET `BoundingRadius`=1.602478504180908203, `CombatReach`=4.5, `VerifiedBuild`=54736 WHERE `DisplayID`=41503;

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 214525, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1021.24652099609375, -3157.25341796875, 30.74737167358398437, 1.571901917457580566, 0, 0, 0.707497596740722656, 0.706715762615203857, 604800, 255, 1, 54736), -- Instance Portal (Raid 4 Difficulties) (Area: Terrace of Endless Spring - Difficulty: 0) CreateObject1
(@OGUID+1, 214854, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.841064453125, -3049.00830078125, 13.82509040832519531, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 0, 54736), -- Jinyu Council Vortex Wall (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@OGUID+2, 214853, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.9254150390625, -3049.0966796875, -6.98916339874267578, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 0, 54736), -- Jinyu Council Vortex (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@OGUID+3, 214851, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.841064453125, -2911.575927734375, 20.35693550109863281, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 1, 54736), -- Lei Shi Vortex Wall (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@OGUID+4, 214852, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.9254150390625, -2911.34765625, -0.45731830596923828, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 1, 54736), -- Lei Shi Vortex (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@OGUID+5, 214849, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.875, -2771.908203125, 39.15059661865234375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 1, 54736), -- Sha of Fear Vortex Wall (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1
(@OGUID+6, 214850, 996, 6067, 6515, '5,6,3,4,7', 0, 0, -1017.9254150390625, -2771.996337890625, 23.17139816284179687, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 604800, 255, 1, 54736); -- Sha of Fear Vortex (Area: Terrace of Endless Spring - Difficulty: 10 Player) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Jinyu Council Vortex Wall
(@OGUID+2, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Jinyu Council Vortex
(@OGUID+3, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Lei Shi Vortex Wall
(@OGUID+4, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Lei Shi Vortex
(@OGUID+5, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Sha of Fear Vortex Wall
(@OGUID+6, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0); -- Sha of Fear Vortex

UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214850; -- Sha of Fear Vortex
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214849; -- Sha of Fear Vortex Wall
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214852; -- Lei Shi Vortex
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214851; -- Lei Shi Vortex Wall
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214853; -- Jinyu Council Vortex
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=214854; -- Jinyu Council Vortex Wall
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry` IN (214525, 214522); -- Instance Portal (Raid 4 Difficulties)

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=3331 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(3331, 0, 0, 54736);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=389 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(389, 0, 3331, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 14, 14, 0, 0, 0, 0, 0, 0, 54736); -- Spell: 125666 (Sha Corruption Fountain)

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (130023, 125713);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 125713, 0, 0, 51, 0, 5, 63420, 0, '', 0, 0, 0, '', 'Spell \'Corruption Channel\' can only hit \'SLG Generic MoP\''),
(13, 1, 130023, 0, 0, 51, 0, 5, 63420, 0, '', 0, 0, 0, '', 'Spell \'Corruption Channel\' can only hit \'SLG Generic MoP\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (117052, 127731);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 117052, 0, 0, 51, 0, 5, 60583, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Protector Kaolan\''),
(13, 1, 117052, 0, 1, 51, 0, 5, 60585, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Regail\''),
(13, 1, 117052, 0, 2, 51, 0, 5, 60586, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Asani\''),
(13, 2, 117052, 0, 0, 51, 0, 5, 60583, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Protector Kaolan\''),
(13, 2, 117052, 0, 1, 51, 0, 5, 60585, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Regail\''),
(13, 2, 117052, 0, 2, 51, 0, 5, 60586, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Asani\''),
(13, 1, 127731, 0, 0, 51, 0, 5, 60583, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Protector Kaolan\''),
(13, 1, 127731, 0, 1, 51, 0, 5, 60585, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Regail\''),
(13, 1, 127731, 0, 2, 51, 0, 5, 60586, 0, '', 0, 0, 0, '', 'Spell \'Sha Corruption\' can only hit \'Elder Asani\'');

-- Spell target position
DELETE FROM `spell_target_position` WHERE (`ID`=117227 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(117227, 0, 996, -1017.82000732421875, -3049.2099609375, 12.82429981231689453, 54736); -- Spell: 117227 (Corrupted Waters) Efffect: 28 (SPELL_EFFECT_SUMMON)

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`=117052;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(117052, 'spell_protectors_of_the_endless_sha_corruption');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (118040, 118053, 118054, 118055, 118064);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(118040, 'spell_protectors_of_the_endless_lightning_storm_damage'),
(118053, 'spell_protectors_of_the_endless_lightning_storm_damage'),
(118054, 'spell_protectors_of_the_endless_lightning_storm_damage'),
(118055, 'spell_protectors_of_the_endless_lightning_storm_damage'),
(118064, 'spell_protectors_of_the_endless_lightning_storm_damage');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (118003, 118004, 118005, 118007);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(118003, 'spell_protectors_of_the_endless_lightning_storm'),
(118004, 'spell_protectors_of_the_endless_lightning_storm'),
(118005, 'spell_protectors_of_the_endless_lightning_storm'),
(118007, 'spell_protectors_of_the_endless_lightning_storm');

DELETE FROM `spell_script_names` WHERE `spell_id` = 118077;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(118077, 'spell_protectors_of_the_endless_lightning_storm_cast');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 60583;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(60583, 0, 0, 'The terrace was not meant for your kind!', 14, 0, 100, 0, 0, 28369, 61520, 0, 'Protector Kaolan to SLG Generic MoP'),
(60583, 1, 0, 'My strength grows!', 14, 0, 100, 0, 0, 28371, 61521, 0, 'Protector Kaolan to Ancestro Regail'),
(60583, 2, 0, '|TInterface\\Icons\\ability_shaman_fortifyingwaters.blp:20|t%s is about to be healed by |cFFF00000|Hspell:117283|h[Cleansing Waters]|h|r! Move him!', 42, 0, 100, 0, 0, 0, 62340, 0, 'Protector Kaolan to Player'),
(60583, 3, 0, '|TInterface\\Icons\\ability_shaman_fortifyingwaters.blp:20|t%s is being healed by |cFFF00000|Hspell:117283|h[Cleansing Waters]|h|r! Dispel him!', 41, 0, 100, 0, 0, 0, 62341, 0, 'Protector Kaolan to Aguas purificadoras'),
(60583, 4, 0, 'None can match my strength!', 14, 0, 100, 0, 0, 28373, 61523, 0, 'Protector Kaolan to Ancestro Asani'),
(60583, 5, 0, 'I will not be controlled!', 14, 0, 100, 0, 0, 28372, 61522, 0, 'Protector Kaolan');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (64368, 66100) AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6436800, 6610000) AND `source_type`= 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(64368, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (64368 * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apparition of Fear - On Just Created - Self: Start timed action list'),
(6436800, 9, 0, 0, 0, 0, 100, 0, 1000, 5000, 0, 0, 0, '', 85, 125706, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apparition of Fear- On Just Created - Self: Cast Spell 125706'),
(66100, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (66100 * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apparition of Terror - On Just Created - Self: Start timed action list'),
(6610000, 9, 0, 0, 0, 0, 100, 0, 1000, 5000, 0, 0, 0, '', 85, 130022, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apparition of Terror- On Just Created - Self: Cast Spell 130022');
