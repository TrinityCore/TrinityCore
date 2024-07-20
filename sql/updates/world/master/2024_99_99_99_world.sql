-- Lords of Dread
SET @CGUID := 20000000; -- Insert highest based on your db
SET @OGUID := 15000000; -- Insert highest based on your db
SET @ATID := 65;
SET @ATCP := 53;
SET @ATSPAWNID := 67;

-- Game Objects
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (375410 ,375198 ,375199 ,375200 ,375201 ,375409);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(375410, 0, 48, 0, 0), -- Massive Gate
(375198, 0, 48, 0, 0), -- Shining Barrier
(375199, 0, 48, 0, 0), -- Shining Barrier
(375200, 0, 48, 0, 0), -- Shining Barrier
(375201, 0, 48, 0, 0), -- Shining Barrier
(375409, 0, 48, 0, 0); -- Massive Door

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 375410, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5629.8427734375, -4124.0986328125, 154.3605194091796875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 604800, 255, 1, 50747), -- Massive Gate Door Before Lords of Dread
(@OGUID+1, 375198, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5673.40185546875, -4084.786376953125, 141.7731475830078125, 2.068685531616210937, 0, 0, 0.859526634216308593, 0.51109093427658081, 604800, 255, 0, 50747), -- Shining Barrier Before Lords Right side
(@OGUID+2, 375199, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5685.90966796875, -4106.12548828125, 141.7732391357421875, 3.155124664306640625, 0, 0, -0.99997711181640625, 0.006765823345631361, 604800, 255, 0, 50747), -- Shining Barrier Before Lords Left Side
(@OGUID+3, 375200, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5771.35498046875, -4056.611083984375, 141.773162841796875, 5.196827411651611328, 0, 0, -0.51686000823974609, 0.856069922447204589, 604800, 255, 1, 50747), -- Shining Barrier After Lords Left side
(@OGUID+4, 375201, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5758.828125, -4035.46923828125, 141.7731475830078125, 0.016992771998047828, 0, 0, 0.008496284484863281, 0.999963879585266113, 604800, 255, 1, 50747), -- Shining Barrier After Lords Right side
(@OGUID+5, 375409, 2481, 13742, 13969, '14,15,16,17', '0', 0, -5814.8056640625, -4017.30859375, 154.3605194091796875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 604800, 255, 1, 50747); -- Massive Door After Lords of Dread

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0), -- Massive Gate
(@OGUID+1, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0), -- Shining Barrier
(@OGUID+2, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0), -- Shining Barrier
(@OGUID+3, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0), -- Shining Barrier
(@OGUID+4, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0), -- Shining Barrier
(@OGUID+5, 0, 0, 0.866025209426879882, 0.500000298023223876, 0, 0); -- Massive Door

