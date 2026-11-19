SET @OGUID := 5000001;
SET @CGUID := 5000007;

-- NOTE: This NPC seems to be bugged on retail, just teleports itself every 24 seconds, so this spawn is static until get more info about that behaviour
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 82417, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4052.865478515625, -2212.833251953125, 48.62794113159179687, 4.706927299499511718, 120, 10, 0, 4000, 0, 0, 0, 0, 50791); -- Iron Horde War Machine (Area: The Dark Portal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 238954, 1265, 7025, 7037, '0', 0, 0, 4167.5166015625, -2309.351318359375, 63.47442626953125, 3.150515317916870117, 0.001313209533691406, -0.30070209503173828, -0.95370769500732421, 0.004263732582330703, 120, 255, 1, 50791), -- Doodad_6IH_IronHorde_darkportaldoor001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 238955, 1265, 7025, 7037, '0', 0, 0, 3964.467529296875, -2311.125, 63.47442626953125, 3.150515317916870117, 0.001313209533691406, -0.30070209503173828, -0.95370769500732421, 0.004263732582330703, 120, 255, 1, 50791), -- Doodad_6IH_IronHorde_darkportaldoor002 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+2, 237261, 1265, 7025, 7037, '0', 3251, 0, 4066.85595703125, -2402.782958984375, 77.76815032958984375, 1.507232904434204101, 0, 0, 0.6842803955078125, 0.729219019412994384, 120, 255, 1, 50791), -- Gul'dan Light Shaft (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+3, 236692, 1265, 7025, 7037, '0', 3251, 0, 4066.552490234375, -2371.4560546875, 94.5568695068359375, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Center001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+4, 231763, 1265, 7025, 7037, '0', 0, 856, 4122.72998046875, -2409.388916015625, 90.68038177490234375, 2.657860279083251953, 0.074547767639160156, -0.08730888366699218, 0.962948799133300781, 0.244027435779571533, 120, 255, 1, 50791), -- Iron Horde Capsule (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+5, 231763, 1265, 7025, 7037, '0', 0, 856, 4104.328125, -2264.84716796875, 66.13668060302734375, 4.142614364624023437, -0.15509796142578125, 0.014460563659667968, -0.87203598022460937, 0.463992208242416381, 120, 255, 1, 50791), -- Iron Horde Capsule (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+6, 231763, 1265, 7025, 7037, '0', 0, 856, 4033.478271484375, -2303.48095703125, 66.63425445556640625, 5.33914804458618164, 0.04236602783203125, -0.1409759521484375, -0.4399566650390625, 0.885871946811676025, 120, 255, 1, 50791), -- Iron Horde Capsule (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+7, 231763, 1265, 7025, 7037, '0', 0, 856, 4111.8671875, -2306.895751953125, 59.53200912475585937, 1.142123818397521972, 0.033294677734375, -0.18153190612792968, 0.520952224731445312, 0.833394527435302734, 120, 255, 1, 50791), -- Iron Horde Capsule (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+8, 231763, 1265, 7025, 7037, '0', 0, 856, 4016.28125, -2267.7900390625, 60.27538299560546875, 4.00154876708984375, -0.12168693542480468, -0.00770759582519531, -0.90427112579345703, 0.409177929162979125, 120, 255, 1, 50791), -- Iron Horde Capsule (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+9, 232500, 1265, 7025, 7037, '0', 0, 856, 4042.505126953125, -2389.45654296875, 94.60352325439453125, 5.392996788024902343, 0, 0, -0.4305429458618164, 0.902570068836212158, 120, 255, 1, 50791), -- Destroyed Iron Horde War Machine Type 01 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+10, 231766, 1265, 7025, 7037, '0', 0, 856, 4122.81005859375, -2275.161376953125, 59.2469024658203125, 4.119008064270019531, 0, 0, -0.88294029235839843, 0.469485282897949218, 120, 255, 1, 50791), -- Destroyed Iron Horde War Machine (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+11, 234139, 1265, 7025, 7037, '0', 0, 856, 4020.178955078125, -2373.052001953125, 79.0666351318359375, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Gul'dan Door Light (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+12, 234139, 1265, 7025, 7037, '0', 0, 856, 4020.322998046875, -2381.145751953125, 79.08153533935546875, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Gul'dan Door Light (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+13, 234139, 1265, 7025, 7037, '0', 0, 856, 4112.9296875, -2372.609375, 79.0704193115234375, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Gul'dan Door Light (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+14, 234139, 1265, 7025, 7037, '0', 0, 856, 4113.02001953125, -2380.56591796875, 79.0675201416015625, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Gul'dan Door Light (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+15, 234140, 1265, 7025, 7037, '0', 0, 856, 4024.376708984375, -2374.70654296875, 87.19438934326171875, 3.035642385482788085, 0, 0, 0.998597145080566406, 0.052950382232666015, 120, 255, 1, 50791), -- Gul'dan Door Light B (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+16, 234140, 1265, 7025, 7037, '0', 0, 856, 4108.828125, -2379.78466796875, 87.21779632568359375, 0.120453201234340667, 0, 0, 0.060190200805664062, 0.998186886310577392, 120, 255, 1, 50791), -- Gul'dan Door Light B (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+17, 234140, 1265, 7025, 7037, '0', 0, 856, 4108.7724609375, -2373.411376953125, 87.15036773681640625, 0.120453201234340667, 0, 0, 0.060190200805664062, 0.998186886310577392, 120, 255, 1, 50791), -- Gul'dan Door Light B (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+18, 234140, 1265, 7025, 7037, '0', 0, 856, 4024.42529296875, -2380.1025390625, 87.1539306640625, 3.035642385482788085, 0, 0, 0.998597145080566406, 0.052950382232666015, 120, 255, 1, 50791), -- Gul'dan Door Light B (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+19, 232502, 1265, 7025, 7037, '0', 0, 856, 4084.189208984375, -2359.869873046875, 94.60382843017578125, 1.308194994926452636, 0, 0, 0.608443260192871093, 0.793597400188446044, 120, 255, 1, 50791), -- Debris 001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+20, 232502, 1265, 7025, 7037, '0', 0, 856, 4037.6875, -2414.78466796875, 94.6002349853515625, 1.308194994926452636, 0, 0, 0.608443260192871093, 0.793597400188446044, 120, 255, 1, 50791), -- Debris 001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+21, 232502, 1265, 7025, 7037, '0', 0, 856, 4098.390625, -2414.265625, 94.60009765625, 1.308194994926452636, 0, 0, 0.608443260192871093, 0.793597400188446044, 120, 255, 1, 50791), -- Debris 001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+22, 232503, 1265, 7025, 7037, '0', 0, 856, 4037.326416015625, -2434.267333984375, 94.60196685791015625, 6.012852668762207031, 0, 0, -0.13475513458251953, 0.990878939628601074, 120, 255, 1, 50791), -- Debris 002 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+23, 232504, 1265, 7025, 7037, '0', 0, 856, 4097.7021484375, -2433.458251953125, 94.60204315185546875, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Debris 003 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+24, 232504, 1265, 7025, 7037, '0', 0, 856, 4040.3525390625, -2376.5556640625, 94.60257720947265625, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Debris 003 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+25, 230833, 1265, 7025, 7037, '0', 3248, 0, 4099.2421875, -2402.998291015625, 69.20999908447265625, 3.149405241012573242, 0, 0, -0.99999237060546875, 0.00390625, 120, 255, 1, 50791), -- Gul'dan Beam (TEMP) (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+26, 230833, 1265, 7025, 7037, '0', 3249, 0, 4067.11376953125, -2435.663330078125, 69.20595550537109375, 1.582800269126892089, 0, 0, 0.711338043212890625, 0.702850043773651123, 120, 255, 1, 50791), -- Gul'dan Beam (TEMP) (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+27, 230833, 1265, 7025, 7037, '0', 3250, 0, 4034.072998046875, -2403.317626953125, 69.24383544921875, 0, 0, 0, 0, 1, 120, 255, 1, 50791); -- Gul'dan Beam (TEMP) (Area: The Dark Portal - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 0), -- Doodad_6IH_IronHorde_darkportaldoor001
(@OGUID+1, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 0), -- Doodad_6IH_IronHorde_darkportaldoor002
(@OGUID+2, 0, 0, 0, 1, 0, 3890), -- Gul'dan Light Shaft
(@OGUID+3, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 0), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Center001
(@OGUID+4, 0, 0, 0, 1, 0, 3761), -- Iron Horde Capsule
(@OGUID+5, 0, 0, 0, 1, 0, 3761), -- Iron Horde Capsule
(@OGUID+6, 0, 0, 0, 1, 0, 3761), -- Iron Horde Capsule
(@OGUID+7, 0, 0, 0, 1, 0, 3761), -- Iron Horde Capsule
(@OGUID+8, 0, 0, 0, 1, 0, 3761); -- Iron Horde Capsule

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 82417 /*82417 (Iron Horde War Machine)*/;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(82417, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 82417 (Iron Horde War Machine)

-- GameObject Template Addon
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=238955; -- Doodad_6IH_IronHorde_darkportaldoor002
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=238954; -- Doodad_6IH_IronHorde_darkportaldoor001
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3890 WHERE `entry`=237261; -- Gul'dan Light Shaft
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=236692; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Center001
UPDATE `gameobject_template_addon` SET `flags`=8192, `AIAnimKitID`=3761 WHERE `entry`=231763; -- Iron Horde Capsule
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232500; -- Destroyed Iron Horde War Machine Type 01
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=231766; -- Destroyed Iron Horde War Machine
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=234139; -- Gul'dan Door Light
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=234140; -- Gul'dan Door Light B
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232502; -- Debris 001
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232503; -- Debris 002
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232504; -- Debris 003

-- Creature Template
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=82417; -- Iron Horde War Machine

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 7037 AND `PhaseId` = 3568;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7037, 3568, 'See Battle at the Dark Portal (Assault on the Dark Portal)');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3568 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3568, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3563 if Quest 34393 is not complete | rewarded');
