-- Isle of Dorn - Rambleshire - Creatures and Pathing
SET @CGUID := 50500000;

UPDATE `creature_equip_template` SET `VerifiedBuild`=64978 WHERE (`ID`=1 AND `CreatureID` IN (212435,212436));

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 212435, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3489.303955078125, -3091.100830078125, 158.0813446044921875, 4.378600120544433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Magus (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3491.8515625, -3127.97265625, 155.760345458984375, 3.900045156478881835, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 225735, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3420.89111328125, -3127.5546875, 199.232208251953125, 2.776632547378540039, 5, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Cart (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+3, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3431.035400390625, -3158.5615234375, 156.6797332763671875, 3.553972482681274414, 123, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+4, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3492.7509765625, -3075.173583984375, 155.6990509033203125, 4.213291645050048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+5, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3439.9609375, -3094.43896484375, 154.5025634765625, 0.721670985221862792, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+6, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3376.025146484375, -3133.447265625, 164.070831298828125, 0.735558211803436279, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+7, 212435, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3427.13623046875, -3159.475830078125, 156.53399658203125, 2.547721624374389648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Magus (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+8, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3543.962646484375, -3069.0732421875, 148.407928466796875, 3.486251354217529296, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 221128, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3601.592041015625, -3097.80029296875, 158.18560791015625, 3.252268791198730468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Clawbreaker K'zithix (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3516.3525390625, -3106.083251953125, 153.342987060546875, 3.871130704879760742, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3415.123291015625, -3155.1962890625, 154.99560546875, 3.787674427032470703, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3491.41064453125, -3064.583251953125, 153.17425537109375, 5.788687705993652343, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+13, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3440.765625, -3148.604248046875, 156.290069580078125, 3.851621627807617187, 126, 10, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3450.01904296875, -3096.163330078125, 156.3077850341796875, 3.303915977478027343, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+15, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3444.697998046875, -3176.163330078125, 168.9062957763671875, 2.345483064651489257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+16, 212435, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3489.368896484375, -3150.32470703125, 167.650482177734375, 3.51761174201965332, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Magus (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+17, 212435, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3509.049560546875, -3097.350830078125, 155.435089111328125, 3.368248462677001953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Magus (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+18, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3503.040771484375, -3128.1806640625, 154.9883270263671875, 2.551218032836914062, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+19, 212425, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3500, -3102.869873046875, 161.027587890625, 2.748903512954711914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Scout (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+20, 212425, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3500, -3066.869873046875, 160.99560546875, 5.890496253967285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Scout (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+21, 212436, 2552, 14717, 14784, '0', '0', 0, 0, 1, 3450.93408203125, -3114.583251953125, 156.419830322265625, 4.271411895751953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Shadow Vanguard Soldier (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+22, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3549.013916015625, -3085.911376953125, 148.7562408447265625, 3.745995521545410156, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+23, 214594, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3408.069580078125, -3154.520751953125, 154.76727294921875, 3.868278026580810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+24, 229378, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3574.6884765625, -3094.9150390625, 155.515289306640625, 0, 120, 0, 0, 0, NULL, 768, 1, 8192, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+25, 229378, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3603.302001953125, -3084.54345703125, 154.89208984375, 3.90681624412536621, 120, 0, 0, 0, NULL, 768, 1, 8192, 64978), -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1
(@CGUID+26, 229378, 2552, 14717, 14784, '0', '0', 0, 0, 0, 3595.48779296875, -3090.7900390625, 155.8663787841796875, 4.80206298828125, 120, 0, 0, 0, NULL, 768, 1, 8192, 64978); -- Cascade Guardian (Area: Rambleshire - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Shadow Vanguard Soldier
(@CGUID+7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Shadow Vanguard Soldier
(@CGUID+13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Shadow Vanguard Soldier
(@CGUID+19, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Shadow Vanguard Scout
(@CGUID+20, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Shadow Vanguard Scout

DELETE FROM `creature_template_addon` WHERE `entry` IN (212435 /*212435 (Shadow Vanguard Magus)*/, 212436 /*212436 (Shadow Vanguard Soldier)*/, 212425 /*212425 (Shadow Vanguard Scout)*/, 229378 /*229378 (Cascade Guardian)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(212435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 212435 (Shadow Vanguard Magus)
(212436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 212436 (Shadow Vanguard Soldier)
(212425, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212425 (Shadow Vanguard Scout)
(229378, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''); -- 229378 (Cascade Guardian)

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2860, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=221128 AND `DifficultyID`=0); -- 221128 (Clawbreaker K'zithix) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=229378 AND `DifficultyID`=0); -- 229378 (Cascade Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000000, `VerifiedBuild`=64978 WHERE (`Entry`=212425 AND `DifficultyID`=0); -- 212425 (Shadow Vanguard Scout) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=214594 AND `DifficultyID`=0); -- 214594 (Cascade Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=212436 AND `DifficultyID`=0); -- 212436 (Shadow Vanguard Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=212435 AND `DifficultyID`=0); -- 212435 (Shadow Vanguard Magus) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=64978 WHERE (`Entry`=225735 AND `DifficultyID`=0); -- 225735 (Cart)

UPDATE `creature_model_info` SET `VerifiedBuild`=64978 WHERE `DisplayID` IN (91872, 112730, 112727, 114768, 91864, 91862, 91870, 114533, 91866, 112729, 91868, 114532, 114536);

UPDATE `creature_template` SET `VignetteID`=6115,`faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=221128; -- Clawbreaker K'zithix
UPDATE `creature_template` SET `faction`=2643, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x80000000 WHERE `entry`=229378; -- Cascade Guardian
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `VehicleId`=8274 WHERE `entry`=225735; -- Cart
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212425; -- Shadow Vanguard Scout
UPDATE `creature_template` SET `faction`=2643, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x8000000 WHERE `entry`=214594; -- Cascade Guardian
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=212436; -- Shadow Vanguard Soldier
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=212435; -- Shadow Vanguard Magus

-- PATHING

-- Shadow Vanguard Scout
SET @MOVERGUID := @CGUID+19;
SET @ENTRY := 212425;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.7364, 'Shadow Vanguard Scout - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3487.272, -3097.598, 162.02759, NULL, 0),
(@PATH, 1, 3482, -3084.8699, 162.02759, NULL, 0),
(@PATH, 2, 3487.272, -3072.1418, 162.02759, NULL, 0),
(@PATH, 3, 3500, -3066.8699, 162.02759, NULL, 0),
(@PATH, 4, 3512.728, -3072.1418, 162.02759, NULL, 0),
(@PATH, 5, 3518, -3084.8699, 162.02759, NULL, 0),
(@PATH, 6, 3512.728, -3097.598, 162.02759, NULL, 0),
(@PATH, 7, 3500, -3102.8699, 162.02759, NULL, 0);

UPDATE `creature` SET `position_x`=3487.272, `position_y`=-3097.598, `position_z`=162.02759, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Shadow Vanguard Scout
SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 212425;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.7364, 'Shadow Vanguard Scout - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3487.272, -3097.598, 162.02759, NULL, 0),
(@PATH, 1, 3482, -3084.8699, 162.02759, NULL, 0),
(@PATH, 2, 3487.272, -3072.1418, 162.02759, NULL, 0),
(@PATH, 3, 3500, -3066.8699, 162.02759, NULL, 0),
(@PATH, 4, 3512.728, -3072.1418, 162.02759, NULL, 0),
(@PATH, 5, 3518, -3084.8699, 162.02759, NULL, 0),
(@PATH, 6, 3512.728, -3097.598, 162.02759, NULL, 0),
(@PATH, 7, 3500, -3102.8699, 162.02759, NULL, 0);

UPDATE `creature` SET `position_x`=3487.272, `position_y`=-3097.598, `position_z`=162.02759, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Clawbreaker K'zithix
SET @MOVERGUID := @CGUID+9;
SET @ENTRY := 221128;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Clawbreaker Kzithix - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3610.5918, -3097.871, 159.44656, NULL, 0),
(@PATH, 1, 3595.6128, -3096.9133, 157.74051, NULL, 0),
(@PATH, 2, 3583.1511, -3099.4932, 156.46712, NULL, 0),
(@PATH, 3, 3568.3767, -3103.9827, 157.52808, NULL, 5270),
(@PATH, 4, 3583.1511, -3099.4932, 156.46712, NULL, 0),
(@PATH, 5, 3595.6128, -3096.9133, 157.74051, NULL, 0),
(@PATH, 6, 3610.744, -3097.8665, 159.38052, NULL, 0),
(@PATH, 7, 3610.584, -3097.8516, 159.44656, NULL, 0),
(@PATH, 8, 3610.744, -3097.8665, 159.38052, NULL, 0),
(@PATH, 9, 3613.7354, -3097.6504, 160.42303, NULL, 0),
(@PATH, 10, 3615.7295, -3097.5059, 160.9834, NULL, 0),
(@PATH, 11, 3617.7236, -3097.3613, 161.60568, NULL, 0),
(@PATH, 12, 3619.7178, -3097.2168, 161.85747, NULL, 0),
(@PATH, 13, 3620.7148, -3097.1445, 162.03703, NULL, 0),
(@PATH, 14, 3621.8142, -3097.073, 162.24847, NULL, 4399);

UPDATE `creature` SET `position_x`=3610.5918, `position_y`=-3097.871, `position_z`=159.44656, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Shadow Vanguard Soldier
SET @MOVERGUID := @CGUID+21;
SET @ENTRY := 212436;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadow Vanguard Soldier - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3453.5676, -3107.996, 156.74683, 1.5934888, 1120),
(@PATH, 1, 3451.731, -3100.4028, 156.64001, NULL, 0),
(@PATH, 2, 3452.659, -3103.3057, 156.73602, NULL, 0),
(@PATH, 3, 3453.554, -3108.7605, 156.73296, NULL, 0),
(@PATH, 4, 3452.967, -3115.8108, 156.2481, NULL, 0),
(@PATH, 5, 3450.197, -3121.5676, 155.67456, NULL, 0),
(@PATH, 6, 3446.6406, -3126.7883, 155.89185, NULL, 0),
(@PATH, 7, 3442.4602, -3130.4636, 155.91539, NULL, 0),
(@PATH, 8, 3439.8828, -3131.8352, 155.81352, NULL, 73),
(@PATH, 9, 3444.0676, -3129.1233, 155.92244, NULL, 0),
(@PATH, 10, 3447.9714, -3125.257, 155.80942, NULL, 0),
(@PATH, 11, 3450.9192, -3119.9705, 155.71944, NULL, 0),
(@PATH, 12, 3453.669, -3112.455, 156.62163, NULL, 0),
(@PATH, 13, 3453.5322, -3106.434, 156.7532, NULL, 0);

UPDATE `creature` SET `position_x`=3453.5676, `position_y`=-3107.996, `position_z`=156.74683, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Shadow Vanguard Magus
SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 212435;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadow Vanguard Magus - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3435.3801, -3156.894, 156.68648, NULL, 0),
(@PATH, 1, 3440.1997, -3153.2935, 156.39134, NULL, 0),
(@PATH, 2, 3445.1362, -3146.6528, 156.19888, NULL, 0),
(@PATH, 3, 3446.2744, -3141.8142, 156.32713, NULL, 0),
(@PATH, 4, 3444.8994, -3137.264, 156.33942, NULL, 0),
(@PATH, 5, 3445.7024, -3142.8665, 156.29335, NULL, 0),
(@PATH, 6, 3444.1362, -3148.0625, 156.17697, NULL, 0),
(@PATH, 7, 3441.1746, -3152.4602, 156.33583, NULL, 0),
(@PATH, 8, 3436.7092, -3156.0798, 156.63156, NULL, 0),
(@PATH, 9, 3429.4019, -3159.2761, 156.6936, NULL, 0),
(@PATH, 10, 3420.2317, -3160.25, 155.76776, NULL, 0),
(@PATH, 11, 3428.2456, -3159.3508, 156.59428, NULL, 0);

UPDATE `creature` SET `position_x`=3435.3801, `position_y`=-3156.894, `position_z`=156.68648, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Shadow Vanguard Soldier
SET @MOVERGUID := @CGUID+3;
SET @ENTRY := 212436;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadow Vanguard Soldier - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3435.3801, -3156.894, 156.68648, NULL, 0),
(@PATH, 1, 3440.1997, -3153.2935, 156.39134, NULL, 0),
(@PATH, 2, 3445.1362, -3146.6528, 156.19888, NULL, 0),
(@PATH, 3, 3446.2744, -3141.8142, 156.32713, NULL, 0),
(@PATH, 4, 3444.8994, -3137.264, 156.33942, NULL, 0),
(@PATH, 5, 3445.7024, -3142.8665, 156.29335, NULL, 0),
(@PATH, 6, 3444.1362, -3148.0625, 156.17697, NULL, 0),
(@PATH, 7, 3441.1746, -3152.4602, 156.33583, NULL, 0),
(@PATH, 8, 3436.7092, -3156.0798, 156.63156, NULL, 0),
(@PATH, 9, 3429.4019, -3159.2761, 156.6936, NULL, 0),
(@PATH, 10, 3420.2317, -3160.25, 155.76776, NULL, 0),
(@PATH, 11, 3428.2456, -3159.3508, 156.59428, NULL, 0);

UPDATE `creature` SET `position_x`=3435.3801, `position_y`=-3156.894, `position_z`=156.68648, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Shadow Vanguard Soldier
SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 212436;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadow Vanguard Soldier - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3435.3801, -3156.894, 156.68648, NULL, 0),
(@PATH, 1, 3440.1997, -3153.2935, 156.39134, NULL, 0),
(@PATH, 2, 3445.1362, -3146.6528, 156.19888, NULL, 0),
(@PATH, 3, 3446.2744, -3141.8142, 156.32713, NULL, 0),
(@PATH, 4, 3444.8994, -3137.264, 156.33942, NULL, 0),
(@PATH, 5, 3445.7024, -3142.8665, 156.29335, NULL, 0),
(@PATH, 6, 3444.1362, -3148.0625, 156.17697, NULL, 0),
(@PATH, 7, 3441.1746, -3152.4602, 156.33583, NULL, 0),
(@PATH, 8, 3436.7092, -3156.0798, 156.63156, NULL, 0),
(@PATH, 9, 3429.4019, -3159.2761, 156.6936, NULL, 0),
(@PATH, 10, 3420.2317, -3160.25, 155.76776, NULL, 0),
(@PATH, 11, 3428.2456, -3159.3508, 156.59428, NULL, 0);

UPDATE `creature` SET `position_x`=3435.3801, `position_y`=-3156.894, `position_z`=156.68648, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Cart
SET @MOVERGUID := @CGUID+2;
SET @ENTRY := 225735;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Cart - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3504.4558, -3159.4844, 198.46745, NULL, 0),
(@PATH, 1, 3504.4558, -3159.4844, 198.84982, NULL, 0),
(@PATH, 2, 3504.4558, -3159.4844, 199.2322, NULL, 0),
(@PATH, 3, 3500.6753, -3158.117, 199.2322, NULL, 0),
(@PATH, 4, 3496.0146, -3156.4314, 199.2322, NULL, 0),
(@PATH, 5, 3493.4487, -3155.5034, 199.23221, NULL, 0),
(@PATH, 6, 3493.4487, -3155.5034, 199.23221, NULL, 0),
(@PATH, 7, 3484.5703, -3151.9739, 199.2322, NULL, 0),
(@PATH, 8, 3448.5105, -3138.1077, 199.23218, NULL, 0),
(@PATH, 9, 3410.179, -3123.462, 199.2322, NULL, 0),
(@PATH, 10, 3369.8499, -3107.934, 199.2322, NULL, 0),
(@PATH, 11, 3360.9993, -3104.4236, 199.2322, NULL, 0);

UPDATE `creature` SET `position_x`=3504.4558, `position_y`=-3159.4844, `position_z`=198.46745, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