-- Creature Templates
UPDATE `creature_template` SET `ScriptName`='boss_lords_of_dread_malganis', `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=1500, `unit_flags`=64 WHERE `entry`=181398; -- Mal'Ganis
UPDATE `creature_template` SET `ScriptName`='boss_lords_of_dread_kintessa', `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=1500, `unit_flags`=64 WHERE `entry`=181399; -- Kin'tessa
UPDATE `creature_template` SET `faction`=190, `speed_run`=1.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1, `VehicleId`=7660 WHERE `entry`=183906; -- Simple Task
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=832, `unit_flags2`=67108864, `unit_flags3`=16777217 WHERE `entry` IN (183907, 183910, 183909, 183908); -- Strange Device
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1, `VehicleId`=7614 WHERE `entry`=182039; -- Swarm of Shadows
UPDATE `creature_template` SET `ScriptName`='npc_slumber_cloud', `faction`=16, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=524289 WHERE `entry`=181925; -- Slumber Cloud
UPDATE `creature_template` SET `ScriptName`='npc_inchoate_shadow', `faction`=16, `speed_walk`=0.003999999724328517, `speed_run`=0.001428571413271129, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304, `unit_flags3`=524288 WHERE `entry`=183138; -- Inchoate Shadow
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=186128; -- Overthrown Protector
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=186353; -- Dominated Shaper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33040, `unit_flags2`=33556480 WHERE `entry`=185155; -- Overthrown Protector
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1 WHERE `entry`=185499; -- Domination Beam
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=184533; -- Overthrown Protector
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=184535; -- Overthrown Artisan
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33040, `unit_flags2`=35653632 WHERE `entry`=185154; -- Overthrown Protector
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=184627; -- Dominated Shaper

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (181398, 181399, 183906, 183907, 183910, 183909, 183908, 183138, 186128, 186353, 185155, 185499, 184533, 184535, 185154, 184627);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(181398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '360164 361117'), -- 181398 (Mal'Ganis) - Decay, Mimicking Disguise
(181399, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '360163'), -- 181399 (Kin'tessa) - Darkness
(183906, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 183906 (Simple Task)
(183907, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 183907 (Strange Device) - Ride Vehicle Hardcoded
(183910, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 183910 (Strange Device) - Ride Vehicle Hardcoded
(183909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 183909 (Strange Device) - Ride Vehicle Hardcoded
(183908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 183908 (Strange Device) - Ride Vehicle Hardcoded
(183138, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 183138 (Inchoate Shadow)
(186128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '366437 365176'), -- 186128 (Overthrown Protector) - Enveloped in Dread, Warding Strikes
(186353, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '366474 367432'), -- 186353 (Dominated Shaper) - Bursting Dread, Ritual of Domination
(185155, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '366521 366490'), -- 185155 (Overthrown Protector) - Enveloped in Dread, Infiltration of Dread
(185499, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 185499 (Domination Beam)
(184533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '366437 365176'), -- 184533 (Overthrown Protector) - Enveloped in Dread, Warding Strikes
(184535, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '366474'), -- 184535 (Overthrown Artisan) - Bursting Dread
(185154, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '366521 366490'), -- 185154 (Overthrown Protector) - Enveloped in Dread, Infiltration of Dread
(184627, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '366474 367432'); -- 184627 (Dominated Shaper) - Bursting Dread, Ritual of Domination

-- MYTHIC DIFFICULTY
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=16 AND `Entry` IN (183906, 183907, 183910, 183909, 183908, 182039, 181925, 183138, 186128, 186353, 185426, 181399, 181398, 185155, 185499, 184533, 184535, 185154, 184627, 186105, 186106));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(183906, 16, 3, 3, 2167, 8, 5, 1, 207795, 2097256, 65664, 50747), -- Simple Task
(183907, 16, 3, 3, 2167, 8, 5, 1, 207796, 1612710008, 117506182, 50747), -- Strange Device
(183910, 16, 3, 3, 2167, 8, 5, 1, 207799, 1612710008, 117506182, 50747), -- Strange Device
(183909, 16, 3, 3, 2167, 8, 5, 1, 207798, 1612710008, 117506182, 50747), -- Strange Device
(183908, 16, 3, 3, 2167, 8, 5, 1, 207797, 1612710008, 117506182, 50747), -- Strange Device
(182039, 16, 3, 3, 2167, 8, 5, 1, 205838, 2097256, 65664, 50747), -- Swarm of Shadows
(181925, 16, 3, 3, 2167, 8, 5, 1, 205724, 2097256, 65664, 50747), -- Slumber Cloud
(183138, 16, 1, 1, 2167, 8, 10, 1, 207655, 2097224, 128, 50747), -- Inchoate Shadow
(186128, 16, 2, 2, 2167, 8, 16, 1, 210427, 2097224, 0, 50747), -- Overthrown Protector
(186353, 16, 1, 1, 2167, 8, 10, 1, 210673, 2097224, 0, 50747), -- Dominated Shaper
(185426, 16, 0, 0, 2165, 8, 1, 1, 209592, 1610612752, 117440582, 50747), -- Ancient Console
(181399, 16, 3, 3, 2167, 8, 615.5999755859375, 1, 207709, 2097260, 65664, 50747), -- Kin'tessa
(181398, 16, 3, 3, 2167, 8, 615.5999755859375, 1, 207705, 2097260, 65664, 50747), -- Mal'Ganis
(185155, 16, 2, 2, 2167, 8, 350, 1, 209270, 2097224, 0, 50747), -- Overthrown Protector
(185499, 16, 0, 0, 2167, 8, 5, 1, 209738, 2097256, 65536, 50747), -- Domination Beam
(184533, 16, 2, 2, 2167, 8, 16, 1, 208588, 2097224, 0, 50747), -- Overthrown Protector
(184535, 16, 1, 1, 2167, 8, 10, 1, 208590, 2097224, 0, 50747), -- Overthrown Artisan
(185154, 16, 2, 2, 2167, 8, 350, 1, 209269, 2097224, 0, 50747), -- Overthrown Protector
(184627, 16, 1, 1, 2167, 8, 10, 1, 208682, 2097224, 0, 50747), -- Dominated Shaper
(186105, 16, 2, 2, 2167, 8, 16, 1, 210404, 2097224, 0, 51536), -- Overthrown Protector
(186106, 16, 1, 1, 2167, 8, 10, 1, 210405, 2097224, 0, 51536); -- Overthrown Artisan

-- HEROIC DIFFICULTY
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=15 AND `Entry` IN (183906, 183907, 183910, 183909, 183908, 182039, 181925, 183138, 186128, 186353, 185426, 181399, 181398, 185155, 185499, 184533, 184535, 185154, 184627, 186105, 186106));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
-- Missing Simple task
-- Missing Strange Device
-- Missing Strange Device
-- Missing Strange Device
-- Missing Strange Device
(182039, 15, 3, 3, 2166, 8, 5, 1, 205838, 2097256, 65664, 49570), -- Swarm of Shadows
(181925, 15, 3, 3, 2166, 8, 5, 1, 205724, 2097256, 65664, 49570), -- Slumber Cloud
(183138, 15, 1, 1, 2166, 8, 10, 1, 207654, 2097224, 128, 49570), -- Inchoate Shadow
(186128, 15, 2, 2, 2166, 8, 16, 1, 210427, 2097224, 0, 49570), -- Overthrown Protector
(186353, 15, 1, 1, 2166, 8, 10, 1, 210673, 2097224, 0, 49570), -- Dominated Shaper
(185426, 15, 0, 0, 2165, 8, 1, 1, 209592, 1610612752, 117440582, 49570), -- Ancient Console
(181399, 15, 3, 3, 2166, 8, 440.32501220703125, 1, 207708, 2097260, 65664, 49570), -- Kin'tessa
(181398, 15, 3, 3, 2166, 8, 440.32501220703125, 1, 207704, 2097260, 65664, 49570), -- Mal'Ganis
(185155, 15, 2, 2, 2166, 8, 350, 1, 209270, 2097224, 0, 49570), -- Overthrown Protector
(185499, 15, 0, 0, 2166, 8, 5, 1, 209738, 2097256, 65536, 49570), -- Domination Beam
(184533, 15, 2, 2, 2166, 8, 16, 1, 208588, 2097224, 0, 49570), -- Overthrown Protector
(184535, 15, 1, 1, 2166, 8, 10, 1, 208590, 2097224, 0, 49570), -- Overthrown Artisan
(185154, 15, 2, 2, 2166, 8, 350, 1, 209269, 2097224, 0, 49570), -- Overthrown Protector
(184627, 15, 1, 1, 2166, 8, 10, 1, 208682, 2097224, 0, 49570), -- Dominated Shaper
(186105, 15, 2, 2, 2166, 8, 16, 1, 210404, 2097224, 0, 49570), -- Overthrown Protector
(186106, 15, 1, 1, 2166, 8, 10, 1, 210405, 2097224, 0, 49570); -- Overthrown Artisan

-- NORMAL DIFFICULTY

-- LFR DIFFICULTY
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=17 AND `Entry` IN (182778,185428,185402,184577,184576,184528,184534,184527,183945,183973,182777,182039,181925,183138,185426,181399,181398,76168,43499,185155,185499,185154,185274,184535,185268,184533,184627,185271,184597,186105,185145,186106));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
-- Missing Simple task
-- Missing Strange Device
-- Missing Strange Device
-- Missing Strange Device
-- Missing Strange Device
(182039, 17, 3, 3, 2168, 8, 5, 1, 205838, 2097256, 65664, 51536), -- Swarm of Shadows
(181925, 17, 3, 3, 2168, 8, 5, 1, 205724, 2097256, 65664, 51536), -- Slumber Cloud
(183138, 17, 1, 1, 2168, 8, 3, 1, 207656, 2097224, 128, 51536), -- Inchoate Shadow
-- MISSING OVERTHROWN PROTECTOR 186128
-- MISSING DOMINATED SHAPER 186353
(185426, 17, 0, 0, 2165, 8, 1, 1, 209592, 1610612752, 117440582, 51536), -- Ancient Console
(181399, 17, 3, 3, 2168, 8, 470.25, 1, 207710, 2097260, 65664, 51536), -- Kin'tessa
(181398, 17, 3, 3, 2168, 8, 470.25, 1, 207706, 2097260, 65664, 51536), -- Mal'Ganis
(185155, 17, 2, 2, 2168, 8, 350, 1, 209270, 2097224, 0, 51536), -- Overthrown Protector
(185499, 17, 0, 0, 2168, 8, 5, 1, 209738, 2097256, 65536, 51536), -- Domination Beam
(184533, 17, 2, 2, 2168, 8, 16, 1, 208588, 2097224, 0, 51536), -- Overthrown Protector
(184535, 17, 1, 1, 2168, 8, 10, 1, 208590, 2097224, 0, 51536), -- Overthrown Artisan
(185154, 17, 2, 2, 2168, 8, 350, 1, 209269, 2097224, 0, 51536), -- Overthrown Protector
(184627, 17, 1, 1, 2168, 8, 10, 1, 208682, 2097224, 0, 51536), -- Dominated Shaper
(186105, 17, 2, 2, 2168, 8, 16, 1, 210404, 2097224, 0, 51536), -- Overthrown Protector
(185268, 17, 2, 2, 2168, 8, 22, 1, 209412, 2097224, 0, 51536), -- Ebonsteel Construct
(186106, 17, 1, 1, 2168, 8, 10, 1, 210405, 2097224, 0, 51536); -- Overthrown Artisan

-- Creature Inserts
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+68;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES 
(@CGUID+0, 185843, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5485.43, -3870.3, 128.528, 6.06126, 604800, 0, 0, 100, 0, NULL, 0, NULL, NULL, '', NULL, 50747), 
(@CGUID+1, 185145, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5476.03, -3883.02, 128.332, 5.45491, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+2, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5458.87, -3913.26, 128.332, 2.94368, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+3, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5466.08, -3906.8, 128.53, 2.78132, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+4, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5458.92, -3856.42, 128.069, 3.66729, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+5, 186105, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5451.72, -3918.89, 128.53, 2.5992, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+6, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5459.25, -3903.71, 128.172, 2.73494, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+7, 184589, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5471.49, -3877.83, 128.08, 5.83536, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+8, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5463.09, -3893.99, 128.377, 2.67533, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+9, 184599, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5478.43, -3871.79, 128.154, 0.95793, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+10, 186105, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5444.47, -3900.73, 127.896, 3.16123, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+11, 184613, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 5, -5469.41, -3870.3, 127.894, 1.28061, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+12, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5452.26, -3898.35, 127.898, 3.18261, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+13, 184613, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 8, -5479.19, -3867.66, 128.332, 1.85766, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+14, 186105, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5440.48, -3852.95, 127.897, 3.48518, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+15, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5466.95, -3846.01, 128.53, 4.06858, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+16, 184613, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 9, -5478.68, -3888.51, 128.332, 4.88249, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+17, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5456.72, -3840.37, 128.53, 4.06858, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+18, 186785, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5470.43, -3886.24, 127.896, 4.48232, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+19, 184597, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5473.21, -3880.92, 128.336, 5.06719, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+20, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5456.99, -3849.18, 128.332, 3.82687, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+21, 184601, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 1, -5474.06, -3869.07, 128.527, 1.17224, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+22, 186106, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5449.36, -3854.93, 127.588, 3.82965, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+23, 186105, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5454.28, -3828.8, 128.535, 3.54727, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+24, 184533, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5447.91, -3982.02, 141.166, 1.60368, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+25, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5495.22, -4121.64, 153.641, 0.559785, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+26, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5504.3, -4055.63, 146.646, 3.72048, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+27, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5484.3, -4108.73, 153.929, 2.0097, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+28, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5534.81, -4055.84, 146.646, 5.73064, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+29, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5534.44, -4073.12, 146.646, 0.580147, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+30, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5430.32, -4015.16, 141.375, 3.00635, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+31, 184533, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5588.77, -4140.3, 153.946, 0.338336, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+32, 185843, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5485.43, -3870.3, 128.528, 6.06126, 604800, 0, 0, 100, 0, NULL, 0, NULL, NULL, '', NULL, 50747), 
(@CGUID+33, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5470.87, -4015.67, 141.399, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+34, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5426.19, -4012.26, 141.486, 2.95883, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+35, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5430.13, -4023.52, 141.375, 2.503, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+36, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5519.85, -4046.81, 146.646, 4.75935, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+37, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5467, -4021.13, 141.375, 0.139579, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+38, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5467.44, -4011.75, 141.375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+39, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5417.65, -4177.42, 141.189, 5.22171, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+40, 185154, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5447.95, -4089.86, 153.686, 1.55039, 7200, 10, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+41, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5520.66, -4124.14, 154.225, 2.50367, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+42, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5503.8, -4073.45, 146.646, 2.67379, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+43, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5608.43, -4122.37, 154.523, 1.91979, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+44, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5519.51, -4083.33, 146.646, 1.58137, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+45, 184533, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5586.88, -4151.34, 153.944, 0.475412, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+46, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5499.34, -4131.74, 153.928, 4.45431, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+47, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5400.84, -4177.8, 141.189, 4.22313, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+48, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5401.11, -4206.07, 141.189, 1.98364, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+49, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5502.73, -4189.76, 141.288, 4.18201, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+50, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5524.68, -4189.67, 141.288, 5.26792, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+51, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5621.05, -4143.52, 154.523, 3.37469, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+52, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5417.41, -4205.99, 141.189, 1.00391, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+53, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5393.19, -4191.91, 141.189, 3.2065, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+54, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5492.67, -4208.85, 141.288, 2.90582, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+55, 184627, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5426.24, -4192.21, 141.197, 0.0717818, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+56, 184533, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5445.47, -4213.18, 140.682, 0.481517, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+57, 184533, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5513.47, -4208.3, 141.282, 0.697937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+58, 185499, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5543.65, -4105.56, 174.477, 0.829921, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+59, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5535.86, -4208.39, 141.288, 0.0415895, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+60, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5503.31, -4227.16, 141.288, 2.06371, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+61, 184535, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5525.09, -4227.38, 141.288, 0.972837, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+62, 185155, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5538.2, -4144.94, 153.532, 0.499137, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+63, 185499, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5506.12, -4156.36, 178.278, 4.14981, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+64, 185499, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5612.59, -4105.09, 165.995, 0.800219, 7200, 0, 0, 100, 1, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+65, 185499, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5634.43, -4141.63, 177.465, 1.041, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+66, 181398, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5719.62, -4066.7, 141.336, 4.24142, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+67, 181399, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5724.44, -4074.71, 141.336, 0.872448, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754), 
(@CGUID+68, 185426, 2481, 13742, 13969, '14,15,16,17', 0, 0, 0, -1, 0, 0, -5765.55, -4034.6, 141.901, 4.72113, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 51754);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=360601 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 360601, 0, 0, 31, 0, 3, 181398, 0, 0, 0, 0, '', 'Lords of Dread Encounter - Return Essence to Malganis'); -- Return Essence to Malganis

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=360602 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 360602, 0, 0, 31, 0, 3, 181399, 0, 0, 0, 0, '', 'Lords of Dread Encounter - Return Essence to Kintessa'); -- Return Essence to Kintessa

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=360418 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 360418, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Lords of Dread Encounter - Paranoia hit Players only'); -- Paranoia

-- Areatriggers Create Properties
DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (24063, 23810, 23805, 24134, 24492);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(24063, 0, 28213, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 596994, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_malganis_cloud_of_carrion', 50747), -- Spell: 360012 (Cloud of Carrion) Initial Carrion cast
(23810, 0, 28001, 0, 2, 0, 30349, 0, 0, -1, 0, 435, 30000, 30000, 0, 2, 2, 0, 0, 0, 0, 0, 0, 'at_malganis_cloud_of_carrion_puddle', 50747), -- Spell: 360386 (Cloud of Carrion) -- On Dispel
(23805, 0, 27996, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 1200000, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_kintessa_slumber_cloud', 50747), -- Spell: 360260 (Slumber Cloud)
(24134, 0, 28254, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 1200000, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_kintessa_horrifying_shadows', 50747), -- Spell: 363235 (Horrifying Shadows)
(24492, 0, 28515, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 12000, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_overthrown_protector_carrion_of_cloud', 50747); -- Spell: 366574 (Cloud of Carrion)

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (@ATCP+0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCP+0, 1, @ATID+0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 10, 10, 5, 10, 10, 5, 0, 0, 'at_lords_of_dread_introduction', 0);

-- Areatrigger Template
DELETE FROM `areatrigger_template` WHERE `Id` IN (28213, 28001, 27996, 28254, 28515);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(28213, 0, 0, 50747),
(28001, 0, 0, 50747),
(27996, 0, 0, 50747),
(28254, 0, 0, 50747),
(28515, 0, 0, 50747);

DELETE FROM `areatrigger_template` WHERE `Id` IN (@ATID+0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 0, 0); -- Introduction

DELETE FROM `areatrigger` WHERE `SpawnId` IN(@ATSPAWNID+0);
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATCP+0, 1, 2481, '14,15,16,17', -5641.49, -4117.54, 153.65, 2.62, 1, 0, 0, 'at_lords_of_dread_introduction', 'Sepulcher of the First Ones - Lords of Dread Introduction', 0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (185154, 185155, 181398, 181399);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(185154, 0, 0, 'Your time is up!', 14, 0, 100, 0, 0, 189098, 214724, 0, 'Malganis Copy Aggro'),
(185154, 1, 0, 'You should have submitted.', 14, 0, 100, 0, 0, 189086, 214647, 0, 'Malganis Copy Retreat'),
(185155, 0, 0, 'Survival is not an option.', 14, 0, 100, 0, 0, 189098, 214725, 0, 'Kintessa Copy Aggro'),
(185155, 1, 0, 'Terror shall claim you!', 14, 0, 100, 0, 0, 189093, 214739, 0, 'Kintessa Copy Retreat'),
(181398, 0, 0, 'You cannot escape death!', 14, 0, 100, 1, 0, 189082, 214715, 0, 'Malganis Aggro 01'),
(181398, 0, 1, 'I will cast you into oblivion!', 14, 0, 100, 1, 0, 189081, 214646, 0, 'Malganis Aggro 02'),
(181398, 1, 0, 'A fitting end!', 14, 0, 100, 0, 0, 189088, 214718, 0, 'Malganis Slay 01'),
(181398, 1, 1, 'Worthless.', 14, 0, 100, 0, 0, 189087, 214648, 0, 'Malganis Slay 02'),
(181398, 2, 0, 'The gloom rises!', 14, 0, 100, 0, 0, 189079, 214736, 0, 'Malganis Shadow 01'),
(181398, 2, 1, 'The shadows hunger!', 14, 0, 100, 0, 0, 189077, 214734, 0, 'Malganis Shadow 02'),
(181398, 2, 2, 'Succumb to the dark!', 14, 0, 100, 0, 0, 189078, 214735, 0, 'Malganis Shadow 03'),
(181398, 3, 0, 'Fall to darkness!', 14, 0, 100, 0, 0, 189080, 214733, 0, 'Malganis Swarm of Decay'),
(181398, 4, 0, '|TInterface\\ICONS\\Spell_Nature_NatureTouchDecay.blp:20|t %s begins to dissolve into a |cFFFF0000|Hspell:360300|h[Swarm of Decay]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Malganis Swarm of Decay Announce'),
(181398, 5, 0, 'Well... played...', 14, 0, 100, 0, 0, 189084, 214650, 0, 'Malganis Death 01'),
(181398, 5, 1, 'Not the... ending... I expected...', 14, 0, 100, 0, 0, 189085, 214722, 0, 'Malganis Death 02'),
(181398, 6, 0, '|TInterface\\ICONS\\SPELL_HOLY_HARMUNDEADAURA.BLP:20|t %s gains |cFFFF0000|Hspell:363184|h[Aura of Carrion]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Malganis Aura of Carrion'),
(181398, 7, 0, '%s goes into a berserker rage!', 41, 0, 100, 0, 0, 0, 0, 0, 'Malganis Enrage Announce'), -- Malganis Enrage
(181398, 8, 0, 'Your time is up!', 14, 0, 100, 0, 0, 189098, 214724, 0, 'Malganis Enrage Sound'),
(181399, 0, 0, 'How fun. More playthings.', 14, 0, 100, 1, 0, 189096, 214651, 0, 'Kintessa Aggro 01'),
(181399, 0, 1, 'I have toyed with you long enough.', 14, 0, 100, 0, 0, 189097, 214710, 0, 'Kintessa Aggro 02'),
(181399, 1, 0, 'Dead already?', 14, 0, 100, 0, 0, 189101, 214652, 0, 'Kintessa Slay 01'),
(181399, 1, 1, 'Mortal after all.', 14, 0, 100, 0, 0, 189102, 214653, 0, 'Kintessa Slay 02'),
(181399, 2, 0, 'Let fear take control!', 14, 0, 100, 0, 0, 189092, 214738, 0, 'Kintessa Fearful Trepidation 01'),
(181399, 2, 1, 'Horror grips you!', 14, 0, 100, 0, 0, 189094, 214740, 0, 'Kintessa Fearful Trepidation 02'),
(181399, 3, 0, 'Trust no one.', 14, 0, 100, 0, 0, 189095, 214737, 0, 'Kintessa Infiltration of Dread'),
(181399, 4, 0, '|TInterface\\ICONS\\ABILITY_ROGUE_DIRTYDEEDS.BLP:20|t %s begins to cast |cFFFF0000|Hspell:360417|h[Infiltration of Dread]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Kintessa Infiltration of Dread Announce'),
(181399, 5, 0, 'I want... more... time...', 14, 0, 100, 0, 0, 189099, 214655, 0, 'Kintessa Death 01'),
(181399, 5, 1, 'You... deceived... me...', 14, 0, 100, 0, 0, 189100, 214723, 0, 'Kintessa Death 02'),
(181399, 6, 0, '|TInterface\\ICONS\\SPELL_SHADOW_AURAOFDARKNESS.BLP:20|t %s gains |cFFFF0000|Hspell:363191|h[Aura of Shadows]|h|r!', 41, 0, 100, 0, 0, 189088, 0, 0, 'Kintessa Aura of Shadows Announce'),
(181399, 7, 0, '%s goes into a berserker rage!', 41, 0, 100, 0, 0, 0, 0, 0, 'Kintessa Enrage Announce'),
(181399, 8, 0, 'Survival is not an option.', 14, 0, 100, 0, 0, 189098, 214725, 0, 'Kintessa Enrage Sound');

-- Conversation Template--
DELETE FROM `conversation_template` WHERE `Id` IN (17691, 17690, 17695, 17694, 17696, 17689, 17838);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(17691, 44945, 0, 52106),
(17690, 44943, 0, 52106),
(17695, 44953, 0, 52106),
(17694, 44951, 0, 52106),
(17696, 44955, 0, 52106),
(17689, 44941, 0, 52106),
(17838, 45400, 0, 51536);

-- Conversation Actors
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (17691,17690,17695,17696,17694,17689,17838)) OR (`Idx`=1 AND `ConversationId` IN (17691,17690,17695,17696,17694,17689,17838));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17691, 82804, 0, 1, 181398, 102856, 0, 0, 52106),
(17691, 82805, 0, 0, 181399, 102857, 0, 0, 52106),
(17690, 82804, 0, 1, 181398, 102856, 0, 0, 52106),
(17690, 82805, 0, 0, 181399, 102857, 0, 0, 52106),
(17695, 82805, 0, 1, 181399, 102857, 0, 0, 52106),
(17695, 82804, 0, 0, 181398, 102856, 0, 0, 52106),
(17696, 82805, 0, 1, 181399, 102857, 0, 0, 52106),
(17696, 82804, 0, 0, 181398, 102856, 0, 0, 52106),
(17694, 82805, 0, 1, 181399, 102857, 0, 0, 52106),
(17694, 82804, 0, 0, 181398, 102856, 0, 0, 52106),
(17689, 82804, 0, 1, 181398, 102856, 0, 0, 52106),
(17689, 82805, 0, 0, 181399, 102857, 0, 0, 52106),
(17838, 82804, @CGUID+67, 0, 181399, 0, 0, 0, 51536),
(17838, 82805, @CGUID+66, 1, 181398, 0, 0, 0, 51536);

-- Conversatoin Lines
DELETE FROM `conversation_line_template` WHERE `Id` IN (44946, 44945, 44944, 44943, 44954, 44953, 44956, 44955, 44952, 44951, 44942, 44941, 45401, 45400);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(44946, 1636, 1, 0, 0, 52106),
(44945, 1637, 0, 0, 0, 52106),
(44944, 1636, 1, 0, 0, 52106),
(44943, 1637, 0, 0, 0, 52106),
(44954, 1638, 1, 0, 0, 52106),
(44953, 1635, 0, 0, 0, 52106),
(44956, 1638, 1, 0, 0, 52106),
(44955, 1635, 0, 0, 0, 52106),
(44952, 1638, 1, 0, 0, 52106),
(44951, 1635, 0, 0, 0, 52106),
(44942, 1636, 1, 0, 0, 52106),
(44941, 1637, 0, 0, 0, 52106),
(45401, 0, 1, 0, 0, 51536),
(45400, 0, 0, 0, 0, 51536);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (366518, 366565, 366549, 366573, 366629, 366633, 366559, 361117, 365624, 360166, 360167, 359960, 360006, 360189, 360017, 360015, 361913, 361935, 360300, 360284, 360287, 360288, 360229, 360145, 360146, 360717, 360417, 360418, 360496, 360498, 360516, 360601, 360602, 363232);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(366518, 'spell_lords_of_dread_grand_reveal'),
(366565, 'spell_lords_of_dread_grand_reveal'),
(366549, 'spell_malganis_imitation_leeching_claws'),
(366573, 'spell_malganis_imitation_cloud_of_carrion'),
(366629, 'spell_kintessa_imitation_anguishing_strike'),
(366633, 'spell_kintessa_imitation_fearful_trepidation'),
(366559, 'spell_lords_of_dread_swarming_retreat'),
(361117, 'spell_lords_of_dread_mimicking_disguise'),
(365624, 'spell_lords_of_dread_transformation_visuals'),
(360166, 'spell_lords_of_dread_energy_regeneration'),
(360167, 'spell_lords_of_dread_energy_regeneration'),
(359960, 'spell_malganis_leeching_claws'),
(360006, 'spell_malganis_cloud_of_carrion'),
(360189, 'spell_malganis_cloud_of_carrion_init'),
(360017, 'spell_malganis_cloud_of_carrion_circle'),
(360015, 'spell_malganis_cloud_of_carrion_damage'),
(361913, 'spell_malganis_manifest_shadows'),
(361935, 'spell_inchoate_shadow_ravenous_hunger_periodic'),
(360300, 'spell_malganis_swarm_of_decay'),
(360284, 'spell_kintessa_anguishing_strike'),
(360287, 'spell_kintessa_anguishing_strike_periodic'),
(360288, 'spell_kintessa_anguishing_strike_debuff_damage'),
(360229, 'spell_kintessa_slumber_cloud'),
(360145, 'spell_kintessa_fearful_trepidation'),
(360146, 'spell_kintessa_fearful_trepidation_debuff'),
(360717, 'spell_infiltration_of_dread_cast'),
(360417, 'spell_kintessa_infiltration_of_dread'),
(360418, 'infiltration_of_dread_paranoia'),
(360496, 'spell_lords_of_dread_infiltration'),
(360498, 'spell_lords_of_dread_infiltration'),
(360516, 'spell_lords_of_dread_disappear'),
(360601, 'spell_lords_of_dread_return_essence'),
(360602, 'spell_lords_of_dread_return_essence'),
(363232, 'spell_kintessa_horrifying_shadows_aura_players');